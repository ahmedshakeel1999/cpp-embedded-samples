#pragma once
#include <functional>
#include <unordered_map>
#include <string>

/**
 * @brief Generic state machine for autonomous robot navigation
 * Used in AGV project for navigation logic and obstacle response
 */
enum class RobotState {
    IDLE,
    NAVIGATING,
    OBSTACLE_DETECTED,
    AVOIDING,
    TASK_COMPLETE,
    ERROR
};

struct StateTransition {
    RobotState from;
    RobotState to;
    std::function<bool()> condition;
    std::function<void()> action;
};

class RobotStateMachine {
public:
    using StateCallback = std::function<void(RobotState, RobotState)>;

    RobotStateMachine();

    void update();
    bool forceTransition(RobotState newState);
    void addTransition(StateTransition transition);
    void onStateChange(StateCallback callback);

    RobotState getCurrentState() const { return currentState_; }
    std::string getStateName(RobotState state) const;
    uint32_t getStateCount() const { return stateChangeCount_; }

private:
    RobotState currentState_;
    uint32_t stateChangeCount_;
    std::vector<StateTransition> transitions_;
    StateCallback onChangeCallback_;

    void executeTransition(const StateTransition& t);
};
