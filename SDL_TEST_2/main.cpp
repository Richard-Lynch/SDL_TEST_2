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
#include <SDL2_ttf/SDL_ttf.h>
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
            //Handle button events
            for( int i = 0; i < TOTAL_BUTTONS; ++i )
            {
                game.gButtons[ i ].handleEvent( &e );
            }
        }
        //Clear screen
        SDL_SetRenderDrawColor( game.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( game.gRenderer );
    
        
        //Render buttons
        for( int i = 0; i < TOTAL_BUTTONS; ++i )
        {
            game.gButtons[ i ].render(game.gRenderer, &(game.gButtonSpriteSheetTexture), game.gSpriteClips);
        }
        
        //Update screen
        SDL_RenderPresent( game.gRenderer );
    }
    game.close();
    return 0;
}


