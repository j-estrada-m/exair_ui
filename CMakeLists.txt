cmake_minimum_required(VERSION 3.8)
project(exair_ui)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
find_package(image_transport REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui)
find_package(OpenCV REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(
  include
  ${cv_bridge_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)
add_executable(viewer src/main.cpp src/dual_camera_viewer.cpp include/exair_ui/dual_camera_viewer.hpp)

target_include_directories(viewer PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

ament_target_dependencies(viewer
  rclcpp
  sensor_msgs
  cv_bridge
  image_transport
)

target_link_libraries(viewer
  Qt6::Widgets
  ${OpenCV_LIBRARIES}
)

install(TARGETS viewer
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()