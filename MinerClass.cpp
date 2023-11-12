#include "MinerClass.hpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
// Constructor definition
MinerClass::MinerClass(int initialValue) : value(initialValue),vindue(nullptr),renderer(nullptr) {
    // initi a video 
    SDL_Init(SDL_INIT_VIDEO);

    // Create a winow with dimensions 640x480, and a renderer to render your graphics
    SDL_CreateWindowAndRenderer(640,480,0,&vindue,&renderer);
    // set renderer to draw a black screen for window
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

 // clear renderer
    SDL_RenderClear(renderer);

}

// Member function definition
void MinerClass::printValue() const {
    cout << "Value: " << value << endl;
}

void MinerClass::GenerateRectangle(int xr, int yr, int hr, int wr)
{
     
     // set color of new render, this time white
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
     
     // define rectangle shape from rectangle object defined in hpp
      rect;
      rect->x = xr;
      rect->y = yr;
      rect->w = wr;
      rect->h= hr;
      // draw rectangle
      SDL_RenderDrawRect(renderer,rect);
      // present render
      SDL_RenderPresent(renderer);  

 

}
