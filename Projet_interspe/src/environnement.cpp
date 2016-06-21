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

    glTranslatef(center.x,center.y,center.z);
    glScaled(1,1,1);
    terrain->draw_model();
}

void Sol::updateForm(double delta_t){

}

Sol::Sol(Point p){

    center = p;
    terrain = new MeshObj("models/mount.blend1.obj");
}

Fleche::Fleche(Point p){
    fleche = new MeshObj("models/arrow/arrow.obj");
    center = p;
}

void Fleche::updateForm(double delta_t){

}

void Fleche::render(){
    glScaled(2,2,2);
    glTranslated(center.x,center.y,center.z);
    fleche->draw_model();
}

Ciel::Ciel(Point p){
}

void Ciel::updateForm(double delta_t) {

}

void Ciel::render(){

    glTranslated(0,DISTANCE_SKYBOX,0);
    GLuint texture1 = loadTexture("models/Skybox3/top.jpg" );
    GLuint texture2 = loadTexture("models/Skybox3/back.jpg");
    GLuint texture3 = loadTexture("models/Skybox3/front.jpg" );
    GLuint texture4 = loadTexture("models/Skybox3/left.jpg");
    GLuint texture5 = loadTexture("models/Skybox3/right.jpg" );
    GLuint texture6 = loadTexture("models/Skybox3/bottom.jpg");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

//    Face pour le haut
    glBindTexture(GL_TEXTURE_2D, texture1);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2d(1,1);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,1);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(-DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(1,0);
        glVertex3d(DISTANCE_SKYBOX,DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
    glEnd();

    //Face pour le bas
    glBindTexture(GL_TEXTURE_2D, texture6);
    glTexParameteri(GL_TEXTURE_2D, texture6, GL_REPEAT);
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
    glBindTexture(GL_TEXTURE_2D, texture3);
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
    glBindTexture(GL_TEXTURE_2D, texture4);
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
    glBindTexture(GL_TEXTURE_2D, texture5);
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
    glBindTexture(GL_TEXTURE_2D, texture2);
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

void Cible::render(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

//    Face pour le haut
    glBindTexture(GL_TEXTURE_2D, loadTexture("models/cible.jpg"));
    glColor3f(1,1,1);
    glTranslated(center.x,center.y,center.z);
    glBegin(GL_QUADS);
        glTexCoord2d(1,1);
        glVertex3d(-taille,taille,taille);
        glTexCoord2d(0,1);
        glVertex3d(taille,taille,taille);
        glTexCoord2d(0,0);
        glVertex3d(taille,-taille,taille);
        glTexCoord2d(1,0);
        glVertex3d(-taille,-taille,taille);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Cible::updateForm(double delta_t){

}
