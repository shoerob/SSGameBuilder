//
//  MainScene.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSMainScene.h"

SSMainScene::SSMainScene() : Scene() {
    this->AddActor(&gun);
    
    this->AddActor(&lamb);
    lamb.SetCenter(SSPointMake(4.0f, 0.0f, 10.0f));
    
    //this->AddActor(&explosion);
    //explosion.SetCenter(SSPointMake(0.0f, 0.0f, 100.0f));
}

SSMainScene::~SSMainScene() {
    
}

void SSMainScene::Update(Director &director, int timePassed) {
    Scene::Update(director, timePassed);
    
    
}

void SSMainScene::Render() {
    Scene::Render();
}