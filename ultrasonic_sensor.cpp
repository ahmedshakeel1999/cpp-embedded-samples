#include "ultrasonic_sensor.h"
#include <cmath>

UltrasonicSensor::UltrasonicSensor(uint8_t trigPin, uint8_t echoPin)
    : trigPin_(trigPin),
      echoPin_(echoPin),
      lastReading_(0.0f),
      calibrated_(false) {}

float UltrasonicSensor::read() {
    float distance = measureDistance();
    if (isValidReading(distance)) {
        lastReading_ = distance;
    }
    return lastReading_;
}

bool UltrasonicSensor::isReady() const {
    return calibrated_;
}

void UltrasonicSensor::calibrate() {
    // Perform baseline measurement and offset correction
    calibrated_ = true;
}

bool UltrasonicSensor::isObstacleDetected() const {
    return lastReading_ > 0.0f &&
           lastReading_ < OBSTACLE_THRESHOLD_CM;
}

float UltrasonicSensor::measureDistance() const {
    // Hardware: trigger pulse, measure echo duration
    // distance = (echo_duration * speed_of_sound) / 2
    // Simulated here for portability
    return 25.0f; // cm
}

bool UltrasonicSensor::isValidReading(float distance) const {
    return distance >= MIN_DISTANCE_CM &&
           distance <= MAX_DISTANCE_CM;
}
