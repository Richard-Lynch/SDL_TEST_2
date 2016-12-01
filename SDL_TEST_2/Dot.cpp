//
//  Dot.cpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#include "Dot.hpp"

Dot::Dot(GameSystem Game, LTexture* DotTexture, int x, int y)
{
    //Initialize the offsets
    mPosX = x;
    mPosY = y;
    
    //Set collision circle size
    mCollider.r = DOT_WIDTH / 2;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    
    //Move collider relative to the circle
    shiftCollider();
    
    //Initialize the Screen
    mScreenWidth = Game.LEVEL_WIDTH;
    mScreenHeight = Game.LEVEL_HEIGHT;
    mDotTexture = DotTexture;
    
}

bool Dot::checkCollision( Circle& a, Circle& b )
{
    //Calculate total radius squared
    int totalRadiusSquared = a.r + b.r;
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;
    
    //If the distance between the centers of the circles is less than the sum of their radii
    if( distanceSquared( a.x, a.y, b.x, b.y ) < ( totalRadiusSquared ) )
    {
        //The circles have collided
        return true;
    }
    
    //If not
    return false;
}

bool Dot::checkCollision( Circle& a, SDL_Rect& b )
{
    //Closest point on collision box
    int cX, cY;
    
    //Find closest x offset
    if( a.x < b.x )
    {
        cX = b.x;
    }
    else if( a.x > b.x + b.w )
    {
        cX = b.x + b.w;
    }
    else
    {
        cX = a.x;
    }
    
    //Find closest y offset
    if( a.y < b.y )
    {
        cY = b.y;
    }
    else if( a.y > b.y + b.h )
    {
        cY = b.y + b.h;
    }
    else
    {
        cY = a.y;
    }
    
    //If the closest point is inside the circle
    if( distanceSquared( a.x, a.y, cX, cY ) < a.r * a.r )
    {
        //This box and the circle have collided
        return true;
    }
    
    //If the shapes have not collided
    return false;
}

double Dot::distanceSquared( int x1, int y1, int x2, int y2 )
{
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    return deltaX*deltaX + deltaY*deltaY;
}



void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY -= DOT_VEL;
                decY = false;
                break;
            case SDLK_DOWN:
                mVelY += DOT_VEL;
                decY = false;
                break;
            case SDLK_LEFT:
                mVelX -= DOT_VEL;
                decX = false;
                break;
            case SDLK_RIGHT:
                mVelX += DOT_VEL;
                decX = false;
                break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY += DOT_DEC;
                decY = true;
                break;
            case SDLK_DOWN:
                mVelY -= DOT_DEC;
                decY = true;
                break;
            case SDLK_LEFT:
                mVelX += DOT_DEC;
                decX = true;
                break;
            case SDLK_RIGHT:
                mVelX -= DOT_DEC;
                decX = true;
                break;
        }

    }
}

void Dot::move( SDL_Rect& square, Circle& circle )
{
    //Move the dot left or right
    mPosX += mVelX;
    shiftCollider();
    
    //If the dot collided or went too far to the left or right
    if( ( mCollider.x - mCollider.r < 0 ) || ( mCollider.x + mCollider.r > mScreenWidth ) || checkCollision( mCollider, square ) || checkCollision( mCollider, circle ) )
    {
        //Move back
        mPosX -= mVelX;
        shiftCollider();
    }
    
    //Move the dot up or down
    mPosY += mVelY;
    shiftCollider();
    
    //If the dot collided or went too far up or down
    if( ( mCollider.y - mCollider.r < 0 ) || ( mCollider.y + mCollider.r > mScreenHeight ) || checkCollision( mCollider, square ) || checkCollision( mCollider, circle ) )
    {
        //Move back
        mPosY -= mVelY;
        shiftCollider();
    }
}

void Dot::shiftCollider()
{
    //Align collider to center of dot
    mCollider.x = mPosX + DOT_WIDTH/2;
    mCollider.y = mPosY + DOT_WIDTH/2;
}

Circle& Dot::getCollider()
{
    return mCollider;
}

void Dot::render()
{
    //Show the dot
    mDotTexture->render( mPosX, mPosY);
}

void Dot::render( int camX, int camY )
{
    //Show the dot relative to the camera
    mDotTexture->render( mPosX - camX, mPosY - camY );
}

int Dot::getPosX()
{
    return mPosX;
}

int Dot::getPosY()
{
    return mPosY;
}

