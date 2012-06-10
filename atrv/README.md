# ATRV Project

## Installation

### Create a ROS workspace (if you don't have one already):

    mkdir ~/atrv_ws
    cd ~/atrv_ws
    rosws init .
    
Note: for new versions of rosws the ROS_ROOT path must be given:

    rosws init . $ROS_ROOT

_Note: you can change `~/atrv_ws/` to any path you would like._

### Source the `setup.bash` file to get the ROS_WORKSPACE environment variable up-to-date:

    source setup.bash

### Add the atrv repos to your workspace:

    rosws merge https://raw.github.com/GAVLab/gavlab-ros-pkg/master/atrv/atrv.rosinstall

### Fetch/Update all the repos in your workspace:

    rosinstall .
    source setup.bash

### Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv

