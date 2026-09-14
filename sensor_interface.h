#pragma once

/**
 * @brief Abstract base class for all sensor types
 * Demonstrates polymorphism and interface design in embedded C++
 */
class SensorInterface {
public:
    virtual ~SensorInterface() = default;
    virtual float read() = 0;
    virtual bool isReady() const = 0;
    virtual void calibrate() = 0;
    virtual const char* getName() const = 0;
};
