#pragma once
#include "sensor_interface.h"
#include <cstdint>

/**
 * @brief HC-SR04 Ultrasonic Distance Sensor
 * Used in AGV project for real-time obstacle detection
 */
class UltrasonicSensor : public SensorInterface {
public:
    static constexpr float MIN_DISTANCE_CM = 2.0f;
    static constexpr float MAX_DISTANCE_CM = 400.0f;
    static constexpr float OBSTACLE_THRESHOLD_CM = 30.0f;

    UltrasonicSensor(uint8_t trigPin, uint8_t echoPin);

    float read() override;
    bool isReady() const override;
    void calibrate() override;
    const char* getName() const override { return "UltrasonicHCSR04"; }

    bool isObstacleDetected() const;
    float getLastReading() const { return lastReading_; }

private:
    uint8_t trigPin_;
    uint8_t echoPin_;
    float lastReading_;
    bool calibrated_;

    float measureDistance() const;
    bool isValidReading(float distance) const;
};
