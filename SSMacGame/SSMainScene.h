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
#include "SSLamb.h"
#include "SSExplosion.h"

class SSMainScene : public SoftShoe::GameEngine::Scene, public INotificationSubscriber {
public:
    SSMainScene();
    ~SSMainScene();
    
    // Overrides
    virtual void OnNotificationReceived(std::string notificationName);
    void Update(Director &director, int timePassed);
    void Render();
    
    // Level Setup
    void StartWave1();
    
private:
    SSGun gun;
    SSLamb lamb[3];
    SSExplosion explosion;
    
    // Wave Management
    int currWave = 0;
    int currWaveTime = 0;
};

#endif /* defined(__SSMacGame__MainScene__) */
