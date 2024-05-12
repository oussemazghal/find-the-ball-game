// Inclure le fichier d'en-tête pour la bibliothèque graphique SFML
#include <SFML/Graphics.hpp>

// Prévenir les inclusions multiples du fichier d'en-tête
#pragma once

// Définition de la classe "Niveau"
class Niveau {
public:
    // Déclaration des membres de la classe
    int n = 1; // Le niveau actuel
    sf::Text text; // Le texte à afficher
    sf::RectangleShape sprite; // Le sprite pour le niveau

public:
    // Constructeur de la classe "Niveau"
    Niveau(const sf::Font& font) {
        // Définir la taille du sprite
        sprite.setSize(sf::Vector2f(330, 50));
        // Définir la couleur de remplissage du sprite
        sprite.setFillColor(sf::Color(128, 128, 128));
        // Définir la couleur de contour du sprite
        sprite.setOutlineColor(sf::Color::Black);
        // Définir l'épaisseur du contour du sprite
        sprite.setOutlineThickness(2);
        // Définir la position du sprite
        sprite.setPosition(520, 20);

        // Définir la police du texte
        text.setFont(font);
        // Définir la taille du texte
        text.setCharacterSize(40);
        // Définir la couleur du texte
        text.setFillColor(sf::Color::Black);
        // Définir la position du texte
        text.setPosition(580, 20);
        // Définir le style du texte
        text.setStyle(sf::Text::Bold);
        // Définir la chaîne de caractères du texte
        text.setString(" niveau " + std::to_string(n));
    }

    // Méthode pour modifier le niveau
    void modifierNiveau() {
        // Incrémenter le niveau
        n++;
        // Mettre à jour la chaîne de caractères du texte
        text.setString(" niveau " + std::to_string(n));
    }

    // Méthode pour dessiner le sprite et le texte dans la fenêtre
    void draw(sf::RenderWindow& window) const {
        // Dessiner le sprite dans la fenêtre
        window.draw(sprite);
        // Dessiner le texte dans la fenêtre
        window.draw(text);
    }
};
