#!/usr/bin/env python
# encoding: utf-8

##
# BSD License
##
# Copyright (c) 2011, William Woodall (wjwwood@gmail.com)
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer. Redistributions in binary
# form must reproduce the above copyright notice, this list of conditions and
# the following disclaimer in the documentation and/or other materials
# provided with the distribution. Neither the name of the software nor the
# names of its contributors may be used to endorse or promote products derived
# from this software without specific prior written permission. 
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
##

"""
joy_to_twist.py - Provides Twist messages given a joy topic.

Parameters:
    linear_scalar (default: 1.0) This is a linear scalar that is multiplied by
    the joystick message. (2.0 will result in a 2.0 m/s cmd_vel with a
    joystick msg of 1.0)

    angular_scalar (default: 0.2) This is a linear scalar
    that is multiplied by the joystick message. (0.2 will result in a 0.2
    rad/s cmd_vel with a joystick msg of 1.0)

Topics:
    Subcribes to joy (sensor_msgs/Joy)
    Publishes to cmd_vel (geometry_msgs/Twist)

Created by William Woodall on 2010-07-12.
"""
__author__ = "William Woodall"

###  Imports  ###

# ROS imports
import roslib; roslib.load_manifest('joy_to_twist')
import rospy

# ROS msg and srv imports
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

# Python Libraries
#import sys
import traceback

###  Classes  ###

class Joy2Twist(object):
    """Joy2Twist ROS Node"""
    def __init__(self):
        # Initialize the Node
        rospy.init_node("Joy2Twist")
        
        # Get the linear scalar and angular scalar parameter
        self.LINEAR_SCALAR = rospy.get_param('~max_linear_vel', 0.2)
        self.ANGULAR_SCALAR = rospy.get_param('~max_angular_vel', 0.05)
        rospy.loginfo("Using max_linear_vel: %f and max_angular_vel: %f" %
                      (self.LINEAR_SCALAR, self.ANGULAR_SCALAR))
        self.invert_z = -1 if bool(rospy.get_param('~invert_z', '')) else 1
        
        # Setup the Joy topic subscription
        self.joy_subscriber = rospy.Subscriber("joy", Joy, self.handleJoyMessage, queue_size=1)
        
        # Setup the Twist topic publisher
        self.twist_publisher = rospy.Publisher("cmd_vel", Twist)
        
        # Spin
        rospy.spin()

    def handleJoyMessage(self, data):
        """Handles incoming Joy messages"""
        msg = Twist()
        trigger_val = data.axes[2]
        trigger_val += 1
        trigger_val /= 2
        trigger_val = 1 - trigger_val
        msg.linear.x = data.axes[1]
        scalar = (self.LINEAR_SCALAR/4.0 + trigger_val*(self.LINEAR_SCALAR*3.0/4.0))
        msg.linear.x *= scalar
        msg.angular.z = data.axes[0] * self.invert_z
        scalar = (self.ANGULAR_SCALAR/4.0 + trigger_val*(self.ANGULAR_SCALAR*3.0/4.0))
        scalar *= -1
        msg.angular.z *= scalar
        self.twist_publisher.publish(msg)
    

###  If Main  ###
if __name__ == '__main__':
    try:
        Joy2Twist()
    except:
        rospy.logerr("Unhandled Exception in the joy2Twist"+
                     " Node:+\n"+traceback.format_exc())
