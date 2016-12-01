//
//  LTimer.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef LTimer_hpp
#define LTimer_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <sstream>

//The application time based timer
class LTimer
{
public:
    //Initializes variables
    LTimer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    Uint32 getTicks();
    
    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
    
private:
    //The clock time when the timer started
    Uint32 mStartTicks;
    
    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;
    
    //The timer status
    bool mPaused;
    bool mStarted;
};

#endif /* LTimer_hpp */
