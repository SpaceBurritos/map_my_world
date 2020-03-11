#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    //ROS_INFO_STREAM("Moving the robot in lin x: " + std::to_string(lin_x) + " ang z: " + std::to_string(ang_z));
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if(!client.call(srv)){
      ROS_ERROR("Failed to call service command_robot");
    }
 
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    
    

    int white_pixel = 255;
    double left = img.step/3;
    double middle = 2*img.step/3;
    bool white_pixel_bool = false;
    int pos;
    for (int i = 0; i < img.height * img.step; i += 3){
	if(img.data[i] == white_pixel && img.data[i+1] == white_pixel && img.data[i+2] == white_pixel){
	  pos = i % img.step;
	  white_pixel_bool = true;
	  break;
	}
    }
    if (white_pixel_bool){
      	if (pos <= left){
	  drive_robot(0.1, 0.3);
	} else if(pos <= middle){
	  drive_robot(0.25, 0.0);
	} else {
	  drive_robot(0.1, -0.3);
	}
    } else {
	drive_robot(0,0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
