//
//  SSBullet.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/9/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSBullet.h"

SSBullet::SSBullet() {
    
}

SSBullet::~SSBullet() {
    
}

// Overrides
void SSBullet::Update(Director &director, int timePassed) {
    this->SetCenter(SSPointMake(this->GetCenter().x, this->GetCenter().y + 0.20, 10.0f));
}

void SSBullet::Render() {
    cube.render(this->GetCenter(), 0.1f, SSColorMake(0.0f, 1.0f, 0.0f, 1.0f));
}