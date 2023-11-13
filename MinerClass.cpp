#include "MinerClass.hpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
// Constructor definition
MinerClass::MinerClass(int initialValue) : value(initialValue),vindue(nullptr),renderer(nullptr),h(50),w(100),f(0),counter_x(100),counter_y(100) {
    // initi a video 
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
   
    // Create a winow with dimensions 640x480, and a renderer to render your graphics
    SDL_CreateWindowAndRenderer(640,480,0,&vindue,&renderer);
    // set renderer to draw a black screen for window
    SDL_SetRenderDrawColor(renderer,0,0,0,255);


 // clear renderer
    SDL_RenderClear(renderer);
    GenerateRectangle(counter_x,counter_y,h,w,255); 
     


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

void MinerClass::KeyEvent()
{ 

     Event = new SDL_Event;
      
    while (SDL_PollEvent(Event)) {

  if (Event->type == SDL_KEYDOWN) {
  switch (Event->key.keysym.sym) {
    
    case SDLK_UP: 
    GenerateRectangle(counter_x,counter_y,h,w,0); // delete previous rectangel, eg. make it black
    counter_y--;
    GenerateRectangle(counter_x,counter_y,h,w,255);
    cout << "Up" << endl;
    break;
    
    case SDLK_DOWN:
    GenerateRectangle(counter_x,counter_y,h,w,0);
    counter_y++;
    GenerateRectangle(counter_x,counter_y,h,w,255); 
    cout << "Down" << endl;
    break;
    
    
    case SDLK_LEFT:
    GenerateRectangle(counter_x,counter_y,h,w,0); 
    counter_x--;
    GenerateRectangle(counter_x,counter_y,h,w,255);
    cout << "Left" << endl;
    break;
    
    case SDLK_RIGHT:
    GenerateRectangle(counter_x,counter_y,h,w,0); 
    counter_x++;
    GenerateRectangle(counter_x,counter_y,h,w,255);
    cout << "Right" << endl;
    break;
    
    case SDLK_ESCAPE: // exit while loop in main by setting flag f
    f =1;
    break;
    }
    }

  
}
}

int MinerClass::Fvalue()
{
    return f;
}
