// Standard Headers
// Project Headers
#include "main.h"
#include "engine.h"
#include "logging.h"
#include "global.h"
#include "scene.h"
#include "files.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool gVerbose = false;
bool gWindowed = false;
bool gBorderless = false;
bool gGameRunning = true;

int gWindowWidth;
int gWindowHeight;


//Keep track of the current frame
int frame = 0;

//Whether or not to cap the frame rate
bool cap = true;

using namespace std;

void Engine::onRender()
{
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f( 0.5f, -0.5f );
        glVertex2f( 0.5f, 0.5f );
        glVertex2f( -0.5f, 0.5f );
    glEnd();
}

int Engine::Start()
{
    try
    {
        //Initialize SDL
        if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
        {
             if(strlen(SDL_GetError()) > 0)    
                FATAL_PRINT("SDL could not initialize!\n%s", SDL_GetError());
            else
                FATAL_PRINT("SDL could not initialize!");
            return -1;
        }
        else
        {
            Files files;
            files.initializeEnginePrefs();
            if(files.isWritingEnabled() == true)
            {
                MAIN_PRINT("[Engine] Writing enabled");    
            }
            else
            {
                FATAL_PRINT("Writing disabled, engine may function incorrectly at places.");    
            }

            MAIN_PRINT(files.getEnginePreferences());

            MAIN_PRINT("[Engine] Set GL Attributes");
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

            MAIN_PRINT("[Engine] Create Window");
            SDL_Rect rect;

            if (SDL_GetDisplayBounds(0, &rect) != 0) 
            {
                SDL_Log("SDL_GetDisplayBounds failed: %s", SDL_GetError());
                Engine::window = SDL_CreateWindow( ENGINE_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
            }
            else
            {
                gWindowWidth = rect.w;
                gWindowHeight = rect.h;
                printf("[Engine] WindowSize %i x %i\n", gWindowWidth, gWindowHeight);
                Engine::window = SDL_CreateWindow( ENGINE_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gWindowWidth, gWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
            }
        
            if( Engine::window == NULL )
            {
                if(strlen(SDL_GetError()) > 0)    
                    FATAL_PRINT("Window could not be created!\n%s", SDL_GetError());
                else
                    FATAL_PRINT("Window could not be created!");
            }
            else
            {
                
                //Create context
                gContext = SDL_GL_CreateContext( window );
                if( gContext == NULL )
                {
                    if(strlen(SDL_GetError()) > 0)    
                        FATAL_PRINT("OpenGL context could not be created!\n%s", SDL_GetError());
                    else
                        FATAL_PRINT("OpenGL context could not be created!");
                    return -1;
                }

                //Initialize Projection Matrix
                glMatrixMode( GL_PROJECTION );
                glLoadIdentity();

                //Check for error
                GLenum error = GL_NO_ERROR;
                error = glGetError();
                if( error != GL_NO_ERROR )
                {
                    FATAL_PRINT("Error initializing OpenGL: %d", error);
                    return -1;
                }

                //Initialize Modelview Matrix
                glMatrixMode( GL_MODELVIEW );
                glLoadIdentity();

                //Initialize clear color
                glClearColor( 0.f, 0.f, 0.f, 1.f );

                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable( GL_BLEND );

                //Check for error
                error = glGetError();
                if( error != GL_NO_ERROR )
                {
                    FATAL_PRINT("Error initializing OpenGL: %d", error);
                    return -1;
                }
                // Initialize GLEW
                /*if (glewInit() != GLEW_OK) {
                    fprintf(stderr, "Failed to initialize GLEW\n");
                    return;
                }*/

                if(gWindowed == false)
                {
                    if(gBorderless == true)
                    {
                        MAIN_PRINT("[Engine] Borderless Window");
                        SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else
                    {
                        MAIN_PRINT("[Engine] Exclusive Window");
                        SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
                    }
                }
                else
                {
                    MAIN_PRINT("[Engine] Maximise Window");
                    SDL_MaximizeWindow(window);
                }
                //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

                MAIN_PRINT("[Engine] First onRender");
                Engine::onRender();

                Scene scene;

                SDL_Event event;
                while (gGameRunning)
                {
                    const Uint8 *state = SDL_GetKeyboardState(NULL);
                    Engine::onRender();
                    #if DEBUG
                    printf("Mouse = %i x %i\n", scene.getMouseX(), scene.getMouseY());
                    #endif
                    if (SDL_PollEvent(&event))
                    {
                        switch(event.type)
                        {
                            case SDL_QUIT:
                            {
                                MAIN_PRINT("[Engine] Preparing to kill the game engine via SDL_QUIT");
                                gGameRunning = false;
                            }
                            case SDL_KEYDOWN:
                            {
                                MAIN_PRINT("[Engine] OnKeyDown");
                            }
                            case SDL_KEYUP:
                            {
                                MAIN_PRINT("[Engine] OnKeyUp");
                                if (state[SDL_SCANCODE_RETURN]) 
                                {
                                    FATAL_PRINT("<RETURN> is pressed.\n");
                                }
                            }
                        }
                        
                    }
                }

            }

            MAIN_PRINT("[Engine] Exiting gracefully via SDL_Quit()! Goodbye World!");
            SDL_Quit();
        }
    }
    catch (...)
    {
        ERROR_PRINT("[Engine @ main.cpp] Unknown Exception caught, killing engine process!");
        raise(SIGABRT);
        return -1;
    }
    return 0;
}