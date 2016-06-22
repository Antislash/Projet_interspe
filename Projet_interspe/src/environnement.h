#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "OBJlib.h"
#include "forms.h"

const int DISTANCE_SKYBOX = 45;

class Sol : public Form
{

private:
    Point center;
    MeshObj *terrain;

public:
    Sol(Point p = Point());
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void render();
    void updateForm(double delta_t);

};

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
    GLuint texture1 = loadTexture("models/skybox4/top.jpg" );
    GLuint texture2 = loadTexture("models/skybox4/back.jpg");
    GLuint texture3 = loadTexture("models/skybox4/front.jpg" );
    GLuint texture4 = loadTexture("models/skybox4/left.jpg");
    GLuint texture5 = loadTexture("models/skybox4/right.jpg" );
    GLuint texture6 = loadTexture("models/skybox4/bottom.jpg");


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
    GLuint texture = loadTexture("models/cible.jpg");

public:
    Cible(Point p = Point(), float t = 1.00){center = p; taille = t;}
    void render();
    void updateForm(double delta_t);
};
#endif // ENVIRONNEMENT_H_INCLUDED
