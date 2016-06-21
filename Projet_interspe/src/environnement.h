#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "OBJlib.h"
#include "forms.h"

const int SIZE_PLAN_WIDTH = 3;
const int SIZE_PLAN_LENGTH = 12;
const int DISTANCE_SKYBOX = 50;

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

public:
    Fleche(Point p = Point());
    const Point getCenter() {return center;}
    void setCenter(Point c) {center = c;}
    void render();
    void updateForm(double delta_t);

};

class Ciel : public Form
{

private:
    Point center;

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

public:
    Cible(Point p = Point(), float t = 1.00){center = p; taille = t;}
    void render();
    void updateForm(double delta_t);
};
#endif // ENVIRONNEMENT_H_INCLUDED
