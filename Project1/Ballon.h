// Inclure le fichier d'en-t�te pour la biblioth�que graphique SFML
#include "SFML/Graphics.hpp"

// Inclure le fichier d'en-t�te pour la biblioth�que de cha�nes de caract�res
#include <string>

// Pr�venir les inclusions multiples du fichier d'en-t�te
#pragma once

// D�finition de la classe "Ballon"
class Ballon {
public:
    // Constructeur de la classe "Ballon"
    Ballon(const std::string& textureFile, float x, float y) {
        // Charger une texture � partir d'un fichier
        if (!texture.loadFromFile(textureFile)) {
            // G�rer l'erreur ici si le chargement �choue
        }
        // D�finir la texture du sprite
        sprite.setTexture(texture);
        // D�finir la position du sprite
        sprite.setPosition(x, y);
        // D�finir l'�chelle du sprite
        sprite.setScale(0.5, 0.5);
        // D�finir la couleur du sprite
        sprite.setColor(sf::Color(255, 0, 0));
    }

    // D�claration des membres de la classe
    sf::Texture texture; // Texture pour le sprite
    sf::Sprite sprite;  // Sprite pour le ballon

    // M�thode pour dessiner le sprite dans la fen�tre
    void draw(sf::RenderWindow& window) {
        // Dessiner le sprite dans la fen�tre
        window.draw(sprite);
    }
};
