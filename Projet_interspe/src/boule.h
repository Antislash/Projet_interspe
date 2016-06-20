#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "geometry.h"
#include "animation.h"
#include <string.h>
#include "OBJlib.h"

class Color
{
public:
    float r, g, b;
    Color(float rr = 1.0f, float gg = 1.0f, float bb = 1.0f) {r=rr; g=gg; b=bb;}
};

// Constant Colors
const Color RED(1.0f, 0.0f, 0.0f);
const Color BLUE(0.0f, 0.0f, 1.0f);
const Color GREEN(0.0f, 1.0f, 0.0f);
const Color YELLOW(1.0f, 1.0f, 0.0f);
const Color WHITE(1.0f, 1.0f, 1.0f);


// Generic class to render and animate an object
class Form
{
protected:
    //string text;
    Animation anim;
public:
    Animation& getAnim() {return anim;}
    void setAnim(Animation ani) {anim = ani;}
    // Virtual method : Form is a generic type, no rendering is possible
    virtual void render() = 0;
    virtual void updateForm(double angle, Vector direction, Vector translation) = 0;
};


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
    void updateForm(double angle, Vector direction, Vector translation);
};



#endif // ASTRE_H_INCLUDED
