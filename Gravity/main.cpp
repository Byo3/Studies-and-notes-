#include <SFML/Graphics.hpp>
#include "gravity.hpp"

// Creating a 2D gravity simulation

int main(){
    unsigned int width   = 800;
    unsigned int height  = 600;
    sf::RenderWindow window(sf::VideoMode({width, height}), "Gravity");
    window.setFramerateLimit(144);
    circlePlayer player(25.f, 0.f, {width / 2.f, 0.f});
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        window.clear();
        player.draw(window);

        player.bindingPressed();
        player.applying_gravity(player.Detecting_state(width, height));

        window.display();
        

    } // main while

}