/**
 *  @file : Utils.h
 *  @author : bullydd
 *  @brief  : Dans ce fichier nous avons des fonctions (helpers)
 *            pour initialisation de SDL, la vérification de compilation
 *            des programmes shaders.
 *            Fonctions sont déclarées en tant que membres statiques ce qui
 *            evite une instantiation.
 */

#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include "../glad/glad.h"


/// @brief Initialisation SDL selon les flags spécifiés (SDL_VIDEO, SDL_AUDIO, SDL_EVERYTHING)
/// ensuite définit des attributs pour OpenGL (openGL version, profile, RGBA color channel, ...)
/// Après quoi créé une fénètre ainsi qu'un contexte. Enfin retourne un pointeur sur l'objet
/// SDL_Window
/// @param width 
/// @param height 
/// @param title 
/// @return SDL_Window*
static SDL_Window* Init_SDL_OpenGL(const int width, const int height, const char* title);


#endif