#ifndef FORMS_H_INCLUDED
#define FORMS_H_INCLUDED

#include "geometry.h"
#include "animation.h"


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
    Color col;
    Animation anim;
public:
    Animation& getAnim() {return anim;}
    void setAnim(Animation ani) {anim = ani;}
    // Virtual method : Form is a generic type, no rendering is possible
    virtual void render() = 0;
};


// A particular Form
class Sphere : public Form
{
private:
    Point center;
    double radius;
public:
    Sphere(Point c = Point(), double r = 1.0, Color cl = Color());
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void render();
};

#endif // FORMS_H_INCLUDED
