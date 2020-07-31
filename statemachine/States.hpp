//
//  States.hpp
//  statemachine
//
//  Created by Richard Robinson on 2020-07-31.
//

#ifndef States_hpp
#define States_hpp

#include <stdio.h>
#include "StateContext.hpp"

namespace Modern {

struct WaitNState: StateContext::State {
    int time = 50;
    
    int out() override {
        return 0x22;
    }
    
    void onUpdate(int input, StateContext *context) override;
};

struct WaitEState: StateContext::State {
    int time = 50;
    
    int out() override {
        return 0x14;
    }
    
    void onUpdate(int input, StateContext *context) override;
};

struct GoEState: StateContext::State {
    int time = 300;
    
    int out() override {
        return 0x0C;
    }
    
    void onUpdate(int input, StateContext *context) override;
};

struct GoNState: StateContext::State {
    int time = 300;
    
    int out() override {
        return 0x21;
    }
    
    void onUpdate(int input, StateContext *context) override;
};

}

#endif /* States_hpp */
