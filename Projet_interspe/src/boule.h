#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "geometry.h"
#include "animation.h"
#include <string.h>
#include "OBJlib.h"
#include "forms.h"
#include "environnement.h"



// Class pour la modélisation de la boule
class Boule : public Form
{
private:
    Point center;
    double radius;
    Animation anim;
    double angle, puissance; // Puissance à laquelle le joueur lance la balle
    GLuint texture;
    bool touche; // Vérifie si la balle touche la cible
    bool toucheSol; // Verifie sir la balle touche le sol

public:
    Boule(Point c = Point(), double r = 1.0);
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void setAnimation(Animation animation) {anim = animation;}
    void setAngle(double a){angle =a;}
    void setToucheSol (bool _toucheSol) {toucheSol = _toucheSol;}
    void render();
    void updateForm(double delta_t);
    void updateForm(double delta_t, Cible* cibles, int nb_cibles);
    double getPuissance(){return puissance;}
    void setPuissance(double p){puissance = p;}
    void setTouche(bool t){touche = t;}
    void setTexture(int text);
    Vector check_Impact_cible(Cible cible);
    Vector check_Impact_mur(Cible cible);
};



#endif // ASTRE_H_INCLUDED
