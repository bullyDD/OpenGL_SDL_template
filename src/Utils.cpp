#include "Utils.h"

SDL_Window* Init_SDL_OpenGL(const int width, const int height, const char *title)
{
    // SDL Initialisation
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        SDL_Log("ERROR::SDL:: %s\n", SDL_GetError());
        return nullptr;
    }

    // Load openGL par défaut
    SDL_GL_LoadLibrary(NULL);

    // Active Hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    // Définit la version d'openGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    // Definit la taille en mémoire pour chaque couleur
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  8);

    // Active le double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 24);

    // Créer la fenetre 
    SDL_Window* mWindow = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_OPENGL);
    if (mWindow == nullptr) {
        SDL_Log("ERROR::SDL::WINDOW: %s\n", SDL_GetError());
        return nullptr;
    }

    // Creer un contexte
    SDL_GLContext glContext = SDL_GL_CreateContext(mWindow);
    if (glContext == NULL) {
        SDL_Log("ERROR::SDL::CONTEXT: %s\n", SDL_GetError());
        return nullptr;
    }

    SDL_GL_MakeCurrent(mWindow, glContext);

    SDL_GL_SetSwapInterval(1);      // Active la synchronisation verticale

    return mWindow;
}