// Inclure le fichier d'en-tête pour la bibliothèque graphique SFML
#include <SFML/Graphics.hpp>

// Prévenir les inclusions multiples du fichier d'en-tête
#pragma once

// Définition de la classe "element"
class element {
public:
    // Constructeur de la classe "element"
    element(const std::string& textureFile, float x, float y) {
        // Charger une texture à partir d'un fichier
        if (!texture.loadFromFile(textureFile)) {
            // Gérer l'erreur ici si le chargement échoue
        }
        // Définir la texture du sprite
        sprite.setTexture(texture);
        // Définir la position du sprite
        sprite.setPosition(x, y);
        // Définir l'échelle du sprite
        sprite.setScale(0.5, 0.5);
        // Définir la couleur du sprite
        sprite.setColor(sf::Color(255, 255, 255));
    }
    // Méthode pour dessiner le sprite dans la fenêtre
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
    // Méthode pour modifier la texture du sprite
    void modifiertexture(const std::string& textureFile)
    {
        // Charger une nouvelle texture à partir d'un fichier
        if (!texture.loadFromFile(textureFile)) {
            // Gérer l'erreur ici si le chargement échoue
        }
        // Définir la nouvelle texture du sprite
        sprite.setTexture(texture);
    }

    // Déclaration des membres de la classe
    sf::Texture texture; // Texture pour le sprite
    sf::Sprite sprite;  // Sprite pour l'élément

};
