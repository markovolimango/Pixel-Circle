#include <cmath>
#include "pixel-circle.h"

namespace pxl {
    //geometry and drawing

    sf::Vector2f pixel_center(const sf::Vector2<unsigned> pixel_pos) {
        return {static_cast<float>(pixel_pos.x) + 0.5f, static_cast<float>(pixel_pos.y) + 0.5f};
    }

    float ellipsis_equation(const sf::Vector2<unsigned> pixel_pos, const sf::Vector2<float> center, const float a,
                            const float b) {
        const sf::Vector2 coords = pixel_center(pixel_pos) - center;
        return coords.x * coords.x / (a * a) + coords.y * coords.y / (b * b);
    }


    void fill(sf::Image &image, const float a, const float b, const sf::Color color) {
        unsigned const width = image.getSize().x, height = image.getSize().y;
        sf::Vector2 const center(static_cast<float>(width) / 2, static_cast<float>(height) / 2);

        for (unsigned x = 0; x < width; x++)
            for (unsigned y = 0; y < height; y++)
                if (const sf::Vector2 pixel(x, y); ellipsis_equation(pixel, center, a, b) <= 1)
                    image.setPixel(pixel, color);
    }

    void outline(sf::Image &image, const float a, const float b, const float thickness, const sf::Color color) {
        unsigned const width = image.getSize().x, height = image.getSize().y;
        sf::Vector2 const center(static_cast<float>(width) / 2, static_cast<float>(height) / 2);

        for (unsigned x = 0; x < width; x++)
            for (unsigned y = 0; y < height; y++) {
                const sf::Vector2 pixel(x, y);
                const float inner_eq = ellipsis_equation(pixel, center, a - thickness / 2, b - thickness / 2), outer_eq
                        = ellipsis_equation(pixel, center, a + thickness / 2, b + thickness / 2);
                if (inner_eq >= 1 && outer_eq <= 1)
                    image.setPixel(pixel, color);
            }
    }

    sf::Color hex_to_rgb(const std::string &hex) {
        sf::Color color;
        color.r = stoi(hex.substr(0, 2), nullptr, 16);
        color.g = stoi(hex.substr(2, 2), nullptr, 16);
        color.b = stoi(hex.substr(4, 2), nullptr, 16);
        color.a = 255;
        return color;
    }
}
