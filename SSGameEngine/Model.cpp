//
//  Model.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/30/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "Model.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace SoftShoe::GameEngine;
using namespace std;

Model::Model() {
    this->LoadSimpleModel();
}

Model::~Model() {
    
}

void Model::LoadSimpleModel() {
    string line;
    ifstream modelFile;
    int indexRows = 0;
    int vertexRows = 0;
    
    modelFile.open("/Users/shoemate/Source/SSGameBuilder/DerivedData/SSGameBuilder/Build/Products/Debug/teapot");
    if (modelFile.is_open()) {
        if (modelFile.good()) {
            // bleh
        }
        
        // Indeces
        getline(modelFile, line);
        indexRows = atoi(line.c_str());
        indecesCount = indexRows * 16;

        // Index array
        indeces = new GLuint[indecesCount];
        int currIndex = 0;
        for (int i = 0; i < indexRows; i++) {
            getline(modelFile, line);
            string lineDel;
            stringstream stream(line);
            while (getline(stream, lineDel, ',')) {
                indeces[currIndex] = (GLuint) atoi(lineDel.c_str());
                currIndex++;
            }
        }
        
        getline(modelFile, line);
        vertexRows = atoi(line.c_str());
        verticesCount = vertexRows * 3;
        vertices = new GLfloat[verticesCount];
        currIndex = 0;
        for (int i = 0; i < vertexRows; i++) {
            getline(modelFile, line);
            //            cout << line << "\n";
            string lineDel;
            stringstream stream(line);
            while (getline(stream, lineDel, ',')) {
                vertices[currIndex] = atof(lineDel.c_str()) * 5.0f;
                currIndex++;
            }
        }
    }
}


/*
 
 * Calculates a Bezier curve directly by iterating along the curve
 
 * for the desired number of steps.
 
 *
 
 * Point is an object that has the x, y, and z coordinates and defines
 
 * some mathematical operations for points. See the project accompanying
 
 * the article for its definition.
 
 *
 
 * G is the geometry vector, the three control points for the curves.
 
 * steps is the number of steps to take along the curve.
 
 */
static float angle = 0.0f;
void QuadraticBezierIterate(SSPoint3F G[], int steps) {
    
    float stepSize = 1.0 / steps;
    
    float t = stepSize;
    
    float s = 1.0f;
    
    // Draw the curve as a line strip
    
    glBegin(GL_LINE_STRIP);
    
    // First control point is on the curve
    
    glVertex3f(G[0].x * s, G[0].y * s, G[0].z * s);
    
    // Calculate intermediate points
    
    for(int step = 1; step < steps; step++, t += stepSize) {
        
        // Calculate the blending functions
        
        float b0 = (1 - t) * (1 - t);
        
        float b1 = 2.0 * t * (1 - t);
        
        float b2 = t * t;
        
        // Blend
        
        float x = b0 * G[0].x + b1 * G[1].x + b2 * G[2].x;
        
        float y = b0 * G[0].y + b1 * G[1].y + b2 * G[2].y;
        
        float z = b0 * G[0].z + b1 * G[1].z + b2 * G[2].z;
        
        // Emit a vertex
        
        glVertex3f(x * s, y * s, z * s);
        
    }
    
    // Last control point is on the curve
    
    glVertex3f(G[2].x * s, G[2].y * s, G[2].z * s);
    
    glEnd();
    
}

/*

* Calculates a Bezier curve using subdivision to the desired depth.

*

* Point is an object that has the x, y, and z coordinates and defines

* some mathematical operations for points. See the project accompanying

* the article for its definition.

*

* G is the geometry vector, the three control points for the curves.

* level is the depth to subdivide.

*/

