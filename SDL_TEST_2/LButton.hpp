//
//  LButton.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef LButton_hpp
#define LButton_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "LTexture.hpp"
#include "enums.h"

//The mouse button
class LButton
{
public:
    //Initializes internal variables
    LButton();
    
    //Sets top left position
    void setPosition( int x, int y );
    
    //Handles mouse event
    void handleEvent( SDL_Event* e );
    
    //Shows button sprite
    void render(SDL_Renderer* Renderer, LTexture* ButtonSpriteSheetTexture, SDL_Rect SpriteClips[]);
    
private:
    //Top left position
    SDL_Point mPosition;
    
    //Currently used global sprite
    LButtonSprite mCurrentSprite;
};

#endif /* LButton_hpp */
