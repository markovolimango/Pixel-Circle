#pragma once
#include <SFML/Graphics.hpp>

#ifndef PIXEL_CIRCLE_H
#define PIXEL_CIRCLE_H

namespace pxl {
    void fill(sf::Image &image, float a, float b, sf::Color color);

    void outline(sf::Image &image, float a, float b, float thickness, sf::Color color);

    void skip_empty(const std::string &line, unsigned long &pos);

    sf::Color read_color(const std::string &line, unsigned long &pos);

    float read_num(const std::string &line, unsigned long &pos);
}

#endif
