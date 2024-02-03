#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <can_plugins2/msg/frame.hpp>
#include "can_utils.hpp"
#include <math.h>

namespace can_utils
{
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
      "joy", 10, std::bind(&MinimalPublisher::joy_callback, this, _1)
    );

    timer_target_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_target_callback, this));
  }

private:
  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr joy_msg)
  {
    if (joy_msg->buttons[0] == 1)
    {
      can_plugins2::msg::Frame mode_msg = can_utils::generate_shirasu_mode(shirasu_id, 5);
      publisher_->publish(mode_msg);
      RCLCPP_INFO(this->get_logger(), "Published Shirasu Mode: '%d'", mode_msg.data[0]);
    }
  }

  void timer_target_callback()
  {
    can_plugins2::msg::Frame target_msg = can_utils::generate_shirasu_target(shirasu_id + 1, static_cast<float>(5.0));
    publisher_->publish(target_msg);
    RCLCPP_INFO(this->get_logger(),"any");
  }

  rclcpp::TimerBase::SharedPtr timer_target_;
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_subscriber_;
  rclcpp::Publisher<can_plugins2::msg::Frame>::SharedPtr publisher_;
};

int main(int argc, char **argv)
{
    ros::Publisher chatter = n.advertise<shirasu_ros::CanFrame>("can_tx", 1000); // 仮のshirasuのデータ型

    ros::Subscriber sub = n.subscribe("joy", 1000, joyCallback);

    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        if (gcount == 1)
        {
            const sensor_msgs::Joy& msg = gmsg;

            if (msg.buttons[2] == 1)
            {
                chatter.publish(get_frame(0x100, static_cast<uint8_t>(5)));
                chatter.publish(get_frame(0x110, static_cast<uint8_t>(5)));
                chatter.publish(get_frame(0x120, static_cast<uint8_t>(5)));
                chatter.publish(get_frame(0x130, static_cast<uint8_t>(5)));
            }
            // ↑mode_velへ移行

            if (msg.buttons[1] == 1)
            {
                chatter.publish(get_frame(0x100, static_cast<uint8_t>(1)));
                chatter.publish(get_frame(0x110, static_cast<uint8_t>(1)));
                chatter.publish(get_frame(0x120, static_cast<uint8_t>(1)));
                chatter.publish(get_frame(0x130, static_cast<uint8_t>(1)));
            }
            // ↑手動でmodeをfalseへ

            float x = -(msg.axes[0]);
            float y = (msg.axes[1]);
            float r = 0;

            if (msg.buttons[4] == 1)
            {
                r = 1.0f;
            }
            // ↑左回転
            else if (msg.buttons[5] == 1)
            {
                r = -1.0f;
            }
            // ↑右回転
            else if (msg.buttons[4] == msg.buttons[5])
            {
                r = 0.0f;
            }
            chatter.publish(get_frame(0x101, 6.28f * (y - x + r)));
            chatter.publish(get_frame(0x111, 6.28f * (x + y + r)));
            chatter.publish(get_frame(0x121, 6.28f * (x - y + r)));
            chatter.publish(get_frame(0x131, 6.28f * (-x - y + r)));
        }

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
