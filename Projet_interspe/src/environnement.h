#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "OBJlib.h"
#include "forms.h"
#include "animation.h"

const int DISTANCE_SKYBOX = 45;

class Fleche : public Form
{

private:
    Point center;
    MeshObj *fleche;
    Animation anim;
    double angleX;
    double angleY;

public:
    Fleche(Point p = Point());
    const Point getCenter() {return center;}
    double getAngleX() {return angleX;}
    double getAngleY() {return angleY;}
    void setAngleX(double _angleX) {angleX = _angleX;}
    void setAngleY(double _angleY) {angleY = _angleY;}
    void setCenter(Point c) {center = c;}
    void setAnimation(Animation animation) {anim = animation;}
    void render();
    void updateForm(double delta_t);

};

class Ciel : public Form
{

private:
    Point center;
    GLuint texture1 = loadTexture("models/skybox/spaceship.png" );
    GLuint texture2 = loadTexture("models/skybox/spaceship.png");
    GLuint texture3 = loadTexture("models/skybox/spaceship.png" );
    GLuint texture4 = loadTexture("models/skybox/spaceship.png");
    GLuint texture5 = loadTexture("models/skybox/spaceship.png" );
    GLuint texture6 = loadTexture("models/skybox/spaceship.png");


public:
    Ciel(Point p = Point());
    void render();
    void updateForm(double delta_t);

};

class Cible : public Form
{
private:
    float taille;
    Point center;
    GLuint texture = loadTexture("models/cible.jpg"); // Texture lorsque la cible n'est pas touch�
    GLuint texture2 = loadTexture("models/cible_touche.png"); // Quand la cible est touch�
    bool touche;

public:
    Cible(Point p = Point(), float t = 1.00){center = p; taille = t; touche = false;}
    void render();
    void updateForm(double delta_t);
    Point getCenter(){return center;}
    float getTaille() {return taille;}
    void setTouche(bool t){touche = t;}
};
#endif // ENVIRONNEMENT_H_INCLUDED
