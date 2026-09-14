#include "motor_controller.h"
#include <iostream>

int main() {
    MotorController motor(9, 8, 100.0f);  // PWM pin 9, DIR pin 8

    motor.setDirection(MotorController::Direction::FORWARD);
    motor.setSpeed(75.0f);

    std::cout << "Motor running at: "
              << motor.getCurrentSpeed() << "%" << std::endl;

    motor.emergencyStop();
    std::cout << "Motor stopped. Running: "
              << std::boolalpha << motor.isRunning() << std::endl;

    return 0;
}
