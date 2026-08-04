#include <SFML/Graphics.hpp>
#include <array>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 400}), "RGB window");
    window.setFramerateLimit(3);
    std::array<sf::Color, 15> hexColors = {
      // --- Vivid / Vibrant ---
        sf::Color(0xE7, 0x4C, 0x3C), // 1. Crimson Red    (#E74C3C)
        sf::Color(0xE6, 0x7E, 0x22), // 2. Pumpkin Orange (#E67E22)
        sf::Color(0xF1, 0xC4, 0x0F), // 3. Sunflower Yellow (#F1C40F)
        sf::Color(0x2E, 0xCC, 0x71), // 4. Emerald Green  (#2ECC71)
        sf::Color(0x34, 0x98, 0xDB), // 5. Peter River Blue (#3498DB)
        sf::Color(0x9B, 0x59, 0xB6), // 6. Amethyst Purple (#9B59B6)

        // --- Pastels ---
        sf::Color(0xFF, 0x9A, 0x9E), // 7. Soft Rose Pink (#FF9A9E)
        sf::Color(0xA8, 0xE6, 0xCF), // 8. Mint Green     (#A8E6CF)
        sf::Color(0xDC, 0xD6, 0xCD), // 9. Warm Gray      (#DCD6CD)

        // --- Dark / Deep ---
        sf::Color(0x1A, 0x25, 0x2C), // 10. Midnight Dark  (#1A252C)
        sf::Color(0x2C, 0x3E, 0x50), // 11. Navy Slate     (#2C3E50)
        sf::Color(0x4A, 0x14, 0x8C), // 12. Deep Indigo    (#4A148C)

        // --- Neon / Bright ---
        sf::Color(0x00, 0xFF, 0xCC), // 13. Neon Cyan      (#00FFCC)
        sf::Color(0xFF, 0x00, 0x7F), // 14. Hot Pink       (#FF007F)
        sf::Color(0xCC, 0xFF, 0x00)  // 15. Electric Lime  (#CCFF00)
    };
    std::size_t color_index = 0;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        // clear the window with black color
        sf::Color select_color = hexColors[color_index];
        window.clear(select_color);
        window.display();

        color_index = (color_index + 1) % hexColors.size();
    }// main while
}