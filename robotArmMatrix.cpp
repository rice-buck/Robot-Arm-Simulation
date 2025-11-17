#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
 #include <string>
#include <sstream>
 #include <iomanip>
#include "Matrix.hpp"
#include "Vector.hpp"

int main(){

    //create window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode({800, 600}), ":)", sf::State::Windowed, settings);

    //view for arm coordinates 
    sf::View worldView;
    worldView.setCenter(sf::Vector2f(0.f, 0.f)); // (0,0) is now center of screen
    worldView.setSize(sf::Vector2f(800.f, -600.f)); // NEGATIVE height = flip Y axis

    //view for text
    sf::View textView;
    textView.setCenter(sf::Vector2f(0.f, 0.f)); 
    textView.setSize(sf::Vector2f(800.f, 600.f)); 

    //three dots
    sf::CircleShape d0;
    d0.setFillColor(sf::Color(0,170, 255));     
    sf::CircleShape d1;
    d1.setFillColor(sf::Color(0,170, 255));
    sf::CircleShape d2;
    d2.setFillColor(sf::Color(0,170, 255));
    sf::CircleShape d3;
    d3.setFillColor(sf::Color(0,170, 255));


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

    float theta1 = 30 * (M_PI / 180.0);
    float theta2 = -20 * (M_PI / 180.0);
    float theta3 = 45 * (M_PI / 180.0);

    //load font for text
    sf::Font font("/Users/rhysbuckeye/Library/Fonts/DS-DIGIT.TTF");
    
//events
    while (window.isOpen()){    
         while (std::optional event = window.pollEvent())
{
    // when close button is clicked
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }

}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
        theta1 += 0.0005f;
        std::cout << "Theta 1: " << theta1 * (180.0 / M_PI) << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        theta1 -= 0.0005f;
        std::cout << "Theta 1: " << theta1 * (180.0 / M_PI) << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        theta2 += 0.0005f;
        std::cout << "Theta 2: " << theta2 * (180.0 / M_PI) << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        theta2 -= 0.0005f;
        std::cout << "Theta 2: " << theta2 * (180.0 / M_PI) << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
        theta3 += 0.0005f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){
        theta3 -= 0.0005f;
    }

    //create text for joint angles display
    sf::Text jointAngleOneTxt(font, "", 20);
    jointAngleOneTxt.setPosition({-400.f, -300.f});
    std::ostringstream ss1;            // using string stream to be able to set decimal precision
    ss1 << std::fixed << std::setprecision(2) << (theta1 * 180.0 / M_PI);
    jointAngleOneTxt.setString("Joint angle 1: " + ss1.str());


    sf::Text jointAngleTwoTxt(font, "", 20);
    jointAngleTwoTxt.setPosition({-400.f, -250.f});
    std::ostringstream ss2;
    ss2 << std::fixed << std::setprecision(2) << ((theta1 + theta2) * 180.0 / M_PI);
    jointAngleTwoTxt.setString("Joint angle 2: " + ss2.str());


    sf::Text jointAngleThreeTxt(font, "", 20);
    jointAngleThreeTxt.setPosition({-400.f, -200.f});
    std::ostringstream ss3;
    ss3 << std::fixed << std::setprecision(2) << ((theta1 + theta2 + theta3) * 180.0 / M_PI);
    jointAngleThreeTxt.setString("Joint angle 3: " + ss3.str());


        //size of window    
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);
        float window_min = std::min(window_w, window_h);

        //parameters 
        float radius = 0.02f * window_min;
        float width = radius / 2;
        

        //fill window with color
        window.clear(sf::Color(127, 127, 127));

        
        //set dot radius and origin
        d0.setRadius(radius);
        d0.setOrigin({radius, radius});

        d1.setRadius(radius);
        d1.setOrigin({radius, radius});

        d2.setRadius(radius);
        d2.setOrigin({radius, radius});

        d3.setRadius(radius);
        d3.setOrigin({radius, radius});

        //set line size and origin 
        line1.setSize({100.f, width});
        line1.setOrigin({0.f, width/2});

        line2.setSize({100.f, width});
        line2.setOrigin({0.f, width/2});

        line3.setSize({100.f, width});
        line3.setOrigin({0.f, width/2});

        // Base point
        Vector3 p0(0, 0, 1);

    //Build T01
    float c1 = std::cos(theta1);
    float s1 = std::sin(theta1);

    float T01data[3][3] = {
        { c1, -s1, L1 * c1 },
        { s1,  c1, L1 * s1 },
        { 0,   0,  1 }
    };
    Matrix3x3 T01(T01data);

    //Build T12
    float c2 = std::cos(theta2);
    float s2 = std::sin(theta2);

    float T12data[3][3] = {
        { c2, -s2, L2 * c2 },
        { s2,  c2, L2 * s2 },
        { 0,   0,  1 }
    };
    Matrix3x3 T12(T12data);


    //Build T23
    float c3 = std::cos(theta3);
    float s3 = std::sin(theta3);

    float T23data[3][3] = {
        { c3, -s3, L3 * c3 },
        { s3,  c3, L3 * s3 },
        { 0,   0,  1 }
    };

    Matrix3x3 T23(T23data);

    //Compute cumulative transforms
    Matrix3x3 T02 = T01 * T12;
    Matrix3x3 T03 = T02 * T23;

    //Compute joint positions
    Vector3 p1 = T01 * p0;
    Vector3 p2 = T02 * p0;
    Vector3 p3 = T03 * p0;

    //window with inverted y for plotting
    window.setView(worldView);

            //draw dots
            float p0x = p0.data[0];
            float p0y = p0.data[1];
            d0.setPosition({p0x, p0y});
            window.draw(d0);
            float p1x = p1.data[0];
            float p1y = p1.data[1]; 
            d1.setPosition({p1x, p1y});
            window.draw(d1);
            float p2x = p2.data[0];
            float p2y = p2.data[1];
            d2.setPosition({p2x, p2y});
            window.draw(d2);
            float p3x = p3.data[0];
            float p3y = p3.data[1];
            d3.setPosition({p3x, p3y});
            window.draw(d3);

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

        
        //sets y back to normal for text
        window.setView(textView); 

        // draw text
        window.draw(jointAngleOneTxt);
        window.draw(jointAngleTwoTxt);
        window.draw(jointAngleThreeTxt);


        //display 
        window.display();
    }


    return 0; 
}