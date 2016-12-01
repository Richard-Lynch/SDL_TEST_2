//
//  GameSystem.cpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 04/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#include "GameSystem.hpp"

bool GameSystem::loadMedia()
{
    //Loading success flag
    bool success = true;

    for(int i = 0; i<TOTAL_TEXTURES; i++){
        //Load sprites
        if( !gTexture[i]->loadFromFile( gImage_Strings[i]) )
        {
            printf( "Failed to load texture number: %d!\n", i );
            success = false;
        }
        else
        {
            //create clips
            //create sprites
        }
    }
    
    return success;
}


bool GameSystem::init(){
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        initialised = true;
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            initialised = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                initialised = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    initialised = false;
                }
            }
            
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            
            //initlise textures and strings
            for(int i = 0; i<TOTAL_TEXTURES; i++){
                //create LTextures
                gTexture[ i ] = new LTexture(gRenderer);
            }
            gImage_Strings[PRESS_TEXTURE] = "18_key_states/press.png";
            gImage_Strings[UP_TEXTURE] = "18_key_states/up.png";
            gImage_Strings[DOWN_TEXTURE] = "18_key_states/down.png";
            gImage_Strings[LEFT_TEXTURE] = "18_key_states/left.png";
            gImage_Strings[RIGHT_TEXTURE] = "18_key_states/right.png";
            gImage_Strings[DOT_TEXTURE] = "26_motion/dot.bmp";
            gImage_Strings[BACKGROUND_TEXTURE] = "30_scrolling/bg.png";
            
            loadMedia();
            
        }
    }
    
    
    return initialised;
}

void GameSystem::close()
{
    for(int i = 0; i < TOTAL_TEXTURES; i++){
        delete gTexture[i];
    }
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
