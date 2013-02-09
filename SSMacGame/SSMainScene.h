//
//  MainScene.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__MainScene__
#define __SSMacGame__MainScene__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>
#include "SSGun.h"

class SSMainScene : public SoftShoe::GameEngine::Scene {
public:
    SSMainScene();
    ~SSMainScene();
    
    // Overrides
    void Render();
    
    
private:
    SSGun gun;
};

#endif /* defined(__SSMacGame__MainScene__) */
