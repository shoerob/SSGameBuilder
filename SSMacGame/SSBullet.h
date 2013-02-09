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
    
private:
    Cube cube;
};

#endif /* defined(__SSMacGame__SSBullet__) */
