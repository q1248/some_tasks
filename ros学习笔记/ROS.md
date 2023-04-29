## ROS2的一些优势
1. 不需要使用Master进行管理结点，使用DDS的机制
2. 重新设计了用户api
3. 编译系统使用ament colcon
4. 编程时更多利用面向对象的语言特性
5. ros2 所有命令集中在一个主命令当中

层级对比
![](https://book.guyuehome.com/ROS2/1.%E7%B3%BB%E7%BB%9F%E6%9E%B6%E6%9E%84/image/1.2_ROS2%E5%AF%B9%E6%AF%94ROS1/image26-16532775781034.png)

DDS是物联网中常用的通讯协议
## 理解
### 工作空间
工作空间:相当于project 
一般有 build install log src 三个文件夹
```bash
#安装src里的依赖
rosdepc install -i --from-path src --rosdistro humble -y
#使用python3-colcon-ros进行编译
colcon build
```

### 功能包
相当于一个python里的一个python包
```bash
#新建功能包
ros2 pkg create --build-type <build-type> <package_name>
```

### 节点
- 负责执行具体的任务,相当于进程
- 每个节点都是可执行的
- 每个节点id唯一

面向对象式的编写方式
```python
class HelloWorldNode(Node):

    def __init__(self, name):
    
        super().__init__(name) # ROS2节点父类初始化
        
        while rclpy.ok(): # ROS2系统是否正常运行
        
            self.get_logger().info("Hello World") # ROS2日志输出
            
            time.sleep(0.5) # 休眠控制循环时间

  

def main(args=None): # ROS2节点主入口main函数

    rclpy.init(args=args) # ROS2 Python接口初始化
    
    node = HelloWorldNode("node_helloworld_class") # 创建ROS2节点对象并进行初始化
    
    node.destroy_node() # 销毁节点对象
    
    rclpy.shutdown() # 关闭ROS2 Python接口
```
需要在setup.py添加一下配置
- 创建节点
- 销毁节点
- 关闭python接口
### 话题
作为一个桥梁，实现了节点之间某一个方向上的数据传输
使用了基于DDS的**发布/订阅模型**
发送数据的对象称之为**发布者**，接收数据的对象称之为**订阅者**，每一个话题都需要有一个名字，传输的数据也需要有固定的数据类型
**消息是ROS中的一种接口定义方式**，与编程语言无关，我们也可以通过 **.msg**后缀的文件自行定义，有了这样的接口，各种节点就像积木块一样，通过各种各样的接口进行拼接，组成复杂的机器人系统。

常用的话题操作:
```bash
$ ros2 topic list                # 查看话题列表
$ ros2 topic info <topic_name>   # 查看话题信息
$ ros2 topic hz <topic_name>     # 查看话题发布频率
$ ros2 topic bw <topic_name>     # 查看话题传输带宽
$ ros2 topic echo <topic_name>   # 查看话题数据
$ ros2 topic pub <topic_name> <msg_type> <msg_data>   # 发布话题消息
```
### 服务
从服务的实现机制上来看，这种你问我答的形式叫做**客户端/服务器模型**，简称为CS模型
服务使用的是.srv文件定义消息
服务端的基本过程
-   编程接口初始化
-   创建节点并初始化
-   创建服务器端对象
-   通过回调函数处进行服务
-   向客户端反馈应答结果
-   销毁节点并关闭接口
服务命令的常用操作如下：
```bash
$ ros2 service list                  # 查看服务列表
$ ros2 service type <service_name>   # 查看服务数据类型
$ ros2 service call <service_name> <service_type> <service_data>   # 发送服务请求
```
### 接口
**接口，它是一种相互关系，只有彼此匹配，才能建立连接。**
- 话题通信接口的定义使用的是.msg文件,只需要描述传输的每一帧数据是什么就行
- 服务通信接口的定义使用的是.srv文件,包含请求和应答两部分定义，通过中间的“---”区分
- 动作是另外一种通信机制，用来描述机器人的一个运动过程，使用.action文件定义,接口的定义分成了三个部分，分别是动作的目标，比如是开始运动，运动的结果

接口操作
```bash
$ ros2 interface list                    # 查看系统接口列表
$ ros2 interface show <interface_name>   # 查看某个接口的详细定义
$ ros2 interface package <package_name>  # 查看某个功能包中的接口定义
```

### 动作
客户端发送动作的目标，想让机器人干什么，服务器端执行动作过程， 控制机器人达到运动的目标，同时周期反馈动作执行过程中的状态,当运动执行结束后，服务器再反馈一个动作结束的信息。整个通信过程就此结束
动作通信中的客户端可以有多个，大家都可以发送运动命令，但是服务器端只能有一个
动作是一种应用层的通信机制，其底层就是基于话题和服务来实现的。

动作操作
```bash
$ ros2 action list                  # 查看服务列表
$ ros2 action info <action_name>    # 查看服务数据类型
$ ros2 action send_goal <action_name> <action_type> <action_data>   # 发送服务请求
```
### 参数
类似共享变量
在ROS系统中，参数是以**全局字典**的形态存在的,如果某一个节点对参数进行了修改，其他节点也有办法立刻知道，从而获取最新的数值。
```bash
$ ros2 param list
$ ros2 param describe turtlesim background_b   # 查看某个参数的描述信息
$ ros2 param get turtlesim background_b        # 查询某个参数的值
$ ros2 param set turtlesim background_b 10     # 修改某个参数的值
```
ROS中的参数文件使用yaml格式，可以在param命令后边跟dump子命令，将某个节点的参数都保存到文件中，或者通过load命令一次性加载某个参数文件中的所有内容：
```bash
$ ros2 param dump turtlesim >> turtlesim.yaml  # 将某个节点的参数保存到参数文件中
$ ros2 param load turtlesim turtlesim.yaml     # 一次性加载某一个文件中的所有参数
```

### 分布式通信
域内的处于两个不同物理设备上的node也能进行通信
处于同一域内的才能通信,需要如下配置
```bash
$ export ROS_DOMAIN_ID=<your_domain_id>
```
### DDS
![image.png](https://typoraup.oss-cn-beijing.aliyuncs.com/img/202304161342337.png)
结点在bus上发布消息,选择性接受自己喜欢的消息

## 多结点
**Launch启动文件**，它是ROS系统中多节点启动与配置的一种脚本
**ROS2中的Launch文件就是基于Python描述的**
```python
$ ros2 launch learning_launch simple.launch.py
```
launch文件的简单写法
```python
from launch import LaunchDescription           # launch文件的描述类
from launch_ros.actions import Node            # 节点启动的描述类

def generate_launch_description():             # 自动生成launch文件的函数
    return LaunchDescription([                 # 返回launch文件的描述信息
        Node(                                  # 配置一个节点的启动
            package='learning_topic',          # 节点所在的功能包
            executable='topic_helloworld_pub', # 节点的可执行文件
        ),
        Node(                                  # 配置一个节点的启动
            package='learning_topic',          # 节点所在的功能包
            executable='topic_helloworld_sub', # 节点的可执行文件名
        ),
    ])

```

## 常用工具
### TF
机器人坐标系的管理器
相关包:ros-humble-turtle-tf2-py ros-humble-tf2-tools
python包:transforms3d
### URDF
机器人建模方法,用来描述机器人外观、性能等各方面属性
### GAzebo
三维物理仿真平台
没有机器人时的模拟
支持动力学引擎，可以实现高质量的图形渲染，不仅可以模拟机器人及周边环境，还可以加入摩擦力、弹性系数等物理属性
相关的包:ros-humble-gazebo-*
### Rviz
三维数据可视化显示平台
$ ros2 run rviz2 rviz2
### RQT
模块可视化工具
相关包:ros-humble-rqt
