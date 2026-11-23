#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "lookie_neo_base/lookie_neo_base.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<lookie_neo_base::LookieNeoBase>();
  int code = 0;
  if (node->Start()) {
    rclcpp::spin(node);
    node->Stop();
  } else {
    code = 1;
  }
  node.reset();
  rclcpp::shutdown();
  return code;
}
