#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "geometry.h"
#include "animation.h"
#include <string.h>
#include "OBJlib.h"
#include "forms.h"



// A particular Form
class Boule : public Form
{
private:
    Point center;
    double radius;
    MeshObj *ballon;
public:
    Boule(Point c = Point(), double r = 1.0);
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void render();
    void updateForm(double delta_t);
};



#endif // ASTRE_H_INCLUDED
