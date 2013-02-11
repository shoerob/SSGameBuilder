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
    
private:
    Cube cube;
    
};

#endif /* defined(__SSMacGame__SSLamb__) */
