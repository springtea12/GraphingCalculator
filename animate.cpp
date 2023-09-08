#include "animate.h"

Animate::Animate():sidebar(WORK_PANEL, SIDE_BAR), tb1(15, false), tb2(15, false), tb3(15, false), tb4(15, false), tb5(15, false)
{
    // Creating my window 
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TI-84 Plus CE");
    // Setting my frame limit to update the screen
    window.setFramerateLimit(15);

    // Setting my mouse point size and color
    mouseIn = true;
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Magenta);

    // Loading my font
    if(!font.loadFromFile("C:/Users/Ako/Downloads/Roboto-Thin.ttf"))
        {
            cout << "Animate() Constructor failed to load the font" << endl;
            cin.get();
            exit(-1);
        }

    // Setting a label
    myTextLabel = sf::Text("TI-84", font);
    // Setting the character size
    myTextLabel.setCharacterSize(20);
    // Setting the text style
    myTextLabel.setStyle(sf::Text::Bold);
    // Setting the color
    myTextLabel.setFillColor(sf::Color::Green);
    // Setting the position
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    // Setting up textbox 1
    tb1.setFont(font);
    // Setting Position
    tb1.setPos({1037, 30});
    // Setting Limit
    tb1.setLim(true, 25);
    // Setting the text color
    tb1.setColor(sf::Color::Magenta);
    // textbox 2
    tb2.setFont(font);
    tb2.setPos({1037, 75});
    tb2.setLim(true, 25);
    tb2.setColor(sf::Color::Blue);
    // textbox 3
    tb3.setFont(font);
    tb3.setPos({1037, 120});
    tb3.setLim(true, 25);
    tb3.setColor(sf::Color::Red);
    // textbox 4
    tb4.setFont(font);
    tb4.setPos({1037, 165});
    tb4.setLim(true, 25);
    tb4.setColor(sf::Color::Green);
    // textbox 5
    tb5.setFont(font);
    tb5.setPos({1037, 210});
    tb5.setLim(true, 25);
    tb5.setColor(sf::Color::Yellow);
    // Setting the defualt textbox it will be on
    eqNum = 1;
    // Setting zoom scale to 1
    zoom = .5;
}

void Animate::run()
{
    while(window.isOpen())
    {
        // Check for updates
        processEvents();
        // Update 
        update();
        // Display new screen
        render();
    }
}

void Animate::processEvents()
{
    // Captures events
    sf::Event event;
    // Mouse location 
    float mouseX, mouseY;
    // Keypress check for tab. Will tab over to the next textbox
    // or go back to the beginning if at the end
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(eqNum == 5)
            eqNum = 1;
        else
            eqNum++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(eqNum == 1)
            eqNum = 5;
        else
            eqNum--;
    }
    // To allow the textbox to receive user input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        if(eqNum == 1)
            tb1.setSelected(true);
        else if(eqNum == 2)
            tb2.setSelected(true);
        else if(eqNum == 3)
            tb3.setSelected(true);
        else if(eqNum == 4)
            tb4.setSelected(true);
        else if(eqNum == 5)
            tb5.setSelected(true);
    }
    // To stop the textbox from receiving user input
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        if(eqNum == 1)
        {
            equa1 = tb1.getText();
            tb1.setSelected(false);
        }
        else if(eqNum == 2)
        {
            equa2 = tb2.getText();
            tb2.setSelected(false);
        }
        else if(eqNum == 3)
        {
            equa3 = tb3.getText();
            tb3.setSelected(false);
        }
        else if(eqNum == 4)
        {
            equa4 = tb4.getText();
            tb4.setSelected(false);
        }
        else if(eqNum == 5)
        {
            equa5 = tb5.getText();
            tb5.setSelected(false);
        }
    }
    // Checking for event
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            // Closes window when window is closed
            case sf::Event::Closed:
                window.close();
                break;
            // Mouse is in screen
            case sf::Event::MouseEntered:
                mouseIn = true;
                break;
            // Mouse is out of screen
            case sf::Event::MouseLeft:
                mouseIn = false;
                break;
            // Mouse is moving, will update mouse position
            case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                break;
            // Text is being entered
            case sf::Event::TextEntered:
                if(tb1.getSelected())
                    tb1.typed(event);
                else if(tb2.getSelected())
                    tb2.typed(event);
                else if(tb3.getSelected())
                    tb3.typed(event);
                else if(tb4.getSelected())
                    tb4.typed(event);
                else if(tb5.getSelected())
                    tb5.typed(event);
                break;
            default:
                break;
        }
    }
}

void Animate::update()
{
    if(mouseIn)
    {
        // moving mouse dot
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5, sf::Mouse::getPosition(window).y-5);
    }
}

void Animate::render()
{
    // Clearing the window
    window.clear();
    // Drawing
    Draw();
    // Displaying updated window
    window.display();
}

void Animate::Draw()
{
    /*
    // HEIGHT = 720, WIDTH = 1024
    // X axis will be -8.5 to 8.5
    // Y axis will be -6 to 6
    // Each unit is 60 pixels in length
    */

    // Setting white background for the graph
    sf::RectangleShape bg;
    bg.setSize(sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT));
    bg.setPosition(0,0);
    bg.setFillColor(sf::Color::White);
    window.draw(bg);
    
    // Drawing the mouse point
    if(mouseIn)
    {
        window.draw(mousePoint);
    }

    // Drawing the X Axis
    sf::RectangleShape xAxis;
    xAxis.setSize(sf::Vector2f(WORK_PANEL, 1));
    xAxis.setPosition(0, SCREEN_HEIGHT/2);
    xAxis.setFillColor(sf::Color::Black);
    window.draw(xAxis);

    // Drawing the Y Axis
    sf::RectangleShape yAxis;
    yAxis.setSize(sf::Vector2f(1, SCREEN_HEIGHT));
    yAxis.setPosition(WORK_PANEL / 2, 0);
    yAxis.setFillColor(sf::Color::Black);
    window.draw(yAxis);

    // Possible test case
    //string abc = "sin(x)/2";
    //string abc = "(sin(x))*x";
    //string abc = "abs(x)";

    // Plotting the points for equation 1
    if(equa1.length() > 0)
    {
        ShuntingYard SH1(equa1);
        eq1.set_input(SH1.postfix());
        sf::VertexArray points1(sf::LineStrip, WORK_PANEL);
        points1[WORK_PANEL/2].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);
        for(int i = 0; i < WORK_PANEL/2; i++)
        {
                points1[WORK_PANEL/2 + i].position = sf::Vector2f(WORK_PANEL/2 + i, SCREEN_HEIGHT/2 - eq1(i/60.0)*60);
                points1[WORK_PANEL/2 + i].color = sf::Color::Magenta;
                points1[WORK_PANEL/2 - i].position = sf::Vector2f(WORK_PANEL/2 - i, SCREEN_HEIGHT/2 - eq1(-i/60.0)*60);
                points1[WORK_PANEL/2 - i].color = sf::Color::Magenta;
        }
        window.draw(points1);
    }

    if(equa2.length() > 0)
    {
        ShuntingYard SH2(equa2);
        eq2.set_input(SH2.postfix());
        sf::VertexArray points2(sf::LineStrip, WORK_PANEL);
        points2[WORK_PANEL/2].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);
        for(int i = 0; i < WORK_PANEL/2; i++)
        {
                points2[WORK_PANEL/2 + i].position = sf::Vector2f(WORK_PANEL/2 + i, SCREEN_HEIGHT/2 - eq2(i/60.0)*60);
                points2[WORK_PANEL/2 + i].color = sf::Color::Blue;
                points2[WORK_PANEL/2 - i].position = sf::Vector2f(WORK_PANEL/2 - i, SCREEN_HEIGHT/2 - eq2(-i/60.0)*60);
                points2[WORK_PANEL/2 - i].color = sf::Color::Blue;
        }
        window.draw(points2);
    }

    if(equa3.length() > 0)
    {
        ShuntingYard SH3(equa3);
        eq3.set_input(SH3.postfix());
        sf::VertexArray points3(sf::LineStrip, WORK_PANEL);
        points3[WORK_PANEL/2].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);
        for(int i = 0; i < WORK_PANEL/2; i++)
        {
                points3[WORK_PANEL/2 + i].position = sf::Vector2f(WORK_PANEL/2 + i, SCREEN_HEIGHT/2 - eq3(i/60.0)*60);
                points3[WORK_PANEL/2 + i].color = sf::Color::Red;
                points3[WORK_PANEL/2 - i].position = sf::Vector2f(WORK_PANEL/2 - i, SCREEN_HEIGHT/2 - eq3(-i/60.0)*60);
                points3[WORK_PANEL/2 - i].color = sf::Color::Red;
        }
        window.draw(points3);
    }

    if(equa4.length() > 0)
    {
        ShuntingYard SH4(equa4);
        eq4.set_input(SH4.postfix());
        sf::VertexArray points4(sf::LineStrip, WORK_PANEL);
        points4[WORK_PANEL/2].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);
        for(int i = 0; i < WORK_PANEL/2; i++)
        {
                points4[WORK_PANEL/2 + i].position = sf::Vector2f(WORK_PANEL/2 + i, SCREEN_HEIGHT/2 - eq4(i/60.0)*60);
                points4[WORK_PANEL/2 + i].color = sf::Color::Green;
                points4[WORK_PANEL/2 - i].position = sf::Vector2f(WORK_PANEL/2 - i, SCREEN_HEIGHT/2 - eq4(-i/60.0)*60);
                points4[WORK_PANEL/2 - i].color = sf::Color::Green;
        }
        window.draw(points4);
    }

    if(equa5.length() > 0)
    {
        ShuntingYard SH5(equa5);
        eq5.set_input(SH5.postfix());
        sf::VertexArray points5(sf::LineStrip, WORK_PANEL);
        points5[WORK_PANEL/2].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);
        for(int i = 0; i < WORK_PANEL/2; i++)
        {
                points5[WORK_PANEL/2 + i].position = sf::Vector2f(WORK_PANEL/2 + i, SCREEN_HEIGHT/2 - eq5(i/60.0)*60);
                points5[WORK_PANEL/2 + i].color = sf::Color::Yellow;
                points5[WORK_PANEL/2 - i].position = sf::Vector2f(WORK_PANEL/2 - i, SCREEN_HEIGHT/2 - eq5(-i/60.0)*60);
                points5[WORK_PANEL/2 - i].color = sf::Color::Yellow;
        }
        window.draw(points5);
    }

    // Drawing the sidebar
    sidebar.draw(window);

    // Drawing the textboxes
    tb1.drawTB(window);
    tb2.drawTB(window);
    tb3.drawTB(window);
    tb4.drawTB(window);
    tb5.drawTB(window);
}