#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include "forms.h"


using namespace std;


Sphere::Sphere(Point c, double r, Color cl)
{
    center = c;
    radius = r;
    col = cl;
}


void Sphere::render()
{
    GLUquadric *quad;

    quad = gluNewQuadric();
    glTranslated(center.x,center.y,center.z);
//    glRotated(anim.getAngle(), 1,1,1);
    glTranslated(anim.getAngle(),anim.getAngle(),anim.getAngle());
    // Complete this part
    {
        glColor3f(col.r,col.g,col.b);
        gluSphere(quad,radius,20,20);
    }

    gluDeleteQuadric(quad);
}
