// Copyright 2024 The Technology Innovation Institute (TII)
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

/**
 * @author Damien SIX (damien@robotsix.net)
 */

#include <gtest/gtest.h>
#include "ros2_uav_cpp/ros2_logger.hpp"

using ros2_uav::utils::RosLoggerInterface;

TEST(RosLoggerInterface, Console)
{
  // Create a logger
  auto logger = rclcpp::get_logger("test_logger");
  logger.set_level(rclcpp::Logger::Level::Debug);
  // Create a RosLoggerInterface object
  auto ros_logger = std::make_shared<RosLoggerInterface>(logger);
  // Use the created interface
  uav_cpp::logger::Logger::setCustomLogger(ros_logger);

  testing::internal::CaptureStderr();
  UAVCPP_DEBUG("Test message {}", 1);
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_TRUE(output.find("[test_logger]: Test message 1") != std::string::npos);
  testing::internal::CaptureStderr();
  UAVCPP_INFO("Test message {}", 2);
  output = testing::internal::GetCapturedStderr();
  EXPECT_TRUE(output.find("[test_logger]: Test message 2") != std::string::npos);
  testing::internal::CaptureStderr();
  UAVCPP_WARN("Test message {}", 3);
  output = testing::internal::GetCapturedStderr();
  EXPECT_TRUE(output.find("[test_logger]: Test message 3") != std::string::npos);
  testing::internal::CaptureStderr();
  UAVCPP_ERROR("Test message {}", 4);
  output = testing::internal::GetCapturedStderr();
  EXPECT_TRUE(output.find("[test_logger]: Test message 4") != std::string::npos);
  testing::internal::CaptureStderr();
  UAVCPP_FATAL("Test message {}", 5);
  output = testing::internal::GetCapturedStderr();
  EXPECT_TRUE(output.find("[test_logger]: Test message 5") != std::string::npos);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
