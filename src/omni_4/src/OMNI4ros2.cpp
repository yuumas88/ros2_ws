#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <can_plugins2/msg/frame.hpp>
#include "can_utils.hpp"
#include <cmath>

using namespace can_utils;

can_plugins2::msg::Frame generate_shirasu_mode(const uint16_t id, const uint8_t mode)
{
  const int byte_size = 1;  // Mode is 1 byte.
  
  can_plugins2::msg::Frame frame;
  frame.id = id;
  frame.is_rtr = false;
  frame.is_extended = false;
  frame.is_error = false;

  frame.dlc = byte_size;

  frame.data[0] = mode;

  return frame;
}

can_plugins2::msg::Frame generate_shirasu_target(const uint16_t id, const float data)
{
  const int float_size = 4;  // float is 4 bytes.
  
  can_plugins2::msg::Frame frame;
  frame.id = id;
  frame.is_rtr = false;
  frame.is_extended = false;
  frame.is_error = false;

  frame.dlc = float_size;

  can_pack<float>(frame.data, data);

  const auto tmp1 = frame.data[0];
  const auto tmp2 = frame.data[1];
  const auto tmp3 = frame.data[2];
  const auto tmp4 = frame.data[3];

  frame.data[0] = tmp4;
  frame.data[1] = tmp3;
  frame.data[2] = tmp2;
  frame.data[3] = tmp1;
  
  return frame;
}

const uint16_t shirasu_id = 0x720;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher")
  {
    publisher_ = this->create_publisher<can_plugins2::msg::Frame>("can_tx", 10);

    joy_subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>(
      "joy", 10, std::bind(&MinimalPublisher::joy_callback, this, std::placeholders::_1)
    );

    timer_target_ = this->create_wall_timer(
      std::chrono::milliseconds(500), std::bind(&MinimalPublisher::timer_target_callback, this));
  }

private:
  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr joy_msg)
  {
    if (joy_msg->buttons[0] == 1){      
      publisher_->publish(generate_shirasu_mode(0x100, 5));
      publisher_->publish(generate_shirasu_mode(0x200, 5));
      publisher_->publish(generate_shirasu_mode(0x300, 5));
      publisher_->publish(generate_shirasu_mode(0x400, 5));
      // RCLCPP_INFO(this->get_logger(), "Published Shirasu Mode: '%d'", mode_msg.data[0]);
    }

    if (joy_msg->buttons[1] == 1){      
      publisher_->publish(generate_shirasu_mode(0x100, 0));
      publisher_->publish(generate_shirasu_mode(0x200, 0));
      publisher_->publish(generate_shirasu_mode(0x300, 0));
      publisher_->publish(generate_shirasu_mode(0x400, 0));
      // RCLCPP_INFO(this->get_logger(), "Published Shirasu Mode: '%d'", mode_msg.data[0]);
    }

    float x = -(joy_msg->axes[4]);
    float y = (joy_msg->axes[5]);

    publisher_->publish(generate_shirasu_target(0x100, x * sqrt(1 / 2) + y * sqrt(1 / 2)));
    publisher_->publish(generate_shirasu_target(0x200, -(x * sqrt(1 / 2)) + y * sqrt(1 / 2)));
    publisher_->publish(generate_shirasu_target(0x300, -(x * sqrt(1 / 2) + y * sqrt(1 / 2))));
    publisher_->publish(generate_shirasu_target(0x400, x * sqrt(1 / 2) + -(y * sqrt(1 / 2))));
  }

  void timer_target_callback()
  {
    can_plugins2::msg::Frame target_msg = generate_shirasu_target(shirasu_id + 1, static_cast<float>(5.0));
    publisher_->publish(target_msg);
    RCLCPP_INFO(this->get_logger(),"any");
  }

  rclcpp::TimerBase::SharedPtr timer_target_;
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_subscriber_;
  rclcpp::Publisher<can_plugins2::msg::Frame>::SharedPtr publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MinimalPublisher>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
