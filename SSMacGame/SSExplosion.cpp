//
//  SSExplosion.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/10/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSExplosion.h"

SSExplosion::SSExplosion() {
    
}

SSExplosion::~SSExplosion() {
    
}

void SSExplosion::Update(Director &director, int timePassed) {
    SSColorRGBA color = SSColorMake(SSRandF(0.0f, 1.0f), SSRandF(0.0f, 1.0f), SSRandF(0.0f, 1.0f), 1.0f);
    bool systemDone = true;
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        Particle &p = particles[i];
        
        if (p.life == 0) continue;
        systemDone = false;
        
        if (p.life < 0) {
            //            p.center.x = 0.0f;
            //            p.center.y = -25.0f;
            //            p.center.z = 0.0f;
            p.center = this->center;
            
            p.velocity.x = SSRandF(-0.05f, 0.05f);
            p.velocity.y = SSRandF(-0.05f, 0.05f);
            p.velocity.z = SSRandF(-0.05f, 0.05f);
            
            p.acceleration.x = 0.0f;//SSRandF(-0.0001, 0.0001);
            p.acceleration.y = 0.0f;//-0.0004f;
            p.acceleration.z = 0.0f;//SSRandF(-0.0001, 0.0001);
            
            p.life = (rand() % 50) + 150;
            p.color = color;
        }
        
        // Update Velocity
        p.velocity.x += p.acceleration.x * timePassed/3.0f;
        p.velocity.y += p.acceleration.y * timePassed/3.0f;
        p.velocity.z += p.acceleration.z * timePassed/3.0f;
        
        // Update Center
        p.center.x += p.velocity.x * timePassed/3.0f;
        p.center.y += p.velocity.y * timePassed/3.0f;
        p.center.z += p.velocity.z * timePassed/3.0f;
        
        // Update life
        p.life--;
        p.color.a = ((float)p.life) / 200.0f;
    }
    
    // stop rendering this system when it's done
    if (systemDone) {
        this->SetVisible(false);
    }
}

void SSExplosion::Render() {
    glPushMatrix();
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        Particle &p = particles[i];
        cube.render(p.center, 0.05f, p.color);
    }
    glPopMatrix();
}