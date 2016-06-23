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


Fleche::Fleche(Point p){
    fleche = new MeshObj("models/arrow.obj");
    center = p;
}

void Fleche::updateForm(double delta_t) {

}

void Fleche::render(){
    glScaled(2,2,2);
    glTranslated(center.x,center.y,center.z);
    glRotated(angleX,1,0,0);
    glRotated(angleY,0,0,1);
    fleche->draw_model();
}

Ciel::Ciel(Point p){
}

void Ciel::updateForm(double delta_t) {

}

void Ciel::render(){

    glTranslated(0,DISTANCE_SKYBOX,0);

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
        glTexCoord2d(0,15);
        glVertex3d(DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(0,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,DISTANCE_SKYBOX);
        glTexCoord2d(15,0);
        glVertex3d(-DISTANCE_SKYBOX,-DISTANCE_SKYBOX,-DISTANCE_SKYBOX);
        glTexCoord2d(15,15);
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
    glColor3f(1,1,1);
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

    //Choix du rendu de la cible suivant si elle est touché ou non
    if( touche){
        glBindTexture(GL_TEXTURE_2D, texture2);
    }
    else{
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glColor3f(1,1,1);
    glTranslated(center.x,center.y,center.z);
    // Face avant
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

    // Face arrière
    glBegin(GL_QUADS);
        glVertex3d(-taille,taille,taille+1);
        glVertex3d(taille,taille,taille+1);
        glVertex3d(taille,-taille,taille+1);
        glVertex3d(-taille,-taille,taille+1);
    glEnd();

    // Face gauche
    glBegin(GL_QUADS);
        glVertex3d(taille,taille,taille);
        glVertex3d(taille,taille,taille+1);
        glVertex3d(taille,-taille,taille+1);
        glVertex3d(taille,-taille,taille);
    glEnd();

    // Face droite
    glBegin(GL_QUADS);
        glVertex3d(-taille,taille,taille);
        glVertex3d(-taille,taille,taille+1);
        glVertex3d(-taille,-taille,taille+1);
        glVertex3d(-taille,-taille,taille);
    glEnd();

    // Face haute
    glBegin(GL_QUADS);
        glVertex3d(taille,taille,taille);
        glVertex3d(taille,taille,taille+1);
        glVertex3d(-taille,taille,taille+1);
        glVertex3d(-taille,taille,taille);
    glEnd();

    // Face basse
    glBegin(GL_QUADS);
        glVertex3d(taille,-taille,taille);
        glVertex3d(taille,-taille,taille+1);
        glVertex3d(-taille,-taille,taille+1);
        glVertex3d(-taille,-taille,taille);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Cible::updateForm(double delta_t){

}
