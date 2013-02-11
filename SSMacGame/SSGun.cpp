//
//  SSGun.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSGun.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#include "SSBullet.h"

SSGun::SSGun() {
    lastShotFiredTime = 0;
}

SSGun::~SSGun() {
    
}

void SSGun::Update(Director &director, int timePassed) {
    float xw = -(director.InputServiceInstance().mouseX - 360) * 1.5f / 75.0f;
    this->SetCenter(SSPointMake(xw, -3.5f, 10.0f));
    
    lastShotFiredTime += timePassed;
    
    // change to if mouse down
    if (director.InputServiceInstance().isMouseDown && lastShotFiredTime > 300) {
        lastShotFiredTime = 0;
        SSBullet *bullet = new SSBullet();
        bullet->SetCenter(this->GetCenter());
        this->GetScene()->AddActor(bullet);
    }
}

void SSGun::Render() {
    this->cube.render(this->GetCenter(), 0.3f);
}