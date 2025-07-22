#include "exair_ui/dual_camera_viewer.hpp"
#include <cv_bridge/cv_bridge.hpp>

DualCameraViewer::DualCameraViewer(rclcpp::Node::SharedPtr node, QWidget *parent)
: QWidget(parent)
{
  image_label_1_ = new QLabel(this);
  image_label_2_ = new QLabel(this);

  image_label_1_->setFixedSize(640, 480);
  image_label_2_->setFixedSize(640, 480);

  sub_1_ = node->create_subscription<sensor_msgs::msg::Image>(
    "/arducam/image_raw", 10,
    [this](const sensor_msgs::msg::Image::SharedPtr msg) { imageCallback1(msg); });

  sub_2_ = node->create_subscription<sensor_msgs::msg::Image>(
    "/realsense/image_raw", 10,
    [this](const sensor_msgs::msg::Image::SharedPtr msg) { imageCallback2(msg); });
}

void DualCameraViewer::showImage(QLabel *label, const sensor_msgs::msg::Image::SharedPtr &msg)
{
  try {
    cv::Mat cv_image = cv_bridge::toCvCopy(msg, msg->encoding)->image;
    QImage qimage(cv_image.data, cv_image.cols, cv_image.rows, QImage::Format_RGB888);
    label->setPixmap(QPixmap::fromImage(qimage).scaled(label->size(), Qt::KeepAspectRatio));
  } catch (cv_bridge::Exception &e) {
    RCLCPP_ERROR(rclcpp::get_logger("DualCameraViewer"), "cv_bridge exception: %s", e.what());
  }
}

void DualCameraViewer::imageCallback1(const sensor_msgs::msg::Image::SharedPtr msg)
{
  
  showImage(image_label_1_, msg);
}

void DualCameraViewer::imageCallback2(const sensor_msgs::msg::Image::SharedPtr msg)
{
  showImage(image_label_2_, msg);
}

QLabel *DualCameraViewer::label1() const{
  return image_label_1_;
} 
QLabel  *DualCameraViewer::label2() const{
  return image_label_2_ ;
}