//
//  SSLamb.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/10/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__SSLamb__
#define __SSMacGame__SSLamb__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>

class SSLamb : public SoftShoe::GameEngine::Actor {
public:
    SSLamb();
    ~SSLamb();
    
    // Overrides
    void Update(Director &director, int timePassed);
    void Render();
    
    // Setup
    void StartFromLeft(int waitMs);
    
    // Collision
    SSRectF GetCollisionRect() { return SSRectMake(this->GetCenter().x, this->GetCenter().y, 0.3f, 0.3f); };
    void CollidedWith(Actor *actor);
    
private:
    Cube cube;
    bool isActive = false;
    int waitMs; // amount of time to wait before appearing
    
    bool isDead = false;
    
};

#endif /* defined(__SSMacGame__SSLamb__) */
