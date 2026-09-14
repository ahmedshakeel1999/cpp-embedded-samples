# C++ Embedded Systems — Code Samples
**Muhammad Ahmed Shakeel** | Embedded Software Engineer  
Munich, Germany | ahmshakeel99@gmail.com

---

## About This Repository
Clean C++ code samples demonstrating embedded systems 
programming patterns from my professional and project experience.
Code is written for readability and portability — hardware calls 
are commented out and replaced with simulation equivalents.

---

## Contents

### 01 — Motor Controller
PWM-based DC motor control with OOP design.
- Speed validation and direction control
- Emergency stop mechanism  
- Separation of hardware abstraction from logic

### 02 — Sensor Abstraction Layer
Polymorphic sensor interface using abstract base class.
- UltrasonicSensor implementing SensorInterface
- Easy to extend for any sensor type
- Obstacle detection logic

### 03 — CAN Bus Handler
CAN message handling with callback system.
- Message validation and queuing
- Callback registration per message ID
- Based on real CAN work (HEERO Motors BMS/TCU)

### 04 — Robot State Machine
Generic finite state machine for autonomous navigation.
- Condition-based transitions
- Callback on state change  
- From AGV project (ROS + Raspberry Pi)

### 05 — Sensor Data Pipeline
Real-time data processing with anomaly detection.
- Moving average, min/max, standard deviation
- Anomaly detection threshold
- Circular buffer pattern

---

## Experience Behind This Code

| Project | Tech Stack |
|---------|-----------|
| E-works Mobility (HEERO Motors) | C/C++, STM32, CAN-Bus, HIL |
| Wabtec / Annax GmbH | C++, Python, SQL Server |
| AGV Final Year Project | C++, Python, ROS, OpenCV |

---

## Build

```bash
# Each folder is self-contained
cd 01_motor_controller
g++ -std=c++17 -o motor_demo main.cpp motor_controller.cpp
./motor_demo
```

---

## Contact
ahmshakeel99@gmail.com | 
[LinkedIn](https://linkedin.com/in/ahmed-shakeel-328352194)
