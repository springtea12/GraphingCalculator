#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../sconst/sconst.h"

using namespace std;

class Sidebar 
{
    public:
        // CSTOR
        Sidebar();
        Sidebar(float left, float width);
        // Draw function
        void draw(sf::RenderWindow& window);
        // Accessor
        string& operator [] (int index);
    
    private:
        // To store strings in sidebar
        vector<string> items;
        // Sidebar rectangle
        sf::RectangleShape rect;
        // For drawing text
        sf::Font font;
        // Drawing strings 
        sf::Text sb_text;

        float _left;
        float _width;
};

#endif // SIDEBAR_H