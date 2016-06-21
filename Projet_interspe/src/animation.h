#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include "geometry.h"


class Animation
{
private:
    double angle;
    Vector rot_vect;

public:
    Animation(double agl = 0.0, Vector vect = Vector(1.0, 0.0, 0.0)) {angle = agl; rot_vect = vect;}
    const double getAngle() {return angle;}
    void setAngle(double agl) {angle = agl;}
    const Vector getRotVect() {return rot_vect;}
    void setRotVect(Vector vect) {rot_vect = vect;}

    // Moez
    Vector integration_acc(Vector acc, Vector vit_ini);
    Vector integration_vit(Vector vit, Vector pos_ini);
    void update();

    Vector vit_ini;
    Vector pos_ini;
    Vector acceleration;
    Vector vitesse;
    Vector Position;
    Vector Vitesse;
    Vector integration_acc(Vector acceleration, Vector vit_ini, Vector vitesse); // acc = gravité ; renvoie vecteur vitesse
    Vector integration_vit(Vector vitesse, Vector pos_ini, Vector acceleration, Vector Position); // renvoie vecteur position

};


#endif // ANIMATION_H_INCLUDED
