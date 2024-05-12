#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#pragma once
class Cube {
public:
    Cube(sf::Texture& texture, float x, float y) {
        sprite.setTexture(texture);
        sprite.setScale(1.2, 1.5);
        sprite.setPosition(x, y);
        sprite.setColor(sf::Color(140,140,140));
    }

    sf::Sprite& getSprite() {
        return sprite;
    }


    sf::Sprite sprite;
};