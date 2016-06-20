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
    glTranslated(center.x,center.y,center.z);
    fleche->draw_model();
}

Ciel::Ciel(Point p){
}

void Ciel::render(){

    GLuint texture1 = loadTexture("models/Skybox/top.png" );
    GLuint texture2 = loadTexture("models/Skybox/back.png");
    GLuint texture3 = loadTexture("models/Skybox/front.png" );
    GLuint texture4 = loadTexture("models/Skybox/left.png");
    GLuint texture5 = loadTexture("models/Skybox/right.png" );
    GLuint texture6 = loadTexture("models/Skybox/bottom.png");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

//    Face pour le haut
    glBindTexture(GL_TEXTURE_2D, texture1);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
    glEnd();

    //Face pour le bas
    glBindTexture(GL_TEXTURE_2D, texture6);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,1);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
    glEnd();

    //Face pour le devant
    glBindTexture(GL_TEXTURE_2D, texture5);
        glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,1);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
    glEnd();

    //Face de gauche
    glBindTexture(GL_TEXTURE_2D, texture5);
        glBegin(GL_QUADS);
        glTexCoord2d(1,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
    glEnd();

    //Face de droite
    glBindTexture(GL_TEXTURE_2D, texture2);
        glBegin(GL_QUADS);
        glTexCoord2d(1,1);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,1);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
    glEnd();

    //Face de derrière
    glBindTexture(GL_TEXTURE_2D, texture5);
        glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(1,1);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    //glDisable(GL_DEPTH_TEST);
}
