#pragma once
#include "robot_control/robot_control_interface.h"

class Robot {
 public:
  using Ptr = std::shared_ptr<Robot>;

  struct Position2D {
    float odom_x;
    float odom_y;
    float yaw;
  };

  Robot();
  // Positive turn rate means the robot turns left, as per REP 103
  virtual void SetSpeed(float forwards, float turn);
  virtual void Update(float dt);
  virtual RobotControlInterface::Position2D GetPosition();
  virtual float GetBatteryPercentage();

 private:
  RobotControlInterface::Position2D odom;
  float vel_forwards, vel_yaw;
  float battery_percentage;
  bool is_charging;
};