#include <iostream>
#include "pixel-circle.h"

int main() {
    float a = 0, b = 0, thickness = 0;
    sf::Color fill_color = sf::Color::Black, outline_color;
    std::string line;
    bool fill_color_entered = false;

    std::cout << "Dimensions: ";
    std::getline(std::cin, line);
    unsigned long pos = 0;
    pxl::skip_empty(line, pos);
    try {
        a = pxl::read_num(line, pos);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: Invalid number! Please input a valid number." << std::endl;
        return 1;
    }
    pxl::skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            b = pxl::read_num(line, pos);
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: Invalid number! Please input a valid number or keep the field empty." << std::endl;
            return 1;
        }
    } else {
        b = a;
    }

    std::cout << "Fill color: ";
    std::getline(std::cin, line);
    pos = 0;
    pxl::skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            fill_color = pxl::read_color(line, pos);
            fill_color_entered = true;
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: Invalid color! Please input a valid hex value or keep the field empty." << std::endl;
            return 1;
        }
    }

    std::cout << "Outline thickness: ";
    std::getline(std::cin, line);
    pos = 0;
    pxl::skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            thickness = pxl::read_num(line, pos);
            if (!fill_color_entered) {
                fill_color = sf::Color::Transparent;
            }
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: Invalid number! Please input a valid number or keep the field empty." << std::endl;
            return 1;
        }
    }

    std::cout << "Outline color: ";
    std::getline(std::cin, line);
    pos = 0;
    pxl::skip_empty(line, pos);
    try {
        outline_color = pxl::read_color(line, pos);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: Invalid color! Please input a valid hex value or keep the field empty." << std::endl;
        return 1;
    }

    a /= 2;
    b /= 2;
    sf::Image image({static_cast<unsigned>(2 * a + thickness), static_cast<unsigned>(2 * b + thickness)},
                    sf::Color::Transparent);
    pxl::fill(image, a, b, fill_color);
    pxl::outline(image, a, b, thickness, outline_color);

    const std::string filename = "circle.png";
    if (!image.saveToFile(filename)) {
        std::cerr << "Failed to save image.\n";
        return 1;
    }
    std::cout << "Image saved as \"" << filename << "\".\n";
    return 0;
}
