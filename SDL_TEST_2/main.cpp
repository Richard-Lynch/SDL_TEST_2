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
#include <sstream>
#include <vector>

#include "enums.h"
#include "GameSystem.hpp"
#include "LTimer.hpp"
#include "Dot.hpp"

int main(int argc, const char * argv[]) {
        
    GameSystem game;
    game.init();
    //Main loop flag
    bool quit = false;
    
    //DOT
    Dot dot(game, game.gTexture[DOT_TEXTURE], 20, 20);
    
    //The camera area
    SDL_Rect camera = { 0, 0, game.SCREEN_WIDTH, game.SCREEN_HEIGHT };
    
    //The dot that will be collided against
    Dot otherDot(game, game.gTexture[DOT_TEXTURE], (game.LEVEL_WIDTH)/2, (game.LEVEL_HEIGHT)/2 );
    
    ///Set the wall
    SDL_Rect wall;
    wall.x = 300;
    wall.y = 40;
    wall.w = 40;
    wall.h = 400;
    
    //Event handler
    SDL_Event e;
    
    //Clear screen
    SDL_SetRenderDrawColor( game.gRenderer, 0, 0xFF, 0xFF, 0xFF );
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
            //Handle input for the dot
            dot.handleEvent( e );
        }
        //Clear screen
        SDL_SetRenderDrawColor( game.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( game.gRenderer );
        
        //------------DO STUFF HERE------------------
        //Move the dot and check collision
        dot.move( wall, otherDot.getCollider() );
        
        //Center the camera over the dot
        camera.x = ( dot.getPosX()) - game.SCREEN_WIDTH / 2;
        camera.y = ( dot.getPosY()) - game.SCREEN_HEIGHT / 2;
        
        //Keep the camera in bounds
        if( camera.x < 0 )
        {
            camera.x = 0;
        }
        if( camera.y < 0 )
        {
            camera.y = 0;
        }
        if( camera.x > game.LEVEL_WIDTH - camera.w )
        {
            camera.x = game.LEVEL_WIDTH - camera.w;
        }
        if( camera.y > game.LEVEL_HEIGHT - camera.h )
        {
            camera.y = game.LEVEL_HEIGHT - camera.h;
        }
        
        //Render background
        game.gTexture[BACKGROUND_TEXTURE]->render( 0, 0, &camera );
        
        //Render dots
        dot.render(camera.x, camera.y );
        otherDot.render();
        
        //Render wall
        SDL_SetRenderDrawColor( game.gRenderer, 0x00, 0x00, 0x00, 0xFF );
//        SDL_RenderDrawRect( game.gRenderer, &wall );

        
        //-----------END OF DO STUFF-----------------
        
        //Update screen
        SDL_RenderPresent( game.gRenderer );

    }
    game.close();
    return 0;
}


