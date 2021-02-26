cmake_minimum_required(VERSION 2.8.3)
project(model)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  move_base_msgs
  actionlib
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES model
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(tf_broadcaster src/tf_broadcaster.cpp)
target_link_libraries(tf_broadcaster ${catkin_LIBRARIES})

add_executable(navigation_goals src/navigation_goals.cpp)
target_link_libraries(navigation_goals ${catkin_LIBRARIES})
