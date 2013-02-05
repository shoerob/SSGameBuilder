//
//  TileMap.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/4/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "TileMap.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

using namespace SoftShoe::GameEngine;

TileMap::TileMap() {
    
}

TileMap::~TileMap() {
    
}

void TileMap::Setup(int tileWidth, int tileHeight, int xCnt, int yCnt) {
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    this->xCnt = xCnt;
    this->yCnt = yCnt;
}

void TileMap::Update(int timePassed) {
    
}

void TileMap::Render() {
    glBegin(GL_POINTS);
    for (int x = 0; x < xCnt; x++) {
        for (int y = 0; y < yCnt; y++) {
            glVertex2i(x * tileWidth, y * tileHeight);
        }
    }
    glEnd();
}