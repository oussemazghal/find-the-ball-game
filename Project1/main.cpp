#include <vector>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "Source.h"
#include <SFML/Audio.hpp>
#include "Button.h"
#include "Niveau.h"
#include "Cube.h"
#include "Ballon.h"
#include "Text.h"
#include "element.h"


sf::Color c= sf::Color(128, 128, 128);//couleur des cups
int m = -1;
bool changed = false;
int main() {
    sf::RenderWindow window(sf::VideoMode(900, 600), "SFML window");//fenetre
    element son("source/enabled.png",770,27);//son du jeu



    // Création des boutons
    sf::Font font;
    if (!font.loadFromFile("source/fontt.ttf")) {
        return -1; // Erreur lors du chargement de la police
    }
    //bouttons
     Button startButton(font, "Start", 24, sf::Color(128, 128, 128), sf::Color::Black, sf::Vector2f(350, 200), sf::Vector2f(200, 50));
     Button howToPlayButton(font, "How to Play", 24, sf::Color(128, 128, 128), sf::Color::Black, sf::Vector2f(350, 270), sf::Vector2f(200, 50));
       Button aboutUsButton(font, "About Us", 24, sf::Color(128, 128, 128), sf::Color::Black, sf::Vector2f(350, 340), sf::Vector2f(200, 50));
       Button color(font, "Color ", 24, sf::Color(255, 255, 255), sf::Color::Black, sf::Vector2f(20, 50), sf::Vector2f(120, 50));


    // Charger l'image d'arrière-plan
    sf::Texture backgroundTexture;
    //text du niveau 
    Niveau niveau(font);
    //niveau 1
    element more("source/more.png", 10, 525); 
    element less("source/less.png", 100, 527);
    Button numberofcups(font, "3", 24, sf::Color::Transparent, sf::Color::White, sf::Vector2f(78, 545), sf::Vector2f(20, 10));
    numberofcups.shape.setOutlineColor(sf::Color::Transparent);
    numberofcups.text.setPosition(80, 550);




    // Créer le sprite d'arrière-plan
    sf::Sprite backgroundSprite;
    backgroundimage(backgroundTexture, backgroundSprite, window);
    Ballon ballon("source/ballon.png", 50, 50);
    std::vector<Cube> sprites;

    sf::Texture texture;
    if (!texture.loadFromFile("source/cup3.png")) {
        return -1; // Erreur lors du chargement de l'image
    }

   
    sf::Sprite grisswap;
    sf::Texture grisswaptexture;
    sf::SoundBuffer bufferr;
    sf::Sound sound;
    bufferr.loadFromFile("source/start.mp3");
    sound.setBuffer(bufferr);
    sound.setLoop(true);
    sound.play();
    sound.setLoop(true);
    sound.setVolume(70); 
    bool loaded = false;
   

    while (window.isOpen()) {
        
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {//temps de choisir
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (!gameStarted)
                {
                    if (howToPlayButton.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        createAndDisplayRectangle(window, text1);
                    }
                    if (aboutUsButton.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        createAndDisplayRectangle(window, text2);
                    }
                    if (startButton.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameStarted = true; // Le jeu commence lorsque l'utilisateur clique sur "start"
                        
                        
                        




                    }
                    if (color.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        c=modifiercolor(color, sprites); // Le jeu commence lorsque l'utilisateur clique sur "start"
                        std::cout << "aa";
                    }
                    if (more.sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (!changed)// Le jeu commence lorsque l'utilisateur clique sur "start"
                        {
                            numberofcups.modifierText(true);
                        }
                        else
                            afficheralert(window);
                    }
                        if (less.sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            if (!changed)// Le jeu commence lorsque l'utilisateur clique sur "start"
                            {
                                numberofcups.modifierText(false);
                            }
                            else
                                afficheralert(window);
                        }


                        if (son.sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            if (enableson == true)
                            {
                                son.modifiertexture("source/disabled.png");
                                enableson = false;
                                sound.pause();
                            }
                            else
                            {
                                son.modifiertexture("source/enabled.png");
                                enableson = true;
                                sound.play();


                            }
                        }
                    }
                

                else if (gameStarted && k >= nombre_iteration && !answertime) {
                    changed = true;
                   
                        for (int i = 0; i < sprites.size(); i++) {
                            if (sprites[i].sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                showchoosed = true;
                                m = i;
                            }
                        
                    }
                }
            }
        }
        if (answertime) {

            if (m == indiceballon) {
                std::cout << "Correct!\n";
                affichersuccesechec(window, true, font);

                niveau.modifierNiveau();
                vitesse_deplacement = vitesse_deplacement + 1; // Increase the speed based on the level
                nombre_iteration = nombre_iteration + 5;


                choisirballon = false; // Reset the variable to start the random movement again

                k = 0; // Reset the counter to start the swapping from the beginning
            }
            else {

                std::cout << "Incorrect!\n";
                affichersuccesechec(window, false, font);
                gameStarted = false;
                
                k = 0;
                niveau.n = 0;
                nombre_iteration = 30;
                vitesse_deplacement = 2;
                choisirballon = false;
             

            }

            answertime = false;
            showchoosed = false;
        }
if (!gameStarted)//si le jeu n as pas commencer
            {

    drawMenu(window, backgroundSprite, startButton, howToPlayButton, aboutUsButton, color, son, more, less, numberofcups);

            }
else {
    if (!loaded)
    {
        loadSprites(sprites, texture, numberofcups.getTextAsInt());
        loaded = true;
    }
    for (int i = 0;i < sprites.size();i++)
    {
        sprites[i].sprite.setColor(c);

    }
    
    // Le jeu ne commence que lorsque l'utilisateur a cliqué
                if (k >= nombre_iteration && showchoosed)
                {
                    moveSpriteUpAndDown(sprites, 10, ballon, m);
                }
                if (choisirballon == false)
                    moveRandomSpriteUpAndDown(sprites, 10, ballon);
                else//comment a swapper
                {
                    if (k < nombre_iteration) {
                        swap(sprites, vitesse_deplacement, ballon);
                    }
                }// vitesse augmentée
                chargergrisswap(window, grisswap, grisswaptexture);//charger background du swap
                drawSprites(window, sprites, ballon, grisswap, niveau);//afficher mouvement
            }
        }
            
    
    return 0;
}