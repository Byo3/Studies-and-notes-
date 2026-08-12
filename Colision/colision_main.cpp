#include <SFML/Graphics.hpp>
// It is a basic colission simulator.

int main()
{
    unsigned int window_width  = 800;
    unsigned int window_height = 600;
    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "Colision");
    window.setFramerateLimit(60);

    // drawing a circle.
    float circle_radius = 25.f; // Remember, which is necessary to multiply by 2*radius
    sf::CircleShape player(circle_radius);
    player.setPosition({20.f, 20.f});
    player.setFillColor(sf::Color(23, 115, 82)); // To select a specific color it is used RGB  

    // drawing a square.
    sf::RectangleShape wall({100.f, 50.f});
    wall.setPosition(window.getView().getSize() / 2.f); // It gets the size (width, height) of the window dividing by 2

    sf::RectangleShape triangle({50.f, 100.f});
    triangle.setPosition({50.f, 400});

    // Setting fps and delta time.

    float fps_max = 60.f;
    float dt_min  = 1.f / fps_max;

        // Defining the default presets
    float speed    = 200.f;
    float distance = speed * dt_min;

    // Window loop
    while (window.isOpen()){

        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            } // closing window
        }

        sf::Vector2f direction({0.f, 0.f}); // It always necessary reset the direction

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)){
            direction.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
            direction.x += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){
            direction.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)){
            direction.y += 1.f;
        }

            // it normalizes the direction when two buttons are pressed
        if  (direction.x != 0 || direction.y != 0){ 
            direction = direction.normalized();
            player.setFillColor(sf::Color(100, 226, 180));  
        } else {
            player.setFillColor(sf::Color(23, 115, 82));
        }

        // Store the player's previous position before updating to the new one
        sf::Vector2f previous_direction = player.getPosition();

        // it makes the player move.
        player.move(direction * distance);

        // Setting limits so the player doesn't cross the borders

        if (player.getPosition().x < 0)
        {
            player.setPosition({0.f, player.getPosition().y});
        }
        if (player.getPosition().x > window_width - (circle_radius * 2))
        {
            player.setPosition({window_width - (circle_radius * 2), player.getPosition().y});
        }
        if (player.getPosition().y < 0)
        {
            player.setPosition({player.getPosition().x, 0.f});
        }
        if (player.getPosition().y > window_height - (circle_radius * 2)) 
        {
            player.setPosition({player.getPosition().x, window_height - (circle_radius * 2)});
        }

        if (player.getGlobalBounds().findIntersection(wall.getGlobalBounds()) || 
            player.getGlobalBounds().findIntersection(triangle.getGlobalBounds()))
        {
            player.setPosition(previous_direction);
        }

        window.clear();
        // It draws the objects on the screen.
        window.draw(triangle);
        window.draw(player);    
        window.draw(wall);

        window.display();
    } // main while loop
}// main func
