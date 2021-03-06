//
//  ParticleSystem.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/27/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "ParticleSystem.h"

using namespace SoftShoe::GameEngine;

ParticleSystem::ParticleSystem() : Actor() {

}

ParticleSystem::~ParticleSystem() {

}

void ParticleSystem::Update(Director &director, int timePassed) {
    static SSColorRGBA color = SSColorMake(1.0f, 0.0f, 0.0f, 1.0f);
    static int colorCycle = 0;
    colorCycle++;
    if (colorCycle > 200) {
        color = SSColorMake(SSRandF(0.0f, 1.0f), SSRandF(0.0f, 1.0f), SSRandF(0.0f, 1.0f), 1.0f);
        colorCycle = 0;
    }
    
    
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        Particle &p = particles[i];
        
        if (p.life < 0) {
//            p.center.x = 0.0f;
//            p.center.y = -25.0f;
//            p.center.z = 0.0f;
            p.center = this->center;
            
            p.velocity.x = 0.0f;
            p.velocity.y = SSRandF(0.17f, 0.22f);
            p.velocity.z = 0.0f;
            
            p.acceleration.x = SSRandF(-0.0001, 0.0001);
            p.acceleration.y = -0.0004f;
            p.acceleration.z = SSRandF(-0.0001, 0.0001);
            
            p.life = rand() % 200;
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
}

void ParticleSystem::Render() {
    glPushMatrix();
    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        Particle &p = particles[i];
        if (p.life > 0) {
            cube.render(p.center, 0.5f, p.color);
        }
    }
    glPopMatrix();
}