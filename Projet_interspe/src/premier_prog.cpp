// Using SDL, SDL OpenGL and standard IO
#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

// Module for space geometry
#include "geometry.h"
// Module for generating and rendering forms
#include "boule.h"
#include "environnement.h"
#include "OBJlib.h"
#include "sdlglutils.h"
//#include "skybox.h"


using namespace std;


/***************************************************************************/
/* Constants and functions declarations                                    */
/***************************************************************************/
// Screen dimension constants
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 560;
float pos = 0;
bool avancer = false;

// Max number of forms : static allocation
const int MAX_FORMS_NUMBER = 10;

// Animation actualization delay (in ms) => 100 updates per second
const Uint32 ANIM_DELAY = 10;


// Starts up SDL, creates window, and initializes OpenGL
bool init(SDL_Window** window, SDL_GLContext* context);

// Initializes matrices and clear color
bool initGL();

// Updating forms for animation
void update(Form* formlist[MAX_FORMS_NUMBER]);

// Renders scene to the screen
const void render(Form* formlist[MAX_FORMS_NUMBER], const Point &cam_pos);

// Frees media and shuts down SDL
void close(SDL_Window** window);


/***************************************************************************/
/* Functions implementations                                               */
/***************************************************************************/
bool init(SDL_Window** window, SDL_GLContext* context)
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        // Use OpenGL 2.1
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        // Create window
        *window = SDL_CreateWindow( "TP intro OpenGL / SDL 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
        if( *window == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            // Create context
            *context = SDL_GL_CreateContext(*window);
            if( *context == NULL )
            {
                cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                // Use Vsync
                if(SDL_GL_SetSwapInterval(1) < 0)
                {
                    cout << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << endl;
                }

                // Initialize OpenGL
                if( !initGL() )
                {
                    cout << "Unable to initialize OpenGL!"  << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}


bool initGL()
{
    bool success = true;
    GLenum error = GL_NO_ERROR;

    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport : use all the window to display the rendered scene
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Fix aspect ratio and depth clipping planes
    gluPerspective(40.0, (GLdouble)SCREEN_WIDTH/SCREEN_HEIGHT, 1.0, 100.0);


    // Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Initialize clear color : black with no transparency
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Activate Z-Buffer
    glEnable(GL_DEPTH_TEST);

    // Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        cout << "Error initializing OpenGL!  " << gluErrorString( error ) << endl;
        success = false;
    }

    return success;
}

void update(Form* formlist[MAX_FORMS_NUMBER])
{
    // Update the list of forms
    unsigned short i = 0;
    while(formlist[i] != NULL)
    {
        formlist[i]->getAnim().update();
        i++;
    }
}

const void render(Form* formlist[MAX_FORMS_NUMBER]) //, MeshObj* ballonFoot
{
    // Clear color buffer and Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    if(avancer){
//        pos += 0.01;
//        gluLookAt(2*SIZE_PLAN_WIDTH,2,0, 0,2,SIZE_PLAN_LENGTH, 0.0,1.0,0.0);
        gluLookAt(-2,-4,-10, 0.0,0.0,-5.0, 0.0,1.0,0.0);
    }
    else{
            pos += 0.5;
        // Set the camera position and parameters
        //gluLookAt(2,4,10, 0.0,0.0,-5.0, 0.0,1.0,0.0);
        //Placement, eye, up
        gluLookAt(-35,0,-30, 0,1,10, 0.0,1.0,0.0);
    }



    // X, Y and Z axis
    glPushMatrix(); // Preserve the camera viewing point for further forms
    // Render the coordinates system

    glTranslated(0,1,0);
    glBegin(GL_LINES);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(1, 0, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 1, 0);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 0, 1);
    }
    glEnd();
    glPopMatrix();

    // Render a simple object
//    glPushMatrix(); // Preserve the camera viewing point for further forms
//    glScaled(2,2,2);
//    glTranslated(0,0,3);
//    ballonFoot->draw_model();
//    glPopMatrix();

    // Render the list of forms
    unsigned short i = 0;
    while(formlist[i] != NULL)
    {
        glPushMatrix(); // Preserve the camera viewing point for further forms
        formlist[i]->render();
        glPopMatrix(); // Restore the camera viewing point for next object
        i++;
    }
}

void close(SDL_Window** window)
{
    //Destroy window
    SDL_DestroyWindow(*window);
    *window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}


/***************************************************************************/
/* MAIN Function                                                           */
/***************************************************************************/
int main(int argc, char* args[])
{
    // The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    // OpenGL context
    SDL_GLContext gContext;


    // Start up SDL and create window
    if( !init(&gWindow, &gContext))
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        // Main loop flag
        bool quit = false;
        Uint32 current_time, previous_time;

        // Event handler
        SDL_Event event;

        // Camera position
        //Point camera_position(10, 10, 5.0);

        // The forms to render
        Form* forms_list[MAX_FORMS_NUMBER];
        unsigned short number_of_forms = 0, i;
        forms_list[number_of_forms] = NULL; // Do nothing but remove a warning
        for (i=0; i<MAX_FORMS_NUMBER; i++)
        {
            forms_list[i] = NULL;
        }
        // Create here specific forms and add them to the list...
        // Don't forget to update the actual number_of_forms !

        Boule ballon(Point(0,0,0),0.5);
        Fleche fleche(Point(0,0,0));
        Ciel ciel(Point(0,0,0));
        //Sol sol(Point(0,0,0), Color(0,1,1));
        //MeshObj *fleche=new MeshObj("models/arrow/arrow.obj");


        forms_list[0] = &ballon;
        forms_list[1] = &fleche;
        forms_list[2] = &ciel;


        // Get first "current time"
        previous_time = SDL_GetTicks();
        // While application is running
        while(!quit)
        {
            // Handle events on queue
            while(SDL_PollEvent(&event) != 0)
            {
                int x = 0, y = 0;
                SDL_Keycode key_pressed = event.key.keysym.sym;

                switch(event.type)
                {
                // User requests quit
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                    avancer = true;
                    break;


                case SDL_KEYDOWN:
                    // Handle key pressed with current mouse position
                    SDL_GetMouseState( &x, &y );

                    switch(key_pressed)
                    {
                    // Quit the program when 'q' or Escape keys are pressed
                    case SDLK_q:
                    case SDLK_ESCAPE:
                        quit = true;
                        break;

                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }

            // Update the scene
            current_time = SDL_GetTicks(); // get the elapsed time from SDL initialization (ms)
            if ((current_time - previous_time) > ANIM_DELAY)
            {
                previous_time = current_time;
                update(forms_list);
            }

            // Render the scene
            render(forms_list);

            // Update window screen
            SDL_GL_SwapWindow(gWindow);
        }
    }

    // Free resources and close SDL
    close(&gWindow);

    return 0;
}
