#include "robot_control/robot.h"

#include <cmath>

#define DISCHARGE_RATE 1
#define CHARGE_RATE 10

Robot::Robot() : battery_percentage(100), is_charging(false) {}
// Positive turn rate means the robot turns left, as per REP 103
void Robot::SetSpeed(float forwards, float turn) {
  vel_forwards = forwards;
  vel_yaw = turn;
}
void Robot::Update(float dt) {
  if (is_charging) {
    battery_percentage += CHARGE_RATE * dt;
  } else {
    float distance_forward = vel_forwards * dt;
    odom.yaw += vel_yaw * dt;
    odom.x += distance_forward * sin(odom.yaw);
    odom.y += distance_forward * cos(odom.yaw);

    battery_percentage -= DISCHARGE_RATE * (distance_forward * vel_forwards);
  }
}
RobotControlInterface::Position2D Robot::GetPosition() { return odom; }
float Robot::GetBatteryPercentage() { return battery_percentage; }