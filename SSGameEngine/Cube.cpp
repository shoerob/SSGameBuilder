//
//  Cube.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/25/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "Cube.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

using namespace SoftShoe::GameEngine;

Cube::Cube() : IPrimitive() {

}

Cube::~Cube() {
    
}

void Cube::render(SSPoint3F center, float scale) {
    this->render(center, scale, SSColorMake(1.0f, 0.0f, 0.0f, 1.0f));
}

void Cube::render(SSPoint3F center, float scale, SSColorRGBA color) {
    float s = scale;
    GLfloat vertices[] = {
        s, s, s,  -s, s, s,  -s,-s, s,   s,-s, s,   // v0,v1,v2,v3 (front)
        s, s, s,   s,-s, s,   s,-s,-s,   s, s,-s,   // v0,v3,v4,v5 (right)
        s, s, s,   s, s,-s,  -s, s,-s,  -s, s, s,   // v0,v5,v6,v1 (top)
        -s, s, s,  -s, s,-s,  -s,-s,-s,  -s,-s, s,   // v1,v6,v7,v2 (left)
        -s,-s,-s,   s,-s,-s,   s,-s, s,  -s,-s, s,   // v7,v4,v3,v2 (bottom)
        s,-s,-s,  -s,-s,-s,  -s, s,-s,   s, s,-s }; // v4,v7,v6,v5 (back)
    
    // index array of vertex array for glDrawElements() & glDrawRangeElement()
    GLubyte indices[]  = {
        0, 1, 2,   2, 3, 0,      // front
        4, 5, 6,   6, 7, 4,      // right
        8, 9,10,  10,11, 8,      // top
        12,13,14,  14,15,12,      // left
        16,17,18,  18,19,16,      // bottom
        20,21,22,  22,23,20 };    // back
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColor4f(color.r, color.g, color.b, color.a);
    
    glPushMatrix();
    glTranslatef(center.x, center.y, center.z);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY);
}