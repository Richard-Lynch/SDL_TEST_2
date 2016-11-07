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
    int dot = 0;
    
    //Event handler
    SDL_Event e;
    
    //Clear screen
    SDL_SetRenderDrawColor( game.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( game.gRenderer );
    
    
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
            else if( e.type == SDL_KEYDOWN ){
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                        
                    case SDLK_UP:
                        game.ypos[dot] -= 10;
                        break;
                        
                    case SDLK_DOWN:
                        game.ypos[dot] += 10;
                        break;
                        
                    case SDLK_LEFT:
                        game.xpos[dot] -= 10;
                        break;
                        
                    case SDLK_RIGHT:
                        game.xpos[dot]  += 10;
                        break;
                        
                    case SDLK_SPACE:
                        dot++;
                        dot = dot%4;
                        break;
                        
                    default:
                        break;
                }

            }
        }
        //Clear screen
        SDL_SetRenderDrawColor( game.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( game.gRenderer );
        
        //Render background texture to screen
        game.gBackgroundTexture.render( 0, 0 , game.gRenderer);
        
        //Render top left sprite
        game.gSpriteSheetTexture.render( game.xpos[0], game.ypos[0], game.gRenderer, &(game.gSpriteClips[ 0 ]) );
        
        //Render top right sprite
        game.gSpriteSheetTexture.render( game.xpos[1], game.ypos[1], game.gRenderer, &(game.gSpriteClips[ 1 ]) );
        
        //Render bottom left sprite
        game.gSpriteSheetTexture.render( game.xpos[2], game.ypos[2], game.gRenderer, &(game.gSpriteClips[ 2 ]) );
        
        //Render bottom right sprite
        game.gSpriteSheetTexture.render( game.xpos[3], game.ypos[3], game.gRenderer, &(game.gSpriteClips[ 3 ]) );
        
        //Update screen
        SDL_RenderPresent( game.gRenderer );
    }
    game.close();
    return 0;
}


