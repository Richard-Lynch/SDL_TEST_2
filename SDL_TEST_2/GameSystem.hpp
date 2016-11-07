//
//  GameSystem.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 04/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef GameSystem_hpp
#define GameSystem_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "LTexture.hpp"
#include "enums.h"

class GameSystem{
    public:
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;
    //The window renderer
    SDL_Renderer* gRenderer = NULL;
    //Current displayed image
    SDL_Surface* gCurrentSurface = NULL;
    //Current displayed texture
    SDL_Texture* gTexture[ KEY_PRESS_SURFACE_TOTAL ];
    //The images that correspond to a keypress, array of images
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
    //the strings that find the images, array of strings
    std::string gKeyPressStrings[ KEY_PRESS_SURFACE_TOTAL ];
    
    //Scene textures
    LTexture gFooTexture;
    LTexture gBackgroundTexture;
    //scene locations
    int foo_x, foo_y;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    //Top left corner viewport
    SDL_Rect topLeftViewport;
    //Top right viewport
    SDL_Rect topRightViewport;
    //Bottom viewport
    SDL_Rect bottomViewport;
    
    //text
    const std::string splash = "x.bmp";
    const std::string title = "SDL Tutorials";
    
    //flags
    bool initialised = false;

    //Starts up SDL and creates window
    bool init();

    //Loads media
    bool loadMedia();
    SDL_Surface* loadSurface(std::string path);
    //Loads individual image as texture
    SDL_Texture* loadTexture( std::string path );
    
    //set Viewport
    bool useViewports();

    //Frees media and shuts down SDL
    void close();

};


#endif /* GameSystem_hpp */
