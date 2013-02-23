//
//  Gun.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/23/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__Gun__
#define __SSMacGame__Gun__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>

namespace Game {
    class Gun : public SSObject {
    public:
        Gun();
        ~Gun();
        
        void render();
        
        void doSomething();
        
    private:
        SoftShoe::GameEngine::Cube cube;
    };
}

#endif /* defined(__SSMacGame__Gun__) */
