#include <iostream>
#include "pixel-circle.h"

bool is_digit(const char c) {
    return c >= '0' && c <= '9';
}

void skip_empty(const std::string &line, unsigned long &pos) {
    if (pos >= line.length())
        return;
    while (line[pos] == ' ')
        pos++;
}

sf::Color read_color(const std::string &line, unsigned long &pos) {
    if (pos >= line.length())
        return sf::Color::Black;
    if (line[pos] == '#')
        pos++;
    return pxl::hex_to_rgb(line.substr(pos, 6));
}

float read_num(const std::string &line, unsigned long &pos) {
    if (pos >= line.length()) return 0;
    if (!is_digit(line[pos])) {
        std::string invalid_res;
        while (pos < line.length() && line[pos] != ' ') {
            invalid_res += line[pos];
            pos++;
        }
        throw std::invalid_argument(invalid_res);
    }
    float res = 0;
    while (is_digit(line[pos])) {
        res = res * 10 + static_cast<float>(line[pos] - '0');
        pos++;
    }
    if (line[pos] == '.') {
        pos++;
        float exp = 10;
        while (is_digit(line[pos])) {
            res += static_cast<float>(line[pos] - '0') / exp;
            exp *= 10;
            pos++;
        }
    }
    return res;
}

int main() {
    float a = 0, b = 0, thickness = 0;
    sf::Color fill_color = sf::Color::Black, outline_color;
    std::string line;
    bool fill_color_entered = false;

    std::cout << "Dimensions: ";
    std::getline(std::cin, line);
    unsigned long pos = 0;
    skip_empty(line, pos);
    try {
        a = read_num(line, pos);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: Invalid number! Please input a valid number." << std::endl;
        return 1;
    }
    skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            b = read_num(line, pos);
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
    skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            fill_color = read_color(line, pos);
            fill_color_entered = true;
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: Invalid color! Please input a valid hex value or keep the field empty." << std::endl;
            return 1;
        }
    }

    std::cout << "Outline thickness: ";
    std::getline(std::cin, line);
    pos = 0;
    skip_empty(line, pos);
    if (pos < line.length()) {
        try {
            thickness = read_num(line, pos);
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
    skip_empty(line, pos);
    try {
        outline_color = read_color(line, pos);
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
