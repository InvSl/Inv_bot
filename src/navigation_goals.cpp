#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;



#define NUM_GOALS 3
double goals[NUM_GOALS][3] = {
	{6.5, 0.0, 1.0}, // x y
	{3.2, 3.5, 0.5}, 
	{0.0, 0.0, 1.0}
};


int main(int argc, char** argv)
{
	ros::init(argc, argv, "navigation_goals");
	MoveBaseClient ac("move_base", true);

	while(!ac.waitForServer(ros::Duration(5.0))){
		ROS_INFO("Waiting for the move_base action server to come up");
	}

	move_base_msgs::MoveBaseGoal goal;

	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();

	for(int i = 0; i < NUM_GOALS; ++i)
	{
		goal.target_pose.pose.position.x = goals[i][0];
		goal.target_pose.pose.position.y = goals[i][1];
		goal.target_pose.pose.orientation.w = goals[i][2];

		ROS_INFO("Sending goal: (%f; %f)", goals[i][0], goals[i][1]);
		ac.sendGoal(goal);

		ac.waitForResult();
		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
			ROS_INFO("Goal achieved!");


		ros::Duration(1.0).sleep();
	}
	ROS_INFO("Done.");
	return 0;
}




