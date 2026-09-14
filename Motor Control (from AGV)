#pragma once
#include <cstdint>
#include <stdexcept>

/**
 * @brief PWM-based DC Motor Controller
 * Demonstrates OOP design for embedded actuator control
 * Based on automotive EV control unit experience (HEERO Motors)
 */
class MotorController {
public:
    enum class Direction { FORWARD, BACKWARD, STOP };

    explicit MotorController(uint8_t pwmPin, uint8_t dirPin,
                              float maxSpeed = 100.0f);

    void setSpeed(float speedPercent);
    void setDirection(Direction dir);
    void emergencyStop();
    float getCurrentSpeed() const { return currentSpeed_; }
    Direction getDirection() const { return currentDirection_; }
    bool isRunning() const { return currentSpeed_ > 0.0f; }

private:
    uint8_t pwmPin_;
    uint8_t dirPin_;
    float maxSpeed_;
    float currentSpeed_;
    Direction currentDirection_;

    void validateSpeed(float speed) const;
    uint8_t speedToPWM(float speed) const;
};
