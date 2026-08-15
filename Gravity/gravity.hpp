#include <SFML/Graphics.hpp>

// Setting OOP for "player" 

class circlePlayer{
    private:
        sf::CircleShape shape;

        unsigned int    width;
        unsigned int    height;
        float           vertical_speed;
        sf::Vector2f    direction;
        bool            state;

    public:
        // Setting the parameter to The circlePlayer.
        circlePlayer(float radius, float initial_vertical_speed, sf::Vector2f initial_pos){
            shape.setRadius({radius});
            shape.setPosition(initial_pos);
            vertical_speed = initial_vertical_speed;
        };

    // setting const values
        float gravity              =  300.f;
        float fps_max              = 144.f;
        float delta_time           = 1.f / fps_max;
        float vertical_distance    = vertical_speed * delta_time;
        float horizontal_distance  = 200 * delta_time;

        void draw(sf::RenderWindow& window){
            window.draw(shape);
        }

        bool Detecting_state(unsigned int width, unsigned int height) {
            // It checks if the floor was touched.
            sf::Vector2f pos = shape.getPosition();
            float diameter = 2.f * shape.getRadius();
            state = false;

            if ( pos.x < 0) {
                shape.setPosition({0.f, shape.getPosition().y});
                state = true;
            } else if (pos.x >= width - diameter){
                shape.setPosition({width - diameter, shape.getPosition().y});
            } else if (pos.y < 0){
                shape.setPosition({shape.getPosition().x, 0.f});
                state = true;
            } else if (pos.y >= height - diameter){
                shape.setPosition({shape.getPosition().x, height - diameter});
                vertical_speed = 0.f; // It's necessary reset the vertical_speed when somethig touch the floor
                state = true;
            }
            return state;
        } // Detecting state func

        void applying_gravity(bool shape_state){
            // It increments vertical_speed by multiplying gravity by delta time.
            if (!Detecting_state(width, height)){
                vertical_speed += gravity * delta_time;
                shape.move({0.f, vertical_speed * delta_time});
            }
        }// falling func

        void bindingPressed(){
            direction = {0.f, 0.f};

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)){
                direction.x -= 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
                direction.x += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){
                direction.y -= 1.f;
            }
            shape.move({direction * horizontal_distance});
        } // bindingPressed func
};
