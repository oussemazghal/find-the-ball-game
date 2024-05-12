#include <vector>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "Niveau.h"
#include "Cube.h"
#include "Ballon.h"
#include <cstdlib> // pour rand() et srand()
#include <ctime> // pour time()
#include "element.h"
int niveauu = 1;
int vitesse_deplacement = 2;
int nombre_iteration = 30;
bool showchoosed = false;
int k = 0;
bool choisirballon = false;
bool gameStarted = false;
bool placerballon = false;
bool ballonmouvement = false;
int indiceballon = 1;
bool answertime = false;
bool  waitforfermer = false;
 bool enableson = true;
 void moveSpriteUpAndDown(std::vector<Cube>& sprites, float speed, Ballon& ballon, int i) {
     static sf::Vector2f originalPosition = sprites[i].sprite.getPosition();
     
     static bool movingUp = true;

     if (movingUp) {
         sprites[i].sprite.move(0, -1); // move up by 1 pixel
         if (sprites[i].sprite.getPosition().y < 0) {
             movingUp = false;
         }
     }
     else {
         sprites[i].sprite.move(0, 1); // move down by 1 pixel
         if (sprites[i].sprite.getPosition().y >= originalPosition.y) {
             movingUp = true;
             showchoosed = false;
             answertime = true;
         }
     }
 }

 void moveRandomSpriteUpAndDown(std::vector<Cube>& sprites, float speed, Ballon& ballon) {
     static sf::Vector2f originalPosition = sprites[1].sprite.getPosition();
     if (!placerballon)
     {
         ballon.sprite.setPosition(sprites[1].sprite.getPosition().x + 50, sprites[1].sprite.getPosition().y + 220);
         placerballon = true;
         indiceballon = 1;
     }
     static bool movingUp = true;

     if (movingUp) {
         sprites[1].sprite.move(0, -1); // move up by 1 pixel
         if (sprites[1].sprite.getPosition().y < 0) {
             movingUp = false;
         }
     }
     else {
         sprites[1].sprite.move(0, 1); // move down by 1 pixel
         if (sprites[1].sprite.getPosition().y >= originalPosition.y) {
             movingUp = true;
             choisirballon = true;
         }
     }
 }
 void followParent(sf::Sprite& parent, sf::Sprite& sprite) {
     sf::Vector2f parentPosition = parent.getPosition();

     sprite.setPosition(parentPosition.x + 50, parentPosition.y + 220);
 }

 void swap(std::vector<Cube>& sprites, float speed, Ballon& ballon) {
     std::random_device rd;
     std::mt19937 engine(rd());
     std::uniform_int_distribution<> distribution(0, sprites.size() - 1);

     static int index1 = distribution(engine);
     static int index2 = (index1 + 1 + distribution(engine)) % sprites.size();
     static sf::Vector2f target1 = sprites[index2].sprite.getPosition();
     static sf::Vector2f target2 = sprites[index1].sprite.getPosition();

     for (int i = 0; i < speed; ++i) {
         if (sprites[index1].sprite.getPosition().x < target1.x) {
             sprites[index1].sprite.move(1, 0); // move by 1 pixel
             sprites[index2].sprite.move(-1, 0); // move by 1 pixel

             if (index1 == indiceballon || index2 == indiceballon) {
                 ballonmouvement = true;
                 followParent(sprites[indiceballon].sprite, ballon.sprite);
             }
         }
         else if (sprites[index1].sprite.getPosition().x < target1.x) {
             sprites[index1].sprite.move(1, 0); // move by 1 pixel
             sprites[index2].sprite.move(-1, 0); // move by 1 pixel

             if (index1 == indiceballon || index2 == indiceballon) {
                 followParent(sprites[indiceballon].sprite, ballon.sprite);
             }
         }
         else {
             sf::sleep(sf::seconds(0.1)); // pause d'une seconde

             if (ballonmouvement) {
                 ballonmouvement = false;
             }

             k++;
             std::cout << k;
             index1 = distribution(engine);
             index2 = (index1 + 1 + distribution(engine)) % sprites.size();
             target1 = sprites[index2].sprite.getPosition();
             target2 = sprites[index1].sprite.getPosition();
         }
     }
 }

 void loadSprites(std::vector<Cube>& cubes, sf::Texture& texture, int i) {
     

     int windowWidth = 880;
     int rectangleWidth = 150;
     int spaceBetweenRectangles = (windowWidth - i * rectangleWidth) / (i + 1);

     for (int j = 0; j < i; j++) {
         int xPosition = spaceBetweenRectangles + j * (rectangleWidth + spaceBetweenRectangles);
         Cube cube(texture, xPosition, 100);
         cubes.push_back(cube);
     }
 }




