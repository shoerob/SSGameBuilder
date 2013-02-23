//
//  SceneController.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/22/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "SceneController.h"
#include "Scene2.h"

using namespace SoftShoe::GameEngine;

SceneController::SceneController() {
    
}

SceneController::~SceneController() {
    
}

/**
 * Creates a new scene
 */
SceneController_ptr SceneController::create() {
    SceneController_ptr sceneController = std::make_shared<SceneController>();
//    sceneController->_scene = Scene2::create();
//    sceneController->_scene->setDelegate(sceneController);
    return sceneController;
}

Scene_ptr SceneController::getScene() {
    if (_scene == NULL) {
        _scene = Scene2::create();
        _scene->setDelegate(shared_from_this());
    }
    
    return _scene;
}

void SceneController::onLoad() {
    
}

void SceneController::onUpdate(int timePassed) {
    
}