void QuadraticBezierSubdivide(SSPoint3F G[], int level) {
    
    // Draw a line if level 0 using the end points
    
    if(level == 0) {
        
        glBegin(GL_LINES);
        
        glVertex3f(G[0].x, G[0].y, G[0].z);
        
        glVertex3f(G[2].x, G[2].y, G[2].z);
        
        glEnd();
        
        return;
        
    }
    
    // New geometry vectors for the left and right halves of the curve
    
    SSPoint3F Gl[3];
    
    SSPoint3F Gr[3];
    
    
    
    // Subdivide
    
    Gl[0] = G[0];
    
    //Gl[1] = (G[0] + G[1]) * 0.5f;
    Gl[1].x = (G[0].x + G[1].x) * 0.5f;
    Gl[1].y = (G[0].y + G[1].y) * 0.5f;
    Gl[1].z = (G[0].z + G[1].z) * 0.5f;
    
//    Gr[1] = (G[1] + G[2]) * 0.5f;
    Gr[1].x = (G[1].x + G[2].x) * 0.5f;
    Gr[1].y = (G[1].y + G[2].y) * 0.5f;
    Gr[1].z = (G[1].z + G[2].z) * 0.5f;
    
//    Gl[2] = Gr[0] = (Gl[1] + Gr[1]) * 0.5f;
    Gl[2].x = Gr[0].x = (Gl[1].x + Gr[1].x) * 0.5f;
    Gl[2].y = Gr[0].y = (Gl[1].y + Gr[1].y) * 0.5f;
    Gl[2].z = Gr[0].z = (Gl[1].z + Gr[1].z) * 0.5f;
    
    Gr[2] = G[2];
    
    // Call recursively for left and right halves
    
    QuadraticBezierSubdivide(Gl, --level);
    
    QuadraticBezierSubdivide(Gr, level);
    
}


GLfloat ctrlpoints[4][4][3] = {
    {{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0},
        {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}},
    {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0},
        {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}},
    {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0},
        {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}},
    {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0},
        {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
};

// Overrides
void Model::render(SSPoint3F center, float scale) {
///// BEZIER PATCHES
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
//            0, 1, 12, 4, &ctrlpoints[0][0][0]);
//    glEnable(GL_MAP2_VERTEX_3);
//    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
//    //glEnable(GL_DEPTH_TEST);
//    //glShadeModel(GL_FLAT);
//    
//    glPushMatrix ();
//    glColor3f(1.0, 1.0, 1.0);
//    glRotatef(85.0, 1.0, 1.0, 1.0);
//    for (int j = 0; j <= 8; j++) {
//        glBegin(GL_LINE_STRIP);
//        for (int i = 0; i <= 30; i++)
//            glEvalCoord2f((GLfloat)i/30.0, (GLfloat)j/8.0);
//        glEnd();
//        glBegin(GL_LINE_STRIP);
//        for (int i = 0; i <= 30; i++)
//            glEvalCoord2f((GLfloat)j/8.0, (GLfloat)i/30.0);
//        glEnd();
//    }
//    glPopMatrix ();
    
    

/// BEZIER LINES
    glPushMatrix();
    angle += 50.0f;
    glRotatef(angle * 3.14/180, angle * 3.14/180, angle * 3.14/180, 0.0f);
    for (int i = 0; i < indecesCount-3; i+=1) {
        GLuint index0 = indeces[i + 0];
        GLuint index1 = indeces[i + 1];
        GLuint index2 = indeces[i + 2];
        
        SSPoint3F points[3];
        points[0] = SSPointMake(vertices[(index0-1)*3], vertices[(index0-1)*3+1], vertices[(index0-1)*3+2]);
        points[1] = SSPointMake(vertices[(index1-1)*3], vertices[(index1-1)*3+1], vertices[(index1-1)*3+2]);
        points[2] = SSPointMake(vertices[(index2-1)*3], vertices[(index2-1)*3+1], vertices[(index2-1)*3+2]);
    
        QuadraticBezierIterate(points, 2);
    }
    glPopMatrix();

    //////
    
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_FLOAT, 0, vertices);
//    
//    glPushMatrix();
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glTranslatef(0.0f, 0.0f, 0.0f);
//    glRotatef(angle * 3.14/180, angle * 3.14/180, angle * 3.14/180, 0.0f);
//    angle+=50.0f;
//    
//    glDrawElements(GL_POINTS, indecesCount, GL_UNSIGNED_INT, indeces);
//    glPopMatrix();
//    glDisableClientState(GL_VERTEX_ARRAY);
}

void Model::render(SSPoint3F center, float scale, SSColorRGBA color) {

}
