#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "boule.h"
#include "environnement.h"
#include "animation.h"
#include "geometry.h"
#include <iostream>

using namespace std;


Boule::Boule(Point c, double r)
{
    center = c;
    radius = r;
    angle = 0;
    puissance = 0;
    touche = false;
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


void Boule::updateForm(double delta_t, Cible* cibles, int nb_cibles) {

    if(toucheSol){
        center.y = 0.5;
    }
    else if(center.y > 0.5 && !touche){

        for (int i = 0; i < nb_cibles; i++) {

            Vector N = check_Impact_cible(cibles[i]);

            if (touche) {
                center.x += 15;
                anim.vit_collision(delta_t, N);
            }
        }

        if (!touche)
        {
            //cout << "passe2" << endl;
            anim.integration_acc(delta_t);
        }

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

Vector Boule::check_Impact_cible(Cible cible)
{

    Vector V1 = Vector(cible.getCenter().x - cible.getTaille() +1  - cible.getCenter().x - cible.getTaille(), 0.0, 0.0);
    Vector V2 = Vector(0.0, cible.getCenter().y - cible.getTaille() +1  - cible.getCenter().y - cible.getTaille(), 0.0);

    Vector N = V1^V2;

    double toto = 1.0/N.norm();
    N = toto*N;

    Point P = Point(cible.getCenter().x, cible.getCenter().y - cible.getTaille(), cible.getCenter().z + 4);
    Point C = center;
    Vector PC = Vector(P,C);

    Vector Vect_Impact = (-(N*PC))*N;

    // Calcul de la coordonnée de l'impact

    Point Impact;

    Impact.x = center.x+Vect_Impact.x;
    Impact.y = center.y+Vect_Impact.y;
    Impact.z = center.z+Vect_Impact.z;

    if ((Vect_Impact.norm()<=radius)&&(Impact.x>cible.getCenter().x-cible.getTaille())&&(Impact.x<cible.getCenter().x+cible.getTaille())&&(Impact.y>cible.getCenter().y-cible.getTaille())&&(Impact.y<cible.getCenter().y+cible.getTaille()))
    {
        touche = true;
        return N;
    }

    touche = false;
    return N;
}

