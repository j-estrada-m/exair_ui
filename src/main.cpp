#include <QApplication>
#include <rclcpp/rclcpp.hpp>
#include "exair_ui/dual_camera_viewer.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  auto node = rclcpp::Node::make_shared("exair_ui_node");

  DualCameraViewer viewer(node);
  viewer.show();

  // ✅ Spin the real node (not a dummy one)
  std::thread ros_thread([&]() {
    rclcpp::spin(node);
  });

  int result = app.exec();
  rclcpp::shutdown();
  ros_thread.join();
  return result;
}
