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
    
    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( gKeyPressStrings[ 0 ] );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
    
    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( gKeyPressStrings[ 1 ] );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
    {
        printf( "Failed to load up image!\n" );
        success = false;
    }
    
    //Load down surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( gKeyPressStrings[ 2 ] );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }
    
    //Load left surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( gKeyPressStrings[ 3 ] );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }
    
    //Load right surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( gKeyPressStrings[ 4 ] );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }
    
    //Set default current surface
    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
    
    return success;
}

SDL_Surface* GameSystem::loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    
    return loadedSurface;
}

bool GameSystem::init(){
    gKeyPressStrings[ 0 ] = "04_key_presses/press.bmp";
    gKeyPressStrings[ 1 ] = "04_key_presses/up.bmp";
    gKeyPressStrings[ 2 ] = "04_key_presses/down.bmp";
    gKeyPressStrings[ 3 ] = "04_key_presses/left.bmp";
    gKeyPressStrings[ 4 ] = "04_key_presses/right.bmp";
    
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            initialised = true;
            loadMedia();
            
        }
    }
    return initialised;
}

void GameSystem::close()
{
    //Deallocate surfaces
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
        SDL_FreeSurface( gKeyPressSurfaces[ i ] );
        gKeyPressSurfaces[ i ] = NULL;
    }
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}
