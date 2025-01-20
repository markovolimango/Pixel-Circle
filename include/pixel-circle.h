#pragma once
#include <SFML/Graphics.hpp>

#ifndef PIXEL_CIRCLE_H
#define PIXEL_CIRCLE_H

#if defined(_WIN32)
#   if defined(EXPORTING)
#       define DECLSPEC __declspec(dllexport)
#   else
#       define DECLSPEC __declspec(dllimport)
#   endif
#else
#   define DECLSPEC
#endif

namespace pxl {
    void DECLSPEC fill(sf::Image &image, float a, float b, sf::Color color);

    void DECLSPEC outline(sf::Image &image, float a, float b, float thickness, sf::Color color);

    void DECLSPEC skip_empty(const std::string &line, unsigned long &pos);

    sf::Color DECLSPEC read_color(const std::string &line, unsigned long &pos);

    float DECLSPEC read_num(const std::string &line, unsigned long &pos);
}

#endif
