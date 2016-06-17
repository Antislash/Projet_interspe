#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "boule.h"

const int SIZE_PLAN_WIDTH = 3;
const int SIZE_PLAN_LENGTH = 12;

class Sol : public Form
{

private:
    Point center;
    Color col;

public:
    Sol(Point p = Point(), Color c = Color()){center= p; col =c;}
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void render();

};


#endif // ENVIRONNEMENT_H_INCLUDED
