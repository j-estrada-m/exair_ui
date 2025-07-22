#include <QApplication>
#include <rclcpp/rclcpp.hpp>
#include "exair_ui/dual_camera_viewer.hpp"
#include <QMainWindow>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);
  auto node = rclcpp::Node::make_shared("exair_ui_node");
  DualCameraViewer viewer(node);  
  QMainWindow *  w = new QMainWindow;
  QWidget *central = new QWidget(w);
  QVBoxLayout* layout = new QVBoxLayout;

  w->setWindowTitle("Annulus Floor Crawler Control");
  w->setCentralWidget(central);

  layout->addWidget(viewer.label1());
  layout->addWidget(viewer.label2());
  central->setLayout(layout);
  w->show();

  std::thread ros_thread([&]() {
    rclcpp::spin(node);
  });

  int result = app.exec();
  rclcpp::shutdown();
  ros_thread.join();
  return result;
}
