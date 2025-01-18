#include <iostream>
#include "pixel-circle.h"

int main() {
    unsigned diameter;
    float thickness;
    std::string fill_color, outline_color;
    std::cin >> diameter >> fill_color >> thickness >> outline_color;
    sf::Image image(sf::Vector2u(diameter + thickness, diameter + thickness), sf::Color::White);
    fill(image, (float) diameter / 2, hex_to_rgb(fill_color));
    outline(image, (float) diameter / 2, thickness, hex_to_rgb(outline_color));

    if (image.saveToFile("circle_image.png")) {
        std::cout << "Image saved as circle_image.png\n";
        return 0;
    } else {
        std::cerr << "Failed to save image.\n";
        return 1;
    }
}
