#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "boule.h"


using namespace std;


Boule::Boule(Point c, double r)
{
    center = c;
    radius = r;
    ballon=new MeshObj("models/untitled.obj");
}


void Boule::render()
{

//    glTranslatef(center.x,center.y,center.z);
//    glScaled(0.5,0.5,0.5);
//    ballon->draw_model();

    glEnable(GL_TEXTURE_2D);

    GLUquadricObj *quadric = gluNewQuadric();
    glColor3f(1,1,1);
    gluQuadricTexture(quadric, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, loadTexture("models/Ball_15.jpg" ));
    gluSphere(quadric, radius, 32, 32);

    gluDeleteQuadric(quadric);
    glDisable(GL_TEXTURE_2D);

}
