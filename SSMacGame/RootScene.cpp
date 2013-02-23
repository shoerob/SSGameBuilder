//
//  RootScene.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/23/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "RootScene.h"

using namespace Game;

RootScene::RootScene() : SceneController() {
    
}

RootScene::~RootScene() {
    
}

void RootScene::onLoad() {
    gun = std::make_shared<Gun>();
    this->getScene()->addObject(gun);
}

void RootScene::onUpdate(int timePassed) {
    gun->doSomething();
}