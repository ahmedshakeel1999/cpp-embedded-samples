#include "motor_controller.h"
#include <algorithm>
#include <cmath>

MotorController::MotorController(uint8_t pwmPin, uint8_t dirPin,
                                  float maxSpeed)
    : pwmPin_(pwmPin),
      dirPin_(dirPin),
      maxSpeed_(maxSpeed),
      currentSpeed_(0.0f),
      currentDirection_(Direction::STOP) {}

void MotorController::setSpeed(float speedPercent) {
    validateSpeed(speedPercent);
    currentSpeed_ = speedPercent;
    uint8_t pwmValue = speedToPWM(speedPercent);
    // analogWrite(pwmPin_, pwmValue); // Hardware call
}

void MotorController::setDirection(Direction dir) {
    currentDirection_ = dir;
    // digitalWrite(dirPin_, dir == Direction::FORWARD ? HIGH : LOW);
}

void MotorController::emergencyStop() {
    currentSpeed_ = 0.0f;
    currentDirection_ = Direction::STOP;
    // analogWrite(pwmPin_, 0);
}

void MotorController::validateSpeed(float speed) const {
    if (speed < 0.0f || speed > maxSpeed_) {
        throw std::out_of_range("Speed out of valid range");
    }
}

uint8_t MotorController::speedToPWM(float speed) const {
    return static_cast<uint8_t>((speed / maxSpeed_) * 255.0f);
}
