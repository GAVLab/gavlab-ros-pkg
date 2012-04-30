# ATRV Project

## Installation

### Create a ROS workspace (if you don't have one already):

    mkdir ~/atrv_ws
    cd ~/atrv_ws
    rosws init .
    
_Note: for new versions of rosws the ROS_ROOT path must be given:

    rosws init . $ROS_ROOT

_Note: you can change `~/atrv_ws/` to any path you would like._

### Source the `setup.bash` file to get the ROS_WORKSPACE environment variable up-to-date:

    source setup.bash

### Download the ATRV project with the rosinstall file:

    rosinstall $ROS_WORKSPACE "https://raw.github.com/GAVLab/gavlab-ros-pkg/master/atrv/atrv.rosinstall"
    source setup.bash

### Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv

