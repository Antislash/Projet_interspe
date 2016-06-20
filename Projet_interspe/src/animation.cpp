#include "animation.h"


void Animation::update()
{
    // Complete this part
    angle += 0.05;
}

//____________________________ Moez

Vector Animation::integration_acc(Vector acceleration, Vector vitesse_ini, Vector vitesse)
{
    int dt; // 10 ms ?
    vitesse.x += acceleration.x*dt;
    vitesse.y += acceleration.y*dt;
    vitesse.z += acceleration.z*dt;
    return vitesse;

}

Vector Animation::integration_vit(Vector vitesse, Vector position_ini, Vector acceleration, Vector position)
{
    int dt; // 10 ms ?
    position.x += vitesse.x*dt+(1/2)*acceleration.x*dt;
    position.y += vitesse.y*dt+(1/2)*acceleration.y*dt;
    position.z += vitesse.z*dt+(1/2)*acceleration.z*dt;
    return position;

}


//____________________________ Moez
