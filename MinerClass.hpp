#ifndef MINERCLASS_HPP
#define MINERCLASS_HPP
#include <SDL2/SDL.h>

class MinerClass {
public:
    // Constructor
    MinerClass(int initialValue);
    SDL_Rect* rect;

    // Member function
    void printValue() const;

       // makes a rectangle r on the x,y plane, with widh w, and height h
    void GenerateRectangle(int xr, int yr, int wr, int hr);
    
private:
    // Private data member
    int value;
    SDL_Window* vindue ;
    SDL_Renderer* renderer;
    
};

#endif // MINERCLASS_HPP
