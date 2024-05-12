// Inclure le fichier d'en-t�te pour la biblioth�que graphique SFML
#include "SFML/Graphics.hpp"

// Inclure le fichier d'en-t�te pour les flux d'entr�e/sortie
#include <iostream>

// Pr�venir les inclusions multiples du fichier d'en-t�te
#pragma once

// D�finition de la classe "Button"
class Button {
public:
    // D�claration des membres de la classe
    sf::Text text; // Le texte � afficher
    sf::RectangleShape shape; // La forme du bouton

    // Constructeur de la classe "Button"
    Button(const sf::Font& font, const std::string& string, int characterSize, sf::Color fillColor, sf::Color outlineColor, sf::Vector2f position, sf::Vector2f size) {
        // D�finir la police du texte
        text.setFont(font);
        // D�finir la cha�ne de caract�res du texte
        text.setString(string);
        // D�finir la taille du texte
        text.setCharacterSize(characterSize);
        // D�finir la couleur du texte
        text.setFillColor(sf::Color::Black);
        // D�finir le style du texte
        text.setStyle(sf::Text::Bold);
        // D�finir la position du texte au centre du bouton
        text.setPosition(position.x + 30, position.y + 10);

        // D�finir la taille de la forme
        shape.setSize(size);
        // D�finir la couleur de remplissage de la forme
        shape.setFillColor(fillColor);
        // D�finir la couleur de contour de la forme
        shape.setOutlineColor(outlineColor);
        // D�finir l'�paisseur du contour de la forme
        shape.setOutlineThickness(2);
        // D�finir la position de la forme
        shape.setPosition(position);
    }

    // M�thode pour modifier le texte
    void modifierText(bool i)
    {
        // Obtenir la cha�ne de caract�res du texte
        std::string c = text.getString();
        // Convertir la cha�ne de caract�res en entier
        int value = std::stoi(c);
        // Si "i" est vrai et la valeur est inf�rieure � 5, incr�menter la valeur
        if (i && value < 5)
            text.setString(std::to_string(value + 1));
        // Sinon, si "i" est faux et la valeur est sup�rieure � 2, d�cr�menter la valeur
        else if (!i && value > 2)
            text.setString(std::to_string(value - 1));
    }

    // M�thode pour obtenir la valeur du texte en tant qu'entier
    int getTextAsInt() const {
        // Obtenir la cha�ne de caract�res du texte
        std::string c = text.getString();
        // Convertir la cha�ne de caract�res en entier et la retourner
        return std::stoi(c);
    }

    // M�thode pour dessiner la forme et le texte dans la fen�tre
    void draw(sf::RenderWindow& window) const {
        // Dessiner la forme dans la fen�tre
        window.draw(shape);
        // Dessiner le texte dans la fen�tre
        window.draw(text);
    }
};
