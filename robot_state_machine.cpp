#include "robot_state_machine.h"
#include <algorithm>

RobotStateMachine::RobotStateMachine()
    : currentState_(RobotState::IDLE),
      stateChangeCount_(0) {}

void RobotStateMachine::update() {
    for (const auto& t : transitions_) {
        if (t.from == currentState_ && t.condition()) {
            executeTransition(t);
            break;
        }
    }
}

bool RobotStateMachine::forceTransition(RobotState newState) {
    RobotState prev = currentState_;
    currentState_ = newState;
    ++stateChangeCount_;
    if (onChangeCallback_) {
        onChangeCallback_(prev, currentState_);
    }
    return true;
}

void RobotStateMachine::addTransition(StateTransition transition) {
    transitions_.push_back(std::move(transition));
}

void RobotStateMachine::onStateChange(StateCallback callback) {
    onChangeCallback_ = std::move(callback);
}

std::string RobotStateMachine::getStateName(RobotState state) const {
    switch (state) {
        case RobotState::IDLE:              return "IDLE";
        case RobotState::NAVIGATING:        return "NAVIGATING";
        case RobotState::OBSTACLE_DETECTED: return "OBSTACLE_DETECTED";
        case RobotState::AVOIDING:          return "AVOIDING";
        case RobotState::TASK_COMPLETE:     return "TASK_COMPLETE";
        case RobotState::ERROR:             return "ERROR";
        default:                            return "UNKNOWN";
    }
}

void RobotStateMachine::executeTransition(const StateTransition& t) {
    RobotState prev = currentState_;
    if (t.action) t.action();
    currentState_ = t.to;
    ++stateChangeCount_;
    if (onChangeCallback_) {
        onChangeCallback_(prev, currentState_);
    }
}
