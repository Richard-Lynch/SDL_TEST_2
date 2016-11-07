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
                        game.foo_y -= 10;
                        break;
                        
                    case SDLK_DOWN:
                        game.foo_y += 10;
                        break;
                        
                    case SDLK_LEFT:
                        game.foo_x -= 10;
                        break;
                        
                    case SDLK_RIGHT:
                        game.foo_x += 10;
                        break;
                        
                    case SDLK_SPACE:
                        game.foo_x = 240;
                        game.foo_y = 190;
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
        
        //Render Foo' to the screen
        game.gFooTexture.render( game.foo_x, game.foo_y , game.gRenderer);
        
        //Update screen
        SDL_RenderPresent( game.gRenderer );
    }
    game.close();
    return 0;
}


