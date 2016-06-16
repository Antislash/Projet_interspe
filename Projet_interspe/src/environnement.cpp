#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "environnement.h"

using namespace std;

void Sol::render(){
    glBegin(GL_QUADS);
    {
        // 1er face
        glColor3f(1, 0, 0);
        glVertex3i(5, 0, 5);
        glColor3f(1, 0, 1);
        glVertex3i(5, 0, -5);
        glColor3f(0, 0, 1);
        glVertex3i(-5, 0, -5);
        glColor3f(1, 0, 0);
        glVertex3i(-5, 0, 5);
    }
    glEnd();

}
