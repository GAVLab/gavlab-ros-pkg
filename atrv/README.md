# ATRV Project

## Installation

Download the ATRV project with the rosinstall file:

    rosinstall ~/atrv_ws "https://raw.github.com/GAVLab/gavlab-ros-pkg/master/atrv.rosinstall" $ROS_ROOT
    cd ~/atrv_ws
    source setup.bash

Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv
