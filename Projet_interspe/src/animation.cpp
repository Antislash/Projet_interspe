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
    vitesse.x += vitesse_ini.x - acceleration*time;
    vitesse.y += vitesse_ini.y - acceleration*time;
    vitesse.z += vitesse_ini.z - acceleration*time;
    return vitesse;
    
}

Vector Animation::integration_vit(Vector vitesse, Vector position_ini)
{
    Vector position;
    int time; // 10 ms ?
    position.x = position_ini.x - vitesse*time;
    position.y = position_ini.y - vitesse*time;
    position.z = position_ini.y - vitesse*time;
    return position;

}

//____________________________ Moez