void chargergrisswap(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture)

{
    if (!texture.loadFromFile("source/swapphoto.jpg")) {}

    sprite.setTexture(texture);

    // Obtenir la taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Obtenir la taille de la texture
    sf::Vector2u textureSize = sprite.getTexture()->getSize();

    // Calculer le facteur d'échelle
    sf::Vector2f scale((float)windowSize.x / textureSize.x, (float)windowSize.y / textureSize.y);

    // Redimensionner le sprite
    sprite.setScale(scale);
}
void drawSprites(sf::RenderWindow& window, std::vector<Cube>& sprites, Ballon& ballon, sf::Sprite& background, Niveau& niveau) {
    window.clear();
    window.draw(background);
    ballon.draw(window);
    for (auto& a : sprites) {
        window.draw(a.sprite);
    }

    niveau.draw(window);
    window.display();
}

sf::Color modifiercolor(Button& c, std::vector<Cube>& sprites)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distribution(0, 256);

    int index1 = distribution(engine);
    int index2 = distribution(engine);
    int index3 = distribution(engine);
    sf::Color color(index1, index2, index3);
    c.shape.setFillColor(color);
    return color;
}

// Fonction pour dessiner les éléments du menu
void drawMenu(sf::RenderWindow& window, sf::Sprite& backgroundSprite, Button a, Button b, Button c,Button couleur,element& son,element& more,element& less,Button&  bou) {
    sf::Texture texture;
    texture.loadFromFile("source/logoo.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.6, 0.4);
    sprite.setPosition(333, 10);
    window.clear();
    window.draw(backgroundSprite); // Dessiner l'arrière-plan
    a.draw(window);
    b.draw(window);
    c.draw(window);
    more.draw(window);
    less.draw(window);
    bou.draw(window);

  
    couleur.draw(window);

    window.draw(sprite);
 

    son.draw(window);

    window.display();
}
void backgroundimage(sf::Texture& texture, sf::Sprite& sprite, sf::RenderWindow& window)
{
    if (!texture.loadFromFile("source/background.jpg")) {}
    sprite.setTexture(texture);
    sprite.setScale(
        window.getSize().x / sprite.getLocalBounds().width,
        window.getSize().y / sprite.getLocalBounds().height
    );
}
void afficheralert(sf::RenderWindow& window)
{

    
    sf::Font font;
    if (!font.loadFromFile("source/fontt.ttf")) { // Remplacez "arial.ttf" par le chemin de votre police
        // Erreur...
    }
    sf::Text text;
    text.setFont(font);
    text.setString(" if you want to change \n the number  of cups , \n  restart the game!");
    text.setOutlineThickness(2);
    text.setCharacterSize(30);
    text.setPosition(300,60);
    sf::RectangleShape backButton(sf::Vector2f(60.f, 30.f));
    backButton.setFillColor(sf::Color(128, 128, 128));
    backButton.setPosition(50, 500);

    sf::Text backButtonText;
    backButtonText.setFont(font);
    backButtonText.setString("Back");
    backButtonText.setCharacterSize(24); // en pixels, pas en points !
    backButtonText.setFillColor(sf::Color::White);
    backButtonText.setPosition(50, 500);
    sf::Sprite s;
    sf::Texture t;
    t.loadFromFile("source/erreur.jpg");
    s.setTexture(t);
    s.setScale(900 / s.getLocalBounds().width, 600 / s.getLocalBounds().height);
    bool displayRectangle = true;

    while (displayRectangle) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    displayRectangle = false;
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Effacer le contenu de la fenêtre
        window.draw(s);


        window.draw(text); // Dessiner le texte
        window.draw(backButton); // Dessiner le bouton de retour
        window.draw(backButtonText); // Dessiner le texte du bouton de retour
        window.display(); // Afficher le contenu de la fenêtre
        
    }



}
void createAndDisplayRectangle(sf::RenderWindow& window, const std::string& displayText) {
    // Créer un rectangle
    sf::RectangleShape rectangle(sf::Vector2f(750, 400));
    rectangle.setPosition(100, 50);
    rectangle.setFillColor(sf::Color(128, 128, 128));
    rectangle.setOutlineThickness(4);

    // Créer un texte
    sf::Font font;
    if (!font.loadFromFile("source/fontt.ttf")) { // Remplacez "arial.ttf" par le chemin de votre police
        // Erreur...
    }
    sf::Text text;
    text.setFont(font);
    text.setString(displayText);
    text.setCharacterSize(22); // en pixels, pas en points !
    text.setFillColor(sf::Color::White);
    text.setPosition(rectangle.getPosition().x + 10, rectangle.getPosition().y);

    // Créer une croix de fermeture
    sf::RectangleShape backButton(sf::Vector2f(60.f, 30.f));
    backButton.setFillColor(sf::Color(128, 128, 128));
    backButton.setPosition(50, 500);

    sf::Text backButtonText;
    backButtonText.setFont(font);
    backButtonText.setString("Back");
    backButtonText.setCharacterSize(24); // en pixels, pas en points !
    backButtonText.setFillColor(sf::Color::White);
    backButtonText.setPosition(50, 500);

    bool displayRectangle = true;
    while (displayRectangle) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    displayRectangle = false;
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Effacer le contenu de la fenêtre
        window.draw(rectangle); // Dessiner le rectangle
        window.draw(text); // Dessiner le texte
        window.draw(backButton); // Dessiner le bouton de retour
        window.draw(backButtonText); // Dessiner le texte du bouton de retour
        window.display(); // Afficher le contenu de la fenêtre
    }
}

