#include "MinerClass.hpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
// Constructor definition
MinerClass::MinerClass(int initialValue) : value(initialValue),vindue(nullptr),renderer(nullptr),h(50),w(100) {
    // initi a video 
    SDL_Init(SDL_INIT_VIDEO);

    // Create a winow with dimensions 640x480, and a renderer to render your graphics
    SDL_CreateWindowAndRenderer(640,480,0,&vindue,&renderer);
    // set renderer to draw a black screen for window
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

 // clear renderer
    SDL_RenderClear(renderer);

}
// Destructor definition
MinerClass::~MinerClass() {
    // Cleanup resources in the destructor
    if (rect != nullptr) {
        delete rect;
    }
    // Close SDL components and perform other cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(vindue);
    SDL_Quit();
}
// Member function definition
void MinerClass::printValue() const {
    cout << "Value: " << value << endl;
}

void MinerClass::GenerateRectangle(int xr, int yr, int hr, int wr,int c)
{
     
     // set color of new render, this time white
    SDL_SetRenderDrawColor(renderer,c,c,c,255);
     rect = new SDL_Rect;
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

void MinerClass::MovingRectangle(int x)
{
    int counter = x;
  
    for (size_t i = 0; i < counter; i++)
    {
    GenerateRectangle(i,150,h,w,255);
    SDL_Delay(50);
    GenerateRectangle(i,150,h,w,0);
    }
    
    
   
}
