#pragma once
#include <SFML/Graphics.hpp>

#ifndef PIXEL_CIRCLE_H
#define PIXEL_CIRCLE_H

namespace pxl {
    sf::Color hex_to_rgb(std::string hex);

    float distance(sf::Vector2<float> a, sf::Vector2<float> b);

    sf::Vector2f pixel_center(sf::Vector2<unsigned> pixel_pos);

    void fill(sf::Image &image, float r, sf::Color color);

    void outline(sf::Image &image, float r, float thickness, sf::Color color);
}

#endif
