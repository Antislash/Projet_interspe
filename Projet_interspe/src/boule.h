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
    Animation anim;
    double angle, puissance; //Puissance � laquelle le joueur lance la balle
    GLuint texture = loadTexture("models/Ball_15.jpg" );
    bool touche; //V�rifie si la balle touche le sol

public:
    Boule(Point c = Point(), double r = 1.0);
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void setAnimation(Animation animation) {anim = animation;}
    void setAngle(double a){angle =a;}
    void render();
    void updateForm(double delta_t);
    double getPuissance(){return puissance;}
    void setPuissance(double p){puissance = p;}
    void setTouche(bool t){touche = t;}
};



#endif // ASTRE_H_INCLUDED
