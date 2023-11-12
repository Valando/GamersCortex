#include "MinerClass.hpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
// Constructor definition
MinerClass::MinerClass(int initialValue) : value(initialValue) {
    // Constructor code (if any)
     
}

// Member function definition
void MinerClass::printValue() const {
    cout << "Value: " << value << endl;
}
