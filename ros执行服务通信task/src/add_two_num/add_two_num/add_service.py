#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rclpy
from rclpy.node   import Node
from interface.srv import AddTwoInts

class adderServer(Node):
    def __init__(self, name):
        super().__init__(name)
        self.srv = self.create_service(AddTwoInts, 'add_two_ints', self.adder_callback)

    def adder_callback(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        return response

def main(args=None):
    rclpy.init(args=args)
    node = adderServer("service_adder_server")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
