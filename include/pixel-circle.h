#pragma once
#include <SFML/Graphics.hpp>

#ifndef PIXEL_CIRCLE_H
#define PIXEL_CIRCLE_H

namespace pxl {
    /*!
     * @brief Fills an ellipse
     *
     * A pixel is colored if it's center is inside the ellipse
     * 
     * @param image The SFML image to draw on
     * @param a Half of the ellipse width
     * @param b Half of the ellipse height
     * @param color The color to fill with
     */
    void fill(sf::Image &image, float a, float b, sf::Color color);

    /*!
     * @brief Draws the outline of an ellipse
     *
     * A pixel is colored if it's center is between an ellipse [thickness] pixels smaller, and one [thickness] pixels
     * larger
     *
     * @param image The SFML image to draw on
     * @param a Half of the ellipse width
     * @param b Half of the ellipse height
     * @param thickness The thickness of the outline in pixels
     * @param color The color of the outline
     */
    void outline(sf::Image &image, float a, float b, float thickness, sf::Color color);

    /*!
     * @brief Converts a HEX value into the SFML color format.
     *
     * @param hex A string representing the HEX value
     * @return The SFML color corresponding to the given HEX value
     */
    sf::Color hex_to_rgb(const std::string &hex);
}

#endif
