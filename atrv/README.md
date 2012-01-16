# ATRV Project

## Installation

Create a ROS workspace (if you don't have one already):

    mkdir ~/atrv_ws
    cd ~/atrv_ws
    rosws init .

Download the ATRV project with the rosinstall file:

    rosinstall ~/atrv_ws "https://raw.github.com/GAVLab/gavlab-ros-pkg/master/atrv/atrv.rosinstall"
    source setup.bash

Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv

