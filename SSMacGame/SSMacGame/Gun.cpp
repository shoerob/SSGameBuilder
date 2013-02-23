//
//  Gun.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/23/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "Gun.h"

using namespace Game;

Gun::Gun() : SSObject(1) {
    
}

Gun::~Gun() {
    
}

void Gun::render() {
    glPushMatrix();
    
    cube.render(SSPointMake(0.0f, 0.0f, 5.0f), 1.0f);
    glPopMatrix();

}


void Gun::doSomething() {

}