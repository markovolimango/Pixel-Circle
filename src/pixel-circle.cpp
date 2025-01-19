#include <cmath>
#include "pixel-circle.h"

namespace pxl {
    sf::Color hex_to_rgb(std::string hex) {
        sf::Color c;
        c.r = stoi(hex.substr(0, 2), nullptr, 16);
        c.g = stoi(hex.substr(2, 2), nullptr, 16);
        c.b = stoi(hex.substr(4, 2), nullptr, 16);
        c.a = 255;
        return c;
    }

    sf::Vector2f pixel_center(sf::Vector2<unsigned> pixel_pos) {
        return {(float) pixel_pos.x + 0.5f, (float) pixel_pos.y + 0.5f};
    }

    float eq(sf::Vector2<unsigned> pixel_pos, sf::Vector2<float> center, float a, float b) {
        sf::Vector2 coords = pixel_center(pixel_pos) - center;
        return coords.x * coords.x / (a * a) + coords.y * coords.y / (b * b);
    }


    void fill(sf::Image &image, const float a, float b, const sf::Color color) {
        unsigned const width = image.getSize().x, height = image.getSize().y;
        sf::Vector2 const center((float) width / 2, (float) height / 2);

        for (unsigned x = 0; x < width; x++) {
            for (unsigned y = 0; y < height; y++) {
                sf::Vector2 p(x, y);
                sf::Vector2<float> q = pixel_center(p) - center;
                if (eq(p, center, a, b) <= 1) {
                    image.setPixel(p, color);
                }
            }
        }
    }

    void outline(sf::Image &image, const float a, float b, const float thickness, const sf::Color color) {
        unsigned const width = image.getSize().x, height = image.getSize().y;
        sf::Vector2<float> const center((float) width / 2, (float) height / 2);

        for (unsigned x = 0; x < width; x++) {
            for (unsigned y = 0; y < height; y++) {
                sf::Vector2 p(x, y);
                float inner = eq(p, center, a - thickness / 2, b - thickness / 2), outer = eq(
                    p, center, a + thickness / 2, b + thickness / 2);
                if (inner >= 1 && outer <= 1) {
                    image.setPixel(p, color);
                }
            }
        }
    }

    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    void skip_empty(std::string str, unsigned long &pos) {
        if (pos >= str.length()) return;
        while (str[pos] == ' ') pos++;
    }

    sf::Color read_color(std::string line, unsigned long &pos) {
        if (pos >= line.length()) {
            return sf::Color::Black;
        }
        if (line[pos] == '#') {
            pos++;
        }
        return pxl::hex_to_rgb(line.substr(pos, 6));
    }

    float read_num(std::string line, unsigned long &pos) {
        if (pos >= line.length()) return 0;
        if (!is_digit(line[pos])) {
            std::string invalid_number;
            while (pos < line.length() && line[pos] != ' ') {
                invalid_number += line[pos];
                pos++;
            }
            throw std::invalid_argument(invalid_number);
        }
        float res = 0;
        while (is_digit(line[pos])) {
            res = res * 10 + (float) (line[pos] - '0');
            pos++;
        }
        if (line[pos] == '.') {
            pos++;
            float exp = 10;
            while (is_digit(line[pos])) {
                res += (float) (line[pos] - '0') / exp;
                exp *= 10;
                pos++;
            }
        }
        return res;
    }
}
