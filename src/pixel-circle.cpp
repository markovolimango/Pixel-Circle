#include <cmath>
#include "pixel-circle.h"

sf::Color hex_to_rgb(std::string hex) {
    if (hex[0] == '#') hex = hex.substr(1, hex.length() - 1);
    sf::Color c;
    c.r = stoi(hex.substr(0, 2), nullptr, 16);
    c.g = stoi(hex.substr(2, 2), nullptr, 16);
    c.r = stoi(hex.substr(4, 2), nullptr, 16);
    c.a = 255;
    return c;
}

float distance(const sf::Vector2<float> a, const sf::Vector2<float> b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

sf::Vector2f pixel_center(sf::Vector2<unsigned> pixel_pos) {
    return {(float) pixel_pos.x + 0.5f, (float) pixel_pos.y + 0.5f};
}

void fill(sf::Image &image, const float r, const sf::Color color) {
    unsigned const width = image.getSize().x, height = image.getSize().y;
    sf::Vector2 const center((float) width / 2, (float) height / 2);

    for (unsigned x = 0; x < width; x++) {
        for (unsigned y = 0; y < height; y++) {
            sf::Vector2 p(x, y);
            if (distance(pixel_center(p), center) <= r) {
                image.setPixel(p, color);
            }
        }
    }
}

void outline(sf::Image &image, const float r, const float thickness, const sf::Color color) {
    unsigned const width = image.getSize().x, height = image.getSize().y;
    sf::Vector2<float> const center((float) width / 2, (float) height / 2);

    for (unsigned x = 0; x < width; x++) {
        for (unsigned y = 0; y < height; y++) {
            sf::Vector2 p(x, y);
            float dist = distance(pixel_center(p), center);
            if (dist <= r + thickness / 2 && dist >= r - thickness / 2) {
                image.setPixel(p, color);
            }
        }
    }
}
