#pragma once
#include "Button.h"
#include <vector>
#include "Niveau.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "Ballon.h"
#include "Cube.h"
#include "element.h"


extern bool enableson;
extern bool resultat;
extern bool niveausuivant;
extern int niveauu;
extern int vitesse_deplacement;
extern int nombre_iteration;
extern bool  waitforfermer;
extern int k;
extern bool choisirballon;
extern bool gameStarted;
extern bool showchoosed;
extern bool  answertime;
extern bool placerballon;
extern bool ballonmouvement;
extern  bool changed;
extern int indiceballon;
void moveSpriteUpAndDown(std::vector<Cube>& sprites, float speed, Ballon& ballon, int i);
void moveRandomSpriteUpAndDown(std::vector<Cube>& sprites, float speed, Ballon& ballon);
void followParent(sf::Sprite& parent, Ballon& sprite);
void swap(std::vector<Cube>& sprites, float speed, Ballon& ballon);
void loadSprites(std::vector<Cube>& cubes, sf::Texture& texture, int i);
void deleteCubes(std::vector<Cube>& cubes);
void drawSprites(sf::RenderWindow& window, std::vector<Cube>& sprites, Ballon& ballon, sf::Sprite& background, Niveau& niveau);
void drawMenu(sf::RenderWindow& window, sf::Sprite& backgroundSprite, Button a, Button b, Button c, Button couleur, element& son,element& more, element& less, Button& e);
void affichersuccesechec(sf::RenderWindow& window, bool ea, sf::Font& font);
void backgroundimage(sf::Texture& texture, sf::Sprite& sprite, sf::RenderWindow& window);
void backgroundimage(sf::Texture& texture, sf::Sprite& sprite, sf::RenderWindow& window);
void createAndDisplayRectangle(sf::RenderWindow& window, const std::string& displayText);
void chargergrisswap(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& text);
sf::Color modifiercolor(Button& c, std::vector<Cube>& sprites);
extern int numberofcups = 3;
void afficheralert(sf::RenderWindow& window);

