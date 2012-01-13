# ROS stacks and packages for the GAVLAB

## ATRV Project

### Installation

Create a ROS workspace:

    mkdir atrv_ws
    cd atrv_ws
    rosws init .
    source setup.bash

Add the ATRV project's rosinstall file:

    rosinstall INSERT STATIC LINK TO ROSINSTALL FILE
    source setup.bash

Build the ATRV project:

    rosmake --rosdep-install gavlab_atrv
