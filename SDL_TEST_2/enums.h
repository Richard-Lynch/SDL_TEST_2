//
//  enums.h
//  SDL_TEST_2
//
//  Created by Richard Lynch on 05/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef enums_h
#define enums_h

//Texture Constants
enum Textures
{
    PRESS_TEXTURE,
    UP_TEXTURE,
    DOWN_TEXTURE,
    LEFT_TEXTURE,
    RIGHT_TEXTURE,
    DOT_TEXTURE,
    BACKGROUND_TEXTURE,
    TOTAL_TEXTURES
};

enum Sprites
{
    DEFUALT_SPRITE,
    FOO_SPRITE,
    TOTAL_SPRITES
};


enum Button_constants{
    BUTTON_WIDTH = 300,
    BUTTON_HEIGHT = 200,
    TOTAL_BUTTONS = 4
};


enum Location
{
    X_POS,
    Y_POS,
    TOTAL_POS
    };

#endif /* enums_h */
