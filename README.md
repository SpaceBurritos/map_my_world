# Map my World?

Third project on the Robotic Software Engineer Nanodegree of Udacity.  
Consisted on the implemantation of the rtabmap package for mapping on a given environment

__Steps to initialization__  
  
  1. Go to cd /home/workspace
  2. catkin_make
  3. When finished, type source devel/setup.bash
  3. roslaunch my_robot world.launch
  4. On another terminal go to cd /home/workspace
  5. Type source devel/setup.bash
  5. And type roslaunch my_robot mapping.launch
  6. On a third terminal, go to cd /home/workspace
  7 Type source devel/setup.bash
  8. And type rosrun teleop_twist_keyboard teleop_twist_keyboard.py

This is the like to the rtabmap file:
https://www.dropbox.com/s/yrx956wcn8ussmn/rtabmap.db?dl=0

 __Initialized Robot__
 
 ![Initialized_robot](/img/Initialized_robot.PNG)

__Localized Robot__

![Localized Logo](/img/Localized_Robot.PNG)
