#ifndef SKYBOX_H_INCLUDED
#define SKYBOX_H_INCLUDED

#include "boule.h"

class Skybox : public Form
{
    private:
        //string sFront, sBack, sLeft, sRight, sTop, sBottom;

    public:
        Skybox();
        void render();
};
#endif // SKYBOX_H_INCLUDED
