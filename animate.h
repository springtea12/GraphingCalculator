#ifndef ANIMATE_H
#define ANIMATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../sidebar/sidebar.h"
#include "../sconst/sconst.h"
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"
#include "../textbox/textbox.h"

using namespace std;

class Animate {
    public: 
        // CSTOR
        Animate();
        // Run the calculator 
        void run();
        // Check for events
        void processEvents();
        // Update with new values
        void update();
        // Render new shapes
        void render();
        // Draw shapes
        void Draw();
    
    private:
        // General window variables
        sf::RenderWindow window;
        sf::CircleShape mousePoint;
        // Font style
        sf::Font font;
        // Calculator label
        sf::Text myTextLabel;
        bool mouseIn;
        // Sidebar
        Sidebar sidebar;
        // Textbox to hold equations
        Textbox tb1, tb2, tb3, tb4, tb5;
        // Equations
        RPN eq1, eq2, eq3, eq4, eq5;
        // Int value for which equation is being modified
        int eqNum;
        // Equation received from user
        string equa1, equa2, equa3, equa4, equa5;
        // Zoom scale
        double zoom;
};

#endif //ANIMATE_H