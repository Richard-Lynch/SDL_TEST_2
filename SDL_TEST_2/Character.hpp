//
//  Character.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "LTexture.hpp"
#include "enums.h"

class Character{
    public:
    //Walking animation
    SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
    LTexture gSpriteSheetTexture;
};

#endif /* Character_hpp */
