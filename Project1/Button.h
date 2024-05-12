// Inclure le fichier d'en-tête pour la bibliothèque graphique SFML
#include "SFML/Graphics.hpp"

// Inclure le fichier d'en-tête pour les flux d'entrée/sortie
#include <iostream>

// Prévenir les inclusions multiples du fichier d'en-tête
#pragma once

// Définition de la classe "Button"
class Button {
public:
    // Déclaration des membres de la classe
    sf::Text text; // Le texte à afficher
    sf::RectangleShape shape; // La forme du bouton

    // Constructeur de la classe "Button"
    Button(const sf::Font& font, const std::string& string, int characterSize, sf::Color fillColor, sf::Color outlineColor, sf::Vector2f position, sf::Vector2f size) {
        // Définir la police du texte
        text.setFont(font);
        // Définir la chaîne de caractères du texte
        text.setString(string);
        // Définir la taille du texte
        text.setCharacterSize(characterSize);
        // Définir la couleur du texte
        text.setFillColor(sf::Color::Black);
        // Définir le style du texte
        text.setStyle(sf::Text::Bold);
        // Définir la position du texte au centre du bouton
        text.setPosition(position.x + 30, position.y + 10);

        // Définir la taille de la forme
        shape.setSize(size);
        // Définir la couleur de remplissage de la forme
        shape.setFillColor(fillColor);
        // Définir la couleur de contour de la forme
        shape.setOutlineColor(outlineColor);
        // Définir l'épaisseur du contour de la forme
        shape.setOutlineThickness(2);
        // Définir la position de la forme
        shape.setPosition(position);
    }

    // Méthode pour modifier le texte
    void modifierText(bool i)
    {
        // Obtenir la chaîne de caractères du texte
        std::string c = text.getString();
        // Convertir la chaîne de caractères en entier
        int value = std::stoi(c);
        // Si "i" est vrai et la valeur est inférieure à 5, incrémenter la valeur
        if (i && value < 5)
            text.setString(std::to_string(value + 1));
        // Sinon, si "i" est faux et la valeur est supérieure à 2, décrémenter la valeur
        else if (!i && value > 2)
            text.setString(std::to_string(value - 1));
    }

    // Méthode pour obtenir la valeur du texte en tant qu'entier
    int getTextAsInt() const {
        // Obtenir la chaîne de caractères du texte
        std::string c = text.getString();
        // Convertir la chaîne de caractères en entier et la retourner
        return std::stoi(c);
    }

    // Méthode pour dessiner la forme et le texte dans la fenêtre
    void draw(sf::RenderWindow& window) const {
        // Dessiner la forme dans la fenêtre
        window.draw(shape);
        // Dessiner le texte dans la fenêtre
        window.draw(text);
    }
};
