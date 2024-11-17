import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Int32

import json
import sys
# 获取该文件的路径
import os
import sys

current_path = os.path.abspath(__file__)
current_path = os.path.dirname(current_path)
sys.path.append(current_path)
print(current_path)
# workflow root
rm_api_path = '/home/cful/Desktop/zkhl_play_phone/src/play_phone'
sys.path.append(rm_api_path)
from include.RM_API.Python.robotic_arm_package.robotic_arm import *


# 机械臂控制类
class ArmController:
    def __init__(self, ip_address):
        # 初始化连接机械臂
        self.robot = Arm(RM65, ip_address, None)
        print(self.robot.API_Version())

    def move_joint_position(self, pose, speed=1):
        """关节运动模式"""
        self.robot.Movej_Cmd(pose, speed)

    def move_line_position(self, pose, speed=1):
        """直线运动模式"""
        self.robot.Movel_Cmd(pose, speed)

    def move_jp_position(self, pose, speed=1):
        """解算运动模式"""
        self.robot.Movej_P_Cmd(pose, speed)
        self.robot.Auto_Set_Tool_Frame()

    def get_current_position(self):
        """获取机械臂当前状态"""
        ret, joints, pose, Arm_err, Sys_err = self.robot.Get_Current_Arm_State(retry=1)
        if ret == 0:
            return pose
        else:
            raise Exception(f"获取机械臂状态失败: {Arm_err}, {Sys_err}")

    def close(self):
        """关闭机械臂连接"""
        self.robot.RM_API_UnInit()
        self.robot.Arm_Socket_Close()


# ROS 控制类
class RosController(Node):
    def __init__(self, ip_address):
        super().__init__('ros_controller')
        # 创建机械臂控制类实例
        self.arm_controller = ArmController(ip_address)

        # 创建订阅者监听新位姿
        self.position_subscriber = self.create_subscription(
            String, 'position_topic', self.position_callback, 10
        )

        # 创建整型发布者
        self.int_publisher = self.create_publisher(Int32, 'int_topic', 10)

        self.get_logger().info('ROS 控制节点已启动')

    def move_fix_position(self, fixed_pose, speed=1):

        # 移动到固定位姿
        self.get_logger().info(f"Moving to fixed pose 1: {fixed_pose}")
        self.arm_controller.move_joint_position(fixed_pose, speed)

    def move_line_position(self, target_pose, speed=1):

        # 移动到目标位姿（直线运动模式）
        self.get_logger().info(f"Moving to target pose: {target_pose}")
        self.arm_controller.move_line_position(target_pose, speed)

    def move_jp_position(self, target_pose, speed=1):
        # 移动到目标位姿（jp运动模式）
        self.get_logger().info(f"Moving to inverse pose: {target_pose}")
        self.arm_controller.move_jp_position(target_pose, speed)

    def position_callback(self, msg):
        """接收新的位姿并更新"""
        pose = self.parse_position(msg.data)
        if pose:
            self.get_logger().info(f"接收到目标位姿: {pose}")
            self.target_pose = pose  # 更新目标位姿
        else:
            self.get_logger().error(f"Failed to parse position from message: {msg.data}")

    def parse_position(self, data):
        """解析 JSON 数据并提取位姿"""
        try:
            # 假设 JSON 数据格式为 {"x": 0.0, "y": 0.0, "z": 0.0, "roll": 0.0, "pitch": 0.0, "yaw": 0.0}
            json_data = json.loads(data)
            position = [
                json_data["x"],
                json_data["y"],
                json_data["z"],
                json_data["roll"],
                json_data["pitch"],
                json_data["yaw"]
            ]
            return position
        except (json.JSONDecodeError, KeyError) as e:
            self.get_logger().error(f"Error parsing JSON data: {e}")
            return None

    def publish_integer(self, value):
        """发布整型消息"""
        int_msg = Int32()
        int_msg.data = value
        self.int_publisher.publish(int_msg)
        self.get_logger().info(f'发布整型数据: {value}')

    def close(self):
        """关闭机械臂控制"""
        self.arm_controller.close()


def main():
    rclpy.init()
    ip_address = "192.168.1.18"  # 替换为你的机械臂 IP 地址
    node = RosController(ip_address)

    try:
        # 步骤1：执行初步的三步运动
        fixed_pose_1 = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        node.move_fix_position(fixed_pose_1)

        # 步骤2：使用 spin_once 更新并获取新的位姿
        rclpy.spin_once(node)  # 更新消息

        node.move_line_position(node.target_pose)
        rclpy.spin_once(node)  # 更新消息

        node.move_jp_position(node.target_pose)
        node.publish_integer(3)  # 发布整数消息表示完成

    finally:
        node.close()


if __name__ == '__main__':
    main()
