#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include "geometry.h"


/*class Animation
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


};*/

class Animation
{
private:
    double phi, theta; // Azimuthal and polar angles for local coordinate system orientation
    Vector acc, spd; //  Instantaneous acceleration and speed
    Point pos; // Instantaneous position of the local coordinate system origin

public:
    Animation(double ph = 0.0, double th = 0.0,
              Vector accel = Vector(0.0, 0.0, 0.0),
              Vector speed = Vector(0.0, 0.0, 0.0),
              Point p = Point(0.0, 0.0, 0.0)
              );
    const double getPhi() {return phi;}
    const double getTheta() {return theta;}
    void setPhi(double agl) {phi = agl;}
    void setTheta(double agl) {theta = agl;}
    const Vector getAccel() {return acc;}
    const Vector getSpeed() {return spd;}
    void setAccel(Vector vect) {acc = vect;}
    void setSpeed(Vector vect) {spd = vect;}
    const Point getPos() {return pos;}
    void setPos(Point pt) {pos = pt;}
    void integration_acc(double dt);
    void integration_vit(double dt);
};



#endif // ANIMATION_H_INCLUDED
