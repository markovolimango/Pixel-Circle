#include <iostream>
#include "pixel-circle.h"

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void skip_empty(std::string str, unsigned long &pos) {
    if (pos >= str.length()) return;
    while (str[pos] == ' ') pos++;
}

template<typename T>
T read_num(std::string str, unsigned long &pos) {
    if (pos >= str.length()) return 0;
    if (!is_digit(str[pos])) {
        std::string invalid_number;
        while (pos < str.length() && str[pos] != ' ') {
            invalid_number += str[pos];
            pos++;
        }
        throw std::invalid_argument(invalid_number);
    }
    T res = 0;
    while (is_digit(str[pos])) {
        res = res * 10 + (str[pos] - '0');
        pos++;
    }
    if (str[pos] == '.') {
        pos++;
        T exp = 10;
        while (is_digit(str[pos])) {
            res += (T) (str[pos] - '0') / exp;
            exp *= 10;
            pos++;
        }
    }
    return res;
}


int main() {
    unsigned diameter = 0;
    float thickness = 0;
    sf::Color fill_color = sf::Color::Black, outline_color = sf::Color::Black;
    bool fill_color_entered = false;

    std::string line;
    std::getline(std::cin, line);
    unsigned long n = line.length(), i = 0;

    try {
        diameter = read_num<unsigned>(line, i);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: \"" << e.what() << "\" is not a valid number." << std::endl;
        return 1;
    }

    skip_empty(line, i);

    if (i < n && line[i] == '#') {
        try {
            fill_color = hex_to_rgb(line.substr(i, 7));
            fill_color_entered = true;
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: \"" << e.what() << "\" is not a valid HEX value." << std::endl;
            return 1;
        }
        fill_color_entered = true;
        i += 7;
    }

    skip_empty(line, i);

    if (!fill_color_entered && i < n)
        fill_color = sf::Color::White;
    try {
        thickness = read_num<float>(line, i);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: \"" << e.what() << "\" is not a valid number." << std::endl;
        return 1;
    }

    skip_empty(line, i);
    if (i < n && line[i] == '#') {
        try {
            outline_color = hex_to_rgb(line.substr(i, 7));
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: \"" << e.what() << "\" is not a valid HEX value." << std::endl;
            return 1;
        }
    }

    sf::Image image({diameter + static_cast<unsigned>(thickness), diameter + static_cast<unsigned>(thickness)},
                    sf::Color::White);
    float radius = static_cast<float>(diameter) / 2;
    fill(image, radius, fill_color);
    outline(image, radius, thickness, outline_color);

    if (image.saveToFile("circle_image.png")) {
        std::cout << "Image saved as circle_image.png\n";
        return 0;
    } else {
        std::cerr << "Failed to save image.\n";
        return 1;
    }
}
