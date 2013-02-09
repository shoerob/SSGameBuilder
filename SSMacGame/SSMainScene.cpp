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
}

SSMainScene::~SSMainScene() {
    
}

void SSMainScene::Render() {
    Scene::Render();
}