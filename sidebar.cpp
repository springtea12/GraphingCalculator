#include "sidebar.h"

Sidebar::Sidebar(){}

Sidebar::Sidebar(float left, float width):_left(left), _width(width)
{
    // Reserving spots in vector
    items.reserve(50);

    // Creating the sidebar
    // Setting color
    rect.setFillColor(sf::Color(30,30,30));
    // Setting position
    rect.setPosition(sf::Vector2f(left, 0));
    // Setting size
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));

    // Loading font
    if(!font.loadFromFile("C:/Users/Ako/Downloads/Roboto-Thin.ttf"))
    {
        cout << "Sidebar() Constructor failed to load the font" << endl;
        cin.get();
        exit(-1);
    }

    // Setting text font
    sb_text.setFont(font);
    // Setting text size
    sb_text.setCharacterSize(18);
    // Making text bold
    sb_text.setStyle(sf::Text::Bold);
    // Setting text color
    sb_text.setFillColor(sf::Color::Yellow);
}

void Sidebar::draw(sf::RenderWindow& window)
{
    // line spacing
    const double VERTICAL_LINE_SPACING = 5.0;
    // Left margin distance
    const double LEFT_MARGIN = 10.0;
    // Drawing the sidebar
    window.draw(rect);
    float height = 10;

    // Drawing text on the string for the sidebar
    for(vector<string>::iterator it = items.begin(); it!= items.end(); it++)
    {
        bool blank = false;
        if(strlen(it->c_str()) == 0)
        {
            blank = true;
            sb_text.setString("BLANK");
        }
        else
            sb_text.setString(it->c_str());
        
        sb_text.setPosition(sf::Vector2f(_left + LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;
        if(!blank)
            window.draw(sb_text);
    }
}

string& Sidebar::operator [] (int index)
{
    // returns item at the given index
    return items[index];
}