#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "boule.h"
#include "environnement.h"
#include "animation.h"
#include <iostream>

using namespace std;


Boule::Boule(Point c, double r)
{
    center = c;
    radius = r;
    angle = 0;
    puissance = 0;
    touche = 0;
}

void Boule::updateForm(double delta_t) {

    if(touche){
        center.y = 0.5;
    }
    else if(center.y > 0.5 && !touche){
        anim.integration_vit(delta_t);
        center = anim.getPos();
        angle += 30;
    }
    else{
        touche = true;
    }

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
    //cout << "angle = " << angle << endl;
    glRotated(angle, 1,0,0);
    gluQuadricTexture(quadric, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, loadTexture("models/Ball_15.jpg" ));
    gluSphere(quadric, radius, 32, 32);

    gluDeleteQuadric(quadric);
    glDisable(GL_TEXTURE_2D);

    if( puissance != 0)
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex3d(-0.5,0,0);
        glVertex3d(-0.6,0,0);
        glColor3f(0,1,0);
        glVertex3d(-0.6,puissance/50,0);
        glVertex3d(-0.5,puissance/50,0);
        glEnd();
    }

}

