#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "environnement.h"
#include "sdlglutils.h"

#include <fstream>
#include <iostream>
using namespace std;

void Sol::render(){
    glBegin(GL_QUADS);
    {
        // 1er face
        glColor3f(1, 0, 0);
        glVertex3i(SIZE_PLAN_WIDTH, 0, SIZE_PLAN_LENGTH);
        glColor3f(1, 0, 1);
        glVertex3i(SIZE_PLAN_WIDTH, 0, -SIZE_PLAN_LENGTH);
        glColor3f(0, 0, 1);
        glVertex3i(-SIZE_PLAN_WIDTH, 0, -SIZE_PLAN_LENGTH);
        glColor3f(1, 0, 0);
        glVertex3i(-SIZE_PLAN_WIDTH, 0, SIZE_PLAN_LENGTH);
    }
    glEnd();

}

Fleche::Fleche(Point p){
    fleche = new MeshObj("models/arrow/arrow.obj");
    center = p;
}

void Fleche::render(){
    glScaled(2,2,2);
    glTranslated(0,0,3);
    fleche->draw_model();
}

Ciel::Ciel(Point p){
}

void Ciel::render(){

    GLuint texture = loadTexture("models/Skybox/top.png" );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(1,1,1);
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1);
        glTexCoord2d(1,0);
        glVertex3d(-1,1,-1);
        glTexCoord2d(1,1);
        glVertex3d(-1,1,1);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}
