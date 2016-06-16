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
//    text = texture;
}


void Boule::render()
{
    GLUquadric *quad;

    quad = gluNewQuadric();
    glTranslated(center.x,center.y,center.z);

    gluQuadricTexture(quad,GL_TRUE);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // Complete this part
    {
//        glColor3f(col.r,col.g,col.b);
        gluSphere(quad,radius,50,50);
    }
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quad);
}

SDL_Surface *loadImage(){
    SDL_Surface * loadedImage = NULL;
    SDL_Surface* zoomedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load("sun.png");
}
