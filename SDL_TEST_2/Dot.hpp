//
//  Dot.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef Dot_hpp
#define Dot_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <sstream>
#include <vector>

#include "GameSystem.hpp"
#include "LTexture.hpp"
#include "enums.h"

//A circle stucture
struct Circle
{
    int x, y;
    int r;
};


//The dot that will move around on the screen
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 5;
    
    //Deceleration
    static const int DOT_DEC = 5;
    bool decX;
    bool decY;
    
    //Initializes the variables
    Dot(GameSystem Game, LTexture* DotTexture, int x, int y);
    
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );
    
    //Moves the dot
    void move( SDL_Rect& square, Circle& circle );
    
    //Shows the dot on the screen relative to the camera
    void render( int camX, int camY );
    void render();
    
    //Gets the collision boxes
    Circle& getCollider();
    
    //Circle/Circle collision detector
    bool checkCollision( Circle& a, Circle& b );
    
    //Circle/Box collision detector
    bool checkCollision( Circle& a, SDL_Rect& b );
    
    //Calculates distance squared between two points
    double distanceSquared( int x1, int y1, int x2, int y2 );
    
    //Position accessors
    int getPosX();
    int getPosY();
    
private:
    //Dot's collision boxes
    Circle mCollider;
    
    //Moves the collision boxes relative to the dot's offset
    void shiftCollider();
    
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    
    //The velocity of the dot
    int mVelX, mVelY;
    
    //The Texture
    LTexture* mDotTexture;
    
    //Screen
    int mScreenWidth, mScreenHeight;
};

#endif /* Dot_hpp */
