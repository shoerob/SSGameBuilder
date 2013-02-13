//
//  SSLamb.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/10/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSLamb.h"
#include "SSBullet.h"
#include "SSExplosion.h"

SSLamb::SSLamb() {
    this->SetCollides(true);
}

SSLamb::~SSLamb() {
    
}

// Overrides
void SSLamb::Update(Director &director, int timePassed) {
    if (!isActive) return;
    
    // explode!!!
    if (isDead) {
        SSExplosion *explosion = new SSExplosion();
        explosion->SetCenter(SSPointMake(this->GetCenter().x, this->GetCenter().y, this->GetCenter().z));
        this->GetScene()->AddActor(explosion);
        
        
        isActive = false;
        return;
    }
    
    this->waitMs -= timePassed;
    
    if (this->waitMs <= 0) {
        this->SetCenter(SSPointMake(this->GetCenter().x - 0.01f, this->GetCenter().y, 10.0f));
        
        // detect if this lamb escaped
        if (this->GetCenter().x < -4.0f) {
            director.NotificationServiceInstance().SendNotification("LAMB_ESCAPED");
            isActive = false;
        }
    }
}

void SSLamb::Render() {
    cube.render(this->GetCenter(), 0.4f, SSColorMake(1.0f, 1.0f, 1.0f, 1.0f));
}

void SSLamb::StartFromLeft(int waitMs) {
    this->isActive = true;
    this->SetCenter(SSPointMake(4.0f, SSRandF(-2.0f, 3.5f), 10.0f));
    this->waitMs = waitMs;
}

void SSLamb::CollidedWith(Actor *actor) {
    SSBullet *bullet = dynamic_cast<SSBullet *>(actor);
    if (bullet != NULL) {
        this->SetCollides(false);
        this->SetVisible(false);
        this->isDead = true;
    }
}