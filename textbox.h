#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class Textbox{
    public:
        // CSTOR
        Textbox(){};

        Textbox(int size, bool sel)
        {
            tb.setCharacterSize(size);
            selected = sel;
            if(sel)
                tb.setString("_");
            else
                tb.setString("");
            tb.setStyle(sf::Text::Bold);
        }
        
        // Color setter
        void setColor(sf::Color color)
        {
            tb.setFillColor(color);
        }

        // Font setter
        void setFont(sf::Font &font)
        {
            tb.setFont(font);
        }

        // Position setter
        void setPos(sf::Vector2f pos)
        {
            tb.setPosition(pos);
        }

        // Limit setter
        void setLim(bool haslim)
        {
            limit = haslim;
        }

        // Limit setter and if theres a limit
        void setLim(bool haslim, int limit)
        {
            limit = haslim;
            lim = limit;
        }

        // Checks if the textbox is selected and whether to get text or not
        void setSelected(bool select)
        {
            selected = select;
            if(!select)
            {
                string a = text.str();
                string abc = "";
                for(int i = 0; i < a.length(); i++)
                {
                    abc += a[i];
                }
                tb.setString(abc);
            }
        }

        // Returns selected status
        bool getSelected()
        {
            return selected;
        }

        // Gets text entered in the textbox
        string getText()
        {
            return text.str();
        }

        // Draws the textbox
        void drawTB(sf::RenderWindow &window)
        {
            window.draw(tb);
        }

        // Converts the inputted keys into char
        void typed(sf::Event input)
        {
            if(selected)
            {
                int charTyped = input.text.unicode;
                if(charTyped < 128)
                {
                    if(limit)
                    {
                        if(text.str().length() <= lim)
                        {
                            inp(charTyped);
                        }
                        else if(text.str().length() > limit && charTyped == 8)
                        {
                            delLast();
                        }
                    }
                    else
                        inp(charTyped);
                }
            }
        }

    private:
        sf::Text tb;
        ostringstream text;
        bool selected = false;
        bool limit = false;
        int lim;

        // Shows user input
        void inp(int chr)
        {
            if(chr != 8 && chr != 13)
            {
                text << static_cast<char>(chr);
            }
            else if(chr == 8)
            {
                if(text.str().length()>0)
                {
                    delLast();
                }
            }
            tb.setString(text.str() + "_");
        }

        // Deletes last typed char
        void delLast()
        {
            string a = text.str();
            string abc = "";
            for(int i = 0; i < a.length()-1; i++)
            {
                abc += a[i];
            }
            text.str("");
            text << abc;
            tb.setString(text.str());
        }
};

#endif // TEXTBOX_H