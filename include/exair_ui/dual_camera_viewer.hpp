#ifndef DUAL_CAMERA_VIEWER_HPP_
#define DUAL_CAMERA_VIEWER_HPP_

#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>


class DualCameraViewer : public QWidget
{
  Q_OBJECT
  

public:
  explicit DualCameraViewer(rclcpp::Node::SharedPtr node, QWidget *parent = nullptr);

private:
  QLabel *image_label_1_;
  QLabel *image_label_2_;

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_1_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_2_;

  void imageCallback1(const sensor_msgs::msg::Image::SharedPtr msg);
  void imageCallback2(const sensor_msgs::msg::Image::SharedPtr msg);

  void showImage(QLabel *label, const sensor_msgs::msg::Image::SharedPtr &msg);

public:
  QLabel *label1() const;
  QLabel *label2() const;
};

#endif
