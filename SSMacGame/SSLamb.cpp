//
//  SSLamb.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/10/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSLamb.h"

SSLamb::SSLamb() {
    
}

SSLamb::~SSLamb() {
    
}

// Overrides
void SSLamb::Update(Director &director, int timePassed) {
    this->SetCenter(SSPointMake(this->GetCenter().x - 0.01f, this->GetCenter().y, 10.0f));
}

void SSLamb::Render() {
    cube.render(this->GetCenter(), 0.4f, SSColorMake(1.0f, 1.0f, 1.0f, 1.0f));
}