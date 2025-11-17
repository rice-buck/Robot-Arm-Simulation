#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>

int main(){

    //create window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), ":)", sf::State::Windowed, settings);
    
    //three points
    sf::CircleShape p0;
    p0.setFillColor(sf::Color(0,170, 255));     
    sf::CircleShape p1;
    p1.setFillColor(sf::Color(0,170, 255));
    sf::CircleShape p2;
    p2.setFillColor(sf::Color(0,170, 255));
    sf::CircleShape p3;
    p3.setFillColor(sf::Color(0,170, 255));


    //create lines
    sf::RectangleShape line1;
    line1.setFillColor(sf::Color(0, 170, 255));
    sf::RectangleShape line2;
    line2.setFillColor(sf::Color(0, 170, 255));
    sf::RectangleShape line3;
    line3.setFillColor(sf::Color(0, 170, 255));

    //lengths and angles
    float L1 = 100;
    float L2 = 75;
    float L3 = 50;

    float theta1 = 30;
    float theta2 = -20 * (M_PI / 180.0);
    float theta3 = 45 * (M_PI / 180.0);

    
//events
    while (window.isOpen()){    
         while (std::optional event = window.pollEvent())
{
    // when close button is clicked
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }

    // when window is resized
    if (const auto* resized = event->getIf<sf::Event::Resized>())
    {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
    }
}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
        theta1 += 0.001f;
        //std::cout << "Theta 1: " << theta1 * (180.0 / M_PI) << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        theta1 -= 0.001f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        theta2 += 0.001f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        theta2 -= 0.001f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
        theta3 += 0.001f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){
        theta3 -= 0.001f;
    }

        //size of window    
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);
        float window_min = std::min(window_w, window_h);

        //parameters 
        float radius = 0.02f * window_min;
        float width = radius / 2;
        float x_old;
        float y_old;
        

        //fill window with color
        window.clear(sf::Color(127, 127, 127));

        
        //set dot radius and origin
        p0.setRadius(radius);
        p0.setOrigin({radius, radius});

        p1.setRadius(radius);
        p1.setOrigin({radius, radius});

        p2.setRadius(radius);
        p2.setOrigin({radius, radius});

        p3.setRadius(radius);
        p3.setOrigin({radius, radius});

        //set line size and origin 
        line1.setSize({100.f, width});
        line1.setOrigin({0.f, width/2});

        line2.setSize({100.f, width});
        line2.setOrigin({0.f, width/2});

        line3.setSize({100.f, width});
        line3.setOrigin({0.f, width/2});

            //draw dots
            float p0x = 400.f;
            float p0y = 300.f;
            p0.setPosition({p0x, p0y});
            window.draw(p0);
            float p1x = p0x + (std::cos(theta1) * L1); //486
            float p1y = p0y + (std::sin(theta1) * L1); //350    
            p1.setPosition({p1x, p1y});
            window.draw(p1);
            float p2x = p1x + (std::cos(theta1 + theta2) * L2); //560
            float p2y = p1y + (std::sin(theta1 + theta2) * L2); //363
            p2.setPosition({p2x, p2y});
            window.draw(p2);
            float p3x = p2x + (std::cos(theta1 + theta2 + theta3) * L3); //588
            float p3y = p2y + (std::sin(theta1 + theta2 + theta3) * L3); //403
            p3.setPosition({p3x, p3y});
            window.draw(p3);

            //draw lines
            line1.setSize({L1, width});
            line1.setRotation(sf::radians(theta1));
            line1.setPosition({p0x, p0y});
            window.draw(line1);

            line2.setSize({L2, width});
            line2.setRotation(sf::radians(theta1 + theta2));
            line2.setPosition({p1x, p1y});
            window.draw(line2);

            line3.setSize({L3, width});
            line3.setRotation(sf::radians(theta1 + theta2 + theta3));
            line3.setPosition({p2x, p2y});
            window.draw(line3);


        //display 
        window.display();
    }


    return 0; 
}