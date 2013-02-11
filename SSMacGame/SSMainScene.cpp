//
//  MainScene.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSMainScene.h"

SSMainScene::SSMainScene() : Scene(), INotificationSubscriber() {
    this->AddActor(&gun);
    for (int i = 0; i < 3; i++) {
        this->AddActor(&lamb[i]);
    }
    
//    this->AddActor(&lamb[0]);
//    lamb[0].SetCenter(SSPointMake(4.0f, 0.0f, 10.0f));
    
    //this->AddActor(&explosion);
    //explosion.SetCenter(SSPointMake(0.0f, 0.0f, 100.0f));
}

SSMainScene::~SSMainScene() {
    
}

void SSMainScene::Update(Director &director, int timePassed) {
    Scene::Update(director, timePassed);
    
    if (currWave == 0) {
        this->StartWave1();
    }
    
    currWaveTime += timePassed;
    
}

void SSMainScene::Render() {
    Scene::Render();
}

void SSMainScene::StartWave1() {
    currWave = 1;
    
    for (int i = 0; i < 3; i++) {
        lamb[i].StartFromLeft(rand() % 5000);
    }
}

void SSMainScene::OnNotificationReceived(std::string notificationName) {
    if (notificationName == "LAMB_ESCAPED") {
        std::cout << "Lamb escaped!!";
    }
}