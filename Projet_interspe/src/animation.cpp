#include "animation.h"


void Animation::update()
{
    // Complete this part
    angle += 0.05;
}

//____________________________ Moez

Vector Animation::integration_acc(Vector acceleration, Vector vitesse_ini)
{
    Vector vitesse;
    int time; // 10 ms ?
    vitesse.x = acceleration.x * time + vitesse_ini.x;
    vitesse.y = acceleration.y * time + vitesse_ini.y;
    vitesse.z = acceleration.z * time + vitesse_ini.z;
    return vitesse;
    
}

Vector Animation::integration_vit(Vector vitesse, Vector position_ini)
{
    Vector position;
    int time; // 10 ms ?
    position.x = vitesse.x * time + position_ini.x;
    position.y = vitesse.y * time + position_ini.y;
    position.z = vitesse.z * time + position_ini.z;
    return position;

}

//____________________________ Moez
