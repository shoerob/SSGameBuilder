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
#include "Director.h"

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

void TileMap::Update(Director &director, int timePassed) {
    xHighlight = director.InputServiceInstance().mouseX / 16;
    yHighlight = director.InputServiceInstance().mouseY / 16;
}

void TileMap::Render() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    for (int y = 0; y < yCnt; y++) {
        for (int x = 0; x < xCnt; x++) {
                glVertex2i(x * tileWidth, y * tileHeight);
                glVertex2i(x * tileWidth + tileWidth, y * tileHeight);
                glVertex2i(x * tileWidth + tileWidth, y * tileHeight + tileHeight);
            }
    }
    glEnd();
    
    glPushMatrix();
    glColor3f(0.5f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(xHighlight * tileWidth, yHighlight * tileHeight);
    glVertex2f(xHighlight * tileWidth + tileWidth, yHighlight * tileHeight);
    glVertex2f(xHighlight * tileWidth + tileWidth, yHighlight * tileHeight + tileHeight);
    glVertex2f(xHighlight * tileWidth + tileWidth, yHighlight * tileHeight + tileHeight);
    glVertex2f(xHighlight * tileWidth, yHighlight * tileHeight + tileHeight);
    glVertex2f(xHighlight * tileWidth, yHighlight * tileHeight);
    glEnd();
    glPopMatrix();
}