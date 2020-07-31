//
//  main.cpp
//  statemachine
//
//  Created by Richard Robinson on 2020-07-22.
//

#include <iostream>
#include "StateContext.hpp"
#include "LegacyStateContext.hpp"
#include "States.hpp"
#include <random>

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 3);

/**
 * {@code
 * N  |   Name    Lights   Time   In=0    In=1    In=2    In=3
 * -  |  -----    ------   ----   ----   -----   -----   -----
 * 0  |    goN      0x11     30    goN   waitN     goN   waitN
 * 1  |  waitN      0x22     05    goE     goE     goE     goE
 * 2  |    goE      0x0C     30    goE     goE   waitE   waitE
 * 3  |  waitE      0X14     05    goN     goN     goN     goN
 * }
*/
int main(int argc, const char * argv[]) {
    auto new_context = Modern::StateContext(new Modern::GoNState());
    auto old_context = Legacy::StateContext(Legacy::GO_N);
    
    std::cout << std::hex;
    
    while (true) {
        auto random = distr(gen);
        
        std::cout << "input = 0x" << random << "\n";
        std::cout << "new_context light = 0x" << new_context.light << "\n";
        std::cout << "old_context light = 0x" << old_context.light << "\n";
        std::cout << "\n";
        
        new_context.update(random);
        old_context.update(random);
    }
        
    return 0;
}
