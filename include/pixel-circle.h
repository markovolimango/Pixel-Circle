#pragma once
#include <SFML/Graphics.hpp>

#ifndef PIXEL_CIRCLE_H
#define PIXEL_CIRCLE_H

namespace pxl {
    sf::Color hex_to_rgb(std::string hex);

    sf::Vector2f pixel_center(sf::Vector2<unsigned> pixel_pos);

    float eq(sf::Vector2<unsigned> pixel_pos, sf::Vector2<float> center, float a, float b);

    void fill(sf::Image &image, float a, float b, sf::Color color);

    void outline(sf::Image &image, float a, float b, float thickness, sf::Color color);

    void skip_empty(std::string str, unsigned long &pos);

    sf::Color read_color(std::string line, unsigned long &pos);

    float read_num(std::string line, unsigned long &pos);
}

#endif
