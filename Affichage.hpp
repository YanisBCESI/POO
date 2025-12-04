#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Cellule.hpp"

using namespace std;

class FenetreAffichage{
protected:
    sf::RenderWindow fenetre;
    int hauteur_grille;
    int largeur_grille;
    const int taille_cellule = 10;
    vector<vector<Cellule *>> tab_cellules;

public:
    FenetreAffichage(int h, int l, string nom)
        : fenetre(sf::VideoMode(l * taille_cellule, h * taille_cellule), nom),
          hauteur_grille{h},
          largeur_grille{l}
    {}
    void fermer() {
        fenetre.close();
    }
    bool estOuverte() const {
        return fenetre.isOpen();
    }
    void afficher(vector<vector<Cellule*>>& nouvgrille) {
        tab_cellules = nouvgrille;
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }
        fenetre.clear(sf::Color::Black);
        sf::RectangleShape cell(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
        for (int x = 0; x < hauteur_grille; x++) {
            for (int y = 0; y < largeur_grille; y++) {
                cell.setPosition(y * taille_cellule, x * taille_cellule);
                if (tab_cellules[x][y]->estVivante())
                    cell.setFillColor(sf::Color::White);
                else
                    cell.setFillColor(sf::Color::Black);
                fenetre.draw(cell);
            }
        }
        fenetre.display();
    }
};

#endif
