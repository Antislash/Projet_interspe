#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "boule.h"
#include "animation.h"
#include <iostream>

using namespace std;


Boule::Boule(Point c, double r)
{
    center = c;
    radius = r;
    ballon=new MeshObj("models/untitled.obj");
}

void Boule::updateForm(double delta_t) {

    anim.integration_vit(delta_t);
    center = anim.getPos();
    cout << "x=" << center.x << endl;
    cout << "y=" << center.y << endl;
    cout << "z=" << center.z << endl;
}

void Boule::render()
{

//    glTranslatef(center.x,center.y,center.z);
//    glScaled(0.5,0.5,0.5);
//    ballon->draw_model();

    glEnable(GL_TEXTURE_2D);
    GLUquadricObj *quadric = gluNewQuadric();
    glColor3f(1,1,1);
    glTranslatef(center.x,center.y,center.z);
    gluQuadricTexture(quadric, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, loadTexture("models/Ball_15.jpg" ));
    gluSphere(quadric, radius, 32, 32);

    gluDeleteQuadric(quadric);
    glDisable(GL_TEXTURE_2D);

}
