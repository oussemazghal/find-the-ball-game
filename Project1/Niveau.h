// Inclure le fichier d'en-t�te pour la biblioth�que graphique SFML
#include <SFML/Graphics.hpp>

// Pr�venir les inclusions multiples du fichier d'en-t�te
#pragma once

// D�finition de la classe "Niveau"
class Niveau {
public:
    // D�claration des membres de la classe
    int n = 1; // Le niveau actuel
    sf::Text text; // Le texte � afficher
    sf::RectangleShape sprite; // Le sprite pour le niveau

public:
    // Constructeur de la classe "Niveau"
    Niveau(const sf::Font& font) {
        // D�finir la taille du sprite
        sprite.setSize(sf::Vector2f(330, 50));
        // D�finir la couleur de remplissage du sprite
        sprite.setFillColor(sf::Color(128, 128, 128));
        // D�finir la couleur de contour du sprite
        sprite.setOutlineColor(sf::Color::Black);
        // D�finir l'�paisseur du contour du sprite
        sprite.setOutlineThickness(2);
        // D�finir la position du sprite
        sprite.setPosition(520, 20);

        // D�finir la police du texte
        text.setFont(font);
        // D�finir la taille du texte
        text.setCharacterSize(40);
        // D�finir la couleur du texte
        text.setFillColor(sf::Color::Black);
        // D�finir la position du texte
        text.setPosition(580, 20);
        // D�finir le style du texte
        text.setStyle(sf::Text::Bold);
        // D�finir la cha�ne de caract�res du texte
        text.setString(" niveau " + std::to_string(n));
    }

    // M�thode pour modifier le niveau
    void modifierNiveau() {
        // Incr�menter le niveau
        n++;
        // Mettre � jour la cha�ne de caract�res du texte
        text.setString(" niveau " + std::to_string(n));
    }

    // M�thode pour dessiner le sprite et le texte dans la fen�tre
    void draw(sf::RenderWindow& window) const {
        // Dessiner le sprite dans la fen�tre
        window.draw(sprite);
        // Dessiner le texte dans la fen�tre
        window.draw(text);
    }
};
