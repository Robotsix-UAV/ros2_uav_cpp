cmake_minimum_required(VERSION 3.8)
project(ros2_uav_cpp)

set(CMAKE_CXX_STANDARD 20)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(uav_cpp REQUIRED)

add_library(ros2_uav_logger INTERFACE include/ros2_uav_cpp/ros2_logger.hpp)
ament_target_dependencies(ros2_uav_logger INTERFACE rclcpp)
target_link_libraries(ros2_uav_logger INTERFACE uav_cpp::logger)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_gtest(ros2_logger_test test/ros2_logger_test.cpp)
  target_include_directories(ros2_logger_test PRIVATE include)
  target_link_libraries(ros2_logger_test ros2_uav_logger)
endif()

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ros2_uav_cpp
  DESTINATION include)

install(TARGETS ros2_uav_logger
  EXPORT ros2_uav_logger_export
  INCLUDES DESTINATION include)

ament_export_dependencies(
  rclcpp
  uav_cpp
)

ament_export_targets(
  ros2_uav_logger_export
  HAS_LIBRARY_TARGET)

  ament_package()
