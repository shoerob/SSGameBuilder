//
//  SSExplosion.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/10/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__SSExplosion__
#define __SSMacGame__SSExplosion__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>

class SSExplosion : public SoftShoe::GameEngine::ParticleSystem {
public:
    SSExplosion();
    ~SSExplosion();
    
    void Update(Director &director, int timePassed);
    void Render();
};


#endif /* defined(__SSMacGame__SSExplosion__) */
