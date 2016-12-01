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
#include <SDL2_ttf/SDL_ttf.h>
#include <sstream>

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture(SDL_Renderer* Renderer, Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF);
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path );
    
    //Deallocates texture
    void free();
    
    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    SDL_Renderer* mRenderer;
    
    //Image dimensions
    int mWidth;
    int mHeight;
    Uint8 R, G, B;
};


#endif /* LTexture_hpp */
