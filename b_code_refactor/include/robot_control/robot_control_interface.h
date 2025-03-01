#pragma once
#include <memory>

class RobotControlInterface {
 public:
  using Ptr = std::shared_ptr<RobotControlInterface>;

  struct Position2D {
    float x = 0;
    float y = 0;
    float yaw = 0;
  };

  virtual ~RobotControlInterface() {}
  // Positive turn rate means the robot turns left, as per REP 103
  virtual void SetSpeed(float forwards, float turn) = 0;
  virtual void Update(float dt) = 0;
  virtual Position2D GetPosition() = 0;
  virtual float GetBatteryPercentage() = 0;
};