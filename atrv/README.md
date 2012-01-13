# ATRV Project

## Installation

Create a ROS workspace:

    mkdir atrv_ws
    cd atrv_ws
    rosws init .
    source setup.bash

Add the ATRV project's rosinstall file:

    rosinstall ~/atrv_ws "https://raw.github.com/GAVLab/gavlab-ros-pkg/master/atrv.rosinstall" $ROS_ROOT
    source setup.bash

Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv
