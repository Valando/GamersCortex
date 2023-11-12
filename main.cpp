#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
    // define window and renderer
    SDL_Window* vindue = nullptr;
    SDL_Renderer* renderer = nullptr;
    
    // initialize video
    SDL_Init(SDL_INIT_VIDEO);
    
    // create window and rendere instance
    SDL_CreateWindowAndRenderer(640,480,0,&vindue,&renderer);
    
    // sætter renderer til at tegne sort bagggrund og clearer den
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    // sætter renderer til at tegne hvidt i midten
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderDrawPoint(renderer,640/2,480/2);
    
    // sæt pixel i windue via rendere
    SDL_RenderPresent(renderer);  
  
     // delay så man kan nå at se det
    SDL_Delay(5000);
  
    // release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(vindue);
    
    // Quit SDL
    SDL_Quit();
    return 0;
}
