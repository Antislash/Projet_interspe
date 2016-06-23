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

//Constructeur
Boule::Boule(Point c, double r)
{
    center = c;
    radius = r;
    angle = 0;
    puissance = 0;
    touche = false;
    texture = loadTexture("models/Ball/Ball_base.jpg" );
    toucheSol = false;
    inversementRot = false;
}

void Boule::updateForm(double delta_t) {

}

//Déplacement de la boule + Vérification des impacts
void Boule::updateForm(double delta_t, Cible* cibles, int nb_cibles) {

    if(toucheSol){
        anim.touche_sol();
        anim.integration_vit(delta_t);
        center = anim.getPos();
        center.y = 0.5;
    }

    else if(center.y > 0.5 && !touche){

        Vector t = check_Impact_mur(cibles[1]);
        if (touche) {
            anim.vit_collision(delta_t, t);
            inversementRot = true;
        }
        for (int i = 0; i < nb_cibles; i++) {

            Vector N = check_Impact_cible(cibles[i]);

            if (touche) {
                cibles[i].setTouche(true);
                anim.vit_collision(delta_t, N);
                inversementRot = true;
            }
        }

        if (!touche)
        {
            anim.integration_acc(delta_t);
        }

        anim.integration_vit(delta_t);

        center = anim.getPos();

        inversementRot ? angle -= 10 : angle += 10;
    }
    else{
        toucheSol = true;
        center.y = 0.5;
    }
}

//Rendu de la boule
void Boule::render()
{

    glEnable(GL_TEXTURE_2D);

    GLUquadricObj *quadric = gluNewQuadric();
    glColor3f(1,1,1);
    glTranslatef(center.x,center.y,center.z);

    glRotated(angle, 1,0,0);
    gluQuadricTexture(quadric, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, texture);
    gluSphere(quadric, radius, 32, 32);

    gluDeleteQuadric(quadric);
    glDisable(GL_TEXTURE_2D);

    //Pour dessinner la jauge de puissance
    if( puissance != 0)
    {
        glColor3f(0,1,0);
        glBegin(GL_QUADS);
        glVertex3d(-0.5,0,0);
        glVertex3d(-0.6,0,0);
        glColor3f(1,0,0);
        glVertex3d(-0.6,puissance/50,0);
        glVertex3d(-0.5,puissance/50,0);
        glEnd();
    }

}

//Calcul si il y a impact avec une cible
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

//Calcul si il y a impact avec le mur du fond
Vector Boule::check_Impact_mur(Cible cible)
{


    Vector V1 = Vector(cible.getCenter().x - cible.getTaille() +1  - cible.getCenter().x - cible.getTaille(), 0.0, 0.0);
    Vector V2 = Vector(0.0, cible.getCenter().y - cible.getTaille() +1  - cible.getCenter().y - cible.getTaille(), 0.0);

    Vector N = V1^V2;

    double toto = 1.0/N.norm();
    N = toto*N;

    Point P = Point(-DISTANCE_SKYBOX, 0, DISTANCE_SKYBOX);
    Point C = center;
    Vector PC = Vector(P,C);

    Vector Vect_Impact = (-(N*PC))*N;

    // Calcul de la coordonnée de l'impact

    Point Impact;

    Impact.x = center.x+Vect_Impact.x;
    Impact.y = center.y+Vect_Impact.y;
    Impact.z = center.z+Vect_Impact.z;

    if ((Vect_Impact.norm()<=radius)&&(Impact.x>-DISTANCE_SKYBOX)&&(Impact.x<DISTANCE_SKYBOX)&&(Impact.y>0)&&(Impact.y<2*DISTANCE_SKYBOX))
    {
        touche = true;
        return N;
    }

    touche = false;
    return N;
}

//Permet de changer l'apparence de la boule
void Boule::setTexture(int text){
    switch(text){
        case 1 : texture = loadTexture("models/Ball/Ball_15.jpg");
            break;
        case 2 : texture = loadTexture("models/Ball/Ball_boulet_canon.jpg");
            break;
        case 3 : texture = loadTexture("models/Ball/Ball_base.jpg");
            break;
        case 4 : texture = loadTexture("models/Ball/ball_colors.jpg");
            break;
        case 5 : texture = loadTexture("models/Ball/ball_fractal.jpg");
            break;
    }
}
