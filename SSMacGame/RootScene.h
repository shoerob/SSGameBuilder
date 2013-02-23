//
//  RootScene.h
//  SSMacGame
//
//  Created by Robert Shoemate on 2/23/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#ifndef __SSMacGame__RootScene__
#define __SSMacGame__RootScene__

#include <iostream>
#include <SSGameEngine/SSGameEngine.h>
#include "Gun.h"

namespace Game {
    class RootScene : public SoftShoe::GameEngine::SceneController {
    public:
        RootScene();
        ~RootScene();
        
        void onLoad();
        void onUpdate(int timePassed);
        
    private:
        std::shared_ptr<Gun> gun;
    };
    
    typedef std::shared_ptr<RootScene> RootScene_ptr;
}



#endif /* defined(__SSMacGame__RootScene__) */
