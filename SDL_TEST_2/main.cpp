//
//  main.cpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 04/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "enums.h"
#include "GameSystem.hpp"

int main(int argc, const char * argv[]) {
        
    GameSystem game;
    game.init();
    //Main loop flag
    bool quit = false;
    
    //Event handler
    SDL_Event e;
    
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                        break;
                        
                    case SDLK_DOWN:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                        break;
                        
                    case SDLK_LEFT:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                        break;
                        
                    case SDLK_RIGHT:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                        break;
                        
                    case SDLK_SPACE:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_STRETCH ];
                        break;
                        
                    case SDLK_KP_A:
                    {
                        //Clear screen
                        SDL_RenderClear( game.gRenderer );
                        
                        //Render texture to screen
                        SDL_RenderCopy( game.gRenderer, game.gTexture, NULL, NULL );
                        
                        //Update screen
                        SDL_RenderPresent( game.gRenderer );
                    }
                        
                    default:
                        game.gCurrentSurface = game.gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                        break;
                }
            }
        }
        //Apply the image stretched
        SDL_Rect stretchRect;
        stretchRect.x = 0;
        stretchRect.y = 0;
        stretchRect.w = game.SCREEN_WIDTH;
        stretchRect.h = game.SCREEN_HEIGHT;
        
        //Apply the image
        SDL_BlitScaled( game.gCurrentSurface, NULL, game.gScreenSurface, &stretchRect );
        
        //Update the surface
        SDL_UpdateWindowSurface( game.gWindow );
    }
    return 0;
}


