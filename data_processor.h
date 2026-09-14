#pragma once
#include <vector>
#include <cstdint>
#include <functional>
#include <optional>

/**
 * @brief Sensor data processing pipeline
 * Reflects data pipeline work from HIL telemetry (HEERO Motors + Wabtec)
 */
struct SensorReading {
    uint32_t timestamp_ms;
    float value;
    uint8_t sensorId;
    bool isValid;
};

class DataProcessor {
public:
    using FilterFunc = std::function<float(const std::vector<float>&)>;

    explicit DataProcessor(size_t bufferSize = 100);

    void addReading(const SensorReading& reading);
    std::optional<float> getMovingAverage(size_t windowSize) const;
    std::optional<float> getMin() const;
    std::optional<float> getMax() const;
    float getStdDev() const;
    bool detectAnomaly(float threshold) const;
    void clearBuffer();
    size_t getBufferSize() const { return buffer_.size(); }

private:
    std::vector<SensorReading> buffer_;
    size_t maxBufferSize_;

    std::vector<float> extractValues() const;
};
