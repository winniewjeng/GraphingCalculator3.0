
#ifndef Sidebar_hpp
#define Sidebar_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Constants.hpp"

using namespace std;
using namespace sf;

class Sidebar {
    
public:
    // CTOR -- set up the sidebar rectangle
    Sidebar();
    void draw(RenderWindow& window);
    // NOT YET IMPLEMENTED
    string& operator [](int index);
    
private:
    
    RectangleShape bar; //sidebar rectangle
    vector<string> items; //strings to place on the sidebar
    Font font; //used to draw text
    Text sb_text; //used to draw strings on the window object
    float _left;
    float _width;
};

#endif /* Sidebar_hpp */
