//
//  InputReceiver.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/5/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "InputService.h"

using namespace SoftShoe::Input;

InputService::InputService() {
    mouseX = 0;
    mouseY = 0;
}

InputService::~InputService() {
    
}

void InputService::MouseMoved(int x, int y) {
    mouseX = x;
    mouseY = y;
}