#include <iostream>
#include "pixel-circle.h"

int main() {
    unsigned diameter;
    float thickness;
    std::string fill_color, outline_color;
    sf::Window window(sf::VideoMode({800, 600}), "Pixel Circle");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }

    /*
    if (image.saveToFile("circle_image.png")) {
        std::cout << "Image saved as circle_image.png\n";
        return 0;
    } else {
        std::cerr << "Failed to save image.\n";
        return 1;
    }
    */
}
