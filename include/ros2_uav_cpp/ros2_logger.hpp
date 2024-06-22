// Copyright 2024 Damien SIX (damien@robotsix.net)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <rclcpp/rclcpp.hpp>
#include <uav_cpp/utils/logger.hpp>

namespace ros2_uav::utils
{
class RosLoggerInterface : public uav_cpp::logger::LoggerInterface
{
public:
  explicit RosLoggerInterface(rclcpp::Logger logger)
  : logger_(logger) {}

  void debug(const std::string & msg) override
  {
    RCLCPP_DEBUG(logger_, msg.c_str());
  }
  void info(const std::string & msg) override
  {
    RCLCPP_INFO(logger_, msg.c_str());
  }
  void warn(const std::string & msg) override
  {
    RCLCPP_WARN(logger_, msg.c_str());
  }
  void error(const std::string & msg) override
  {
    RCLCPP_ERROR(logger_, msg.c_str());
  }
  void fatal(const std::string & msg) override
  {
    RCLCPP_FATAL(logger_, msg.c_str());
  }

private:
  rclcpp::Logger logger_;
};
}  // namespace ros2_uav::utils
