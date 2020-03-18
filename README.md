# Where am I?

Second project on the Robotic Software Engineer Nanodegree of Udacity.  
Consisted on the implemantation of the AMCL package on a robot based on a given map

__Steps to initialization__  
  
  1. Uncompress the file map.pgm.tar.gz located on the folder ~/where_am_i/my_robot/maps/ and make sure the  
     the name  of the file is map.pgm
  2. Go to cd /home/workspace
  3. catkin_make
  4. roslaunch my_robot world.launch
  5. On another terminal go to cd /home/workspace
  6. And type roslaunch my_robot amcl.launch

__On RVIZ__
 - Add Map topic/map
 - Add RobotModel
 - Add PoseArray topic/particlecloud
 - Use the 2v Nav Goal to make the robot move and see how it localizes itself.  
   
 __Initialized Robot__
 
 ![Initialized_robot](/img/Initialized_robot.PNG)

__Localized Robot__

![Localized Logo](/img/Localized_robot.PNG)
