//
//  SSBullet.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/9/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__SSBullet__
#define __SSMacGame__SSBullet__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>

class SSBullet : public SoftShoe::GameEngine::Actor {
public:
    SSBullet();
    ~SSBullet();
    
    // Overrides
    void Update(Director &director, int timePassed);
    void Render();
    
    // Collision
    SSRectF GetCollisionRect() { return SSRectMake(this->GetCenter().x, this->GetCenter().y, 0.3f, 0.3f); };
    void CollidedWith(Actor *actor);
    
private:
    Cube cube;
    
};

#endif /* defined(__SSMacGame__SSBullet__) */
