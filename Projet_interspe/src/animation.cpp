#include "animation.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "geometry.h"

using namespace std;

Animation::Animation(double ph, double th, Vector accel, Vector speed, Point p)
{
    // Constructor
    // Initialization
    phi = ph;
    theta = th;
    acc = accel;
    spd = speed;
    pos = p;
}

//____________________________ Moez

void Animation::integration_acc(double dt)
{
    spd.x += acc.x*dt;
    spd.y += acc.y*dt;
    spd.z += acc.z*dt;

}

void Animation::integration_vit(double dt)
{
    //integration_acc(dt);

    pos.x += spd.x*dt;
    pos.y += spd.y*dt;
    pos.z += spd.z*dt;

}

void Animation::vit_collision(double dt, Vector N)
{
    //spd = -2*(spd*N)*N-spd;
    spd.z = -spd.z;
}


//____________________________ Moez
