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
//    text = texture;
}


void Boule::render()
{

    glTranslatef(0,0,0);
    glScaled(0.5,0.5,0.5);
    ballon->draw_model();


}
