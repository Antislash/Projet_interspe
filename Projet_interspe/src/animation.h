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
    void update();


    // Moez 
    Vector integration_acc(Vector acc, Vector vit_ini);
    Vector integration_vit(Vector vit, Vector pos_ini);

};


#endif // ANIMATION_H_INCLUDED
