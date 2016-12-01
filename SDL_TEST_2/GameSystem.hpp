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
#include <SDL2_ttf/SDL_ttf.h>
#include <sstream>

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
    LTexture* gCurrentTexture = NULL;
    
    //Title of window
    const std::string title = "SDL Tutorials";
    //The dimensions of the level
    const int LEVEL_WIDTH = 1280;
    const int LEVEL_HEIGHT = 960;
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    //Current displayed texture
    LTexture* gTexture[ TOTAL_TEXTURES ];
    //the strings that find the images, array of strings
    std::string gImage_Strings[ TOTAL_TEXTURES ];
    SDL_Rect gClips[TOTAL_SPRITES];
    int gSpriteLoc[TOTAL_SPRITES][TOTAL_POS];
    
    //flags
    bool initialised = false;

    //Starts up SDL and creates window
    bool init();
    //Loads media
    bool loadMedia();
    //Loads individual image as texture
    SDL_Texture* loadTexture( std::string path );

    //Frees media and shuts down SDL
    void close();

};


#endif /* GameSystem_hpp */
