//
//  LTexture.hpp
//  SDL_TEST_2
//
//  Created by Richard Lynch on 07/11/2016.
//  Copyright © 2016 Lynch. All rights reserved.
//

#ifndef LTexture_hpp
#define LTexture_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path , SDL_Renderer* gRenderer );
    
    //Deallocates texture
    void free();
    
    //Renders texture at given point
    void render( int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif /* LTexture_hpp */
