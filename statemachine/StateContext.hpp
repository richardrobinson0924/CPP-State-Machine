//
//  StateContext.hpp
//  statemachine
//
//  Created by Richard Robinson on 2020-07-22.
//

#ifndef StateContext_hpp
#define StateContext_hpp

#include <stdio.h>
#include <thread>

namespace Modern {

class StateContext {
public:
    struct State {
        virtual int out() = 0;
        
        virtual void onUpdate(int input, StateContext* context) = 0;
        
        virtual ~State() {}
    };
    
    int light = 0;
    
    StateContext(State* initialState) : currentState(initialState) {
        if (currentState != nullptr) {
            light = currentState->out();
        }
    }
    
    
    /// Transitions this StateContext's current state to the specified state.
    /// @param newState the State to transition to. It is guaranteed the memory of this pointer is freed once it is no longer the current state.
    void setState(State* newState) {
        if (currentState != nullptr) {
            delete currentState;
        }
        
        currentState = newState;
        if (currentState != nullptr) {
            light = currentState->out();
        }
    }
    
    /// Updates this StateContext's current state
    void update(int input) {
        if (currentState != nullptr) {
            currentState->onUpdate(input, this);
        }
    }
    
    /// The destructor for this class, which frees up the memory allocated for `currentState`
    ~StateContext() {
        delete currentState;
    }
    
private:
    State* currentState = nullptr;
};

}

#endif /* StateContext_hpp */
