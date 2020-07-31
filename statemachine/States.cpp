//
//  States.cpp
//  statemachine
//
//  Created by Richard Robinson on 2020-07-31.
//

#include "States.hpp"

namespace Modern {

void GoNState::onUpdate(int input, StateContext *context) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    
    switch (input) {
        case 0:
            context->setState(new GoNState());
            break;
            
        case 1:
            context->setState(new WaitNState());
            break;
            
        case 2:
            context->setState(new GoNState());
            break;
            
        case 3:
            context->setState(new WaitNState());
            break;
    }
}

void GoEState::onUpdate(int input, StateContext *context) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    
    switch (input) {
        case 0:
        case 1:
            context->setState(new GoEState());
            break;
            
        case 2:
        case 3:
            context->setState(new WaitEState());
            break;
    }
}

void WaitNState::onUpdate(int input, StateContext *context) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    
    context->setState(new GoEState());
}

void WaitEState::onUpdate(int input, StateContext *context) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    
    context->setState(new GoNState());
}

}