sf::SoundBuffer buffer;
sf::Sound sound;

sf::Texture texture1;
sf::Texture texture2;
sf::Sprite sprite1;
sf::Sprite sprite2;


void affichersuccesechec(sf::RenderWindow& window, bool ea, sf::Font& font)
{
    sf::Clock clock;
    sf::Text t;
    if (!texture1.loadFromFile("source/levelup.png"))
    {
        std::cout << "probleme";
    }

    if (!texture2.loadFromFile("source/gameover.png"))
    {
        std::cout << "probleme";
    }
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite1.setScale(900 / sprite1.getLocalBounds().width, 600 / sprite1.getLocalBounds().height);
    sprite2.setScale(900 / sprite2.getLocalBounds().width, 600 / sprite2.getLocalBounds().height);


    if (ea)
    {
        
        if (buffer.loadFromFile("source/success.mp3"))
        {
            sound.setBuffer(buffer);
            if (enableson)
                sound.play();
        }
    }
    else
    {
        
        if (buffer.loadFromFile("source/fail.mp3"))
        {
            sound.setBuffer(buffer);
            if (enableson)
                sound.play();
        }
    }

    // Définir la texture du sprite après avoir chargé la texture

    

    while (clock.getElapsedTime().asSeconds() < 3)
    {
        window.clear();
        if(ea)
        window.draw(sprite1);
        else
            window.draw(sprite2);
        window.display();
    }
}
