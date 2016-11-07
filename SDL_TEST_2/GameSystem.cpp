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

    //Load sprites
    if( !gButtonSpriteSheetTexture.loadFromFile( "17_mouse_events/button.png" , gRenderer) )
    {
        printf( "Failed to load button sprite texture!\n" );
        success = false;
    }
    else
    {
        //Set sprites
        for( int i = 0; i < BUTTON_SPRITE_TOTAL; ++i )
        {
            gSpriteClips[ i ].x = 0;
            gSpriteClips[ i ].y = i * 200;
            gSpriteClips[ i ].w = BUTTON_WIDTH;
            gSpriteClips[ i ].h = BUTTON_HEIGHT;
        }
        
        //Set buttons in corners
        gButtons[ 0 ].setPosition( 0, 0 );
        gButtons[ 1 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, 0 );
        gButtons[ 2 ].setPosition( 0, SCREEN_HEIGHT - BUTTON_HEIGHT );
        gButtons[ 3 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT );
    }
    
    return success;
}

SDL_Texture* GameSystem::loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return newTexture;
}

bool GameSystem::useViewports(){
    bool success = true;
    
    //left
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH / 2;
    topLeftViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    
    //Render texture to screen
    SDL_RenderCopy( gRenderer, gTexture[KEY_PRESS_VIEWPORT_TEXTURE], NULL, NULL );
    
    //right
    topRightViewport.x = SCREEN_WIDTH / 2;
    topRightViewport.y = 0;
    topRightViewport.w = SCREEN_WIDTH / 2;
    topRightViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &topRightViewport );
    
    //Render texture to screen
    SDL_RenderCopy( gRenderer, gTexture[KEY_PRESS_VIEWPORT_TEXTURE], NULL, NULL );
    
    //bottom
    bottomViewport.x = 0;
    bottomViewport.y = SCREEN_HEIGHT / 2;
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &bottomViewport );
    
    //Render texture to screen
    SDL_RenderCopy( gRenderer, gTexture[KEY_PRESS_VIEWPORT_TEXTURE], NULL, NULL );
    
    return success;
}

bool GameSystem::init(){
    gKeyPressStrings[ 0 ] = "04_key_presses/press.png";
    gKeyPressStrings[ 1 ] = "04_key_presses/up.png";
    gKeyPressStrings[ 2 ] = "04_key_presses/down.png";
    gKeyPressStrings[ 3 ] = "04_key_presses/left.png";
    gKeyPressStrings[ 4 ] = "04_key_presses/right.png";
    gKeyPressStrings[ 5 ] = "05_optimized_surface_loading_and_soft_stretching/stretch.png";
    gKeyPressStrings[ 6 ] = "07_texture_loading_and_rendering/texture.png";
    gKeyPressStrings[ 7 ] = "09_the_viewport/viewport.png";
    
    foo_x = 240;
    foo_y = 190;
    
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
                
                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    initialised = false;
                }
            }


            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            loadMedia();
            
        }
    }
    return initialised;
}

void GameSystem::close()
{
    for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
    //Free loaded image
    SDL_DestroyTexture( gTexture[i] );
    
    //Deallocate surfaces
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
        SDL_FreeSurface( gKeyPressSurfaces[ i ] );
        gKeyPressSurfaces[ i ] = NULL;
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
