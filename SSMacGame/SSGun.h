//
//  SSGun.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__SSGun__
#define __SSMacGame__SSGun__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>

class SSGun : public SoftShoe::GameEngine::Actor {
public:
    SSGun();
    ~SSGun();
    
    // Overrides
    void Update(Director &director, int timePassed);
    void Render();
    
private:
    Cube cube;
};

#endif /* defined(__SSMacGame__SSGun__) */
