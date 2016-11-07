//
//  enums.h
//  SDL_TEST_2
//
//  Created by Richard Lynch on 05/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef enums_h
#define enums_h

//Key press surfaces constants
enum KeyPressTextures
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_STRETCH,
    KEY_PRESS_TEXTURE_RENDER,
    KEY_PRESS_VIEWPORT_TEXTURE,
    KEY_PRESS_SURFACE_TOTAL
};

enum Animation
{
    WALKING_ANIMATION_FRAMES = 4
};

enum Button_constants{
    BUTTON_WIDTH = 300,
    BUTTON_HEIGHT = 200,
    TOTAL_BUTTONS = 4
};


enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
    };

#endif /* enums_h */
