#ifndef GRILLE_HPP
#define GRILLE_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Cellule.hpp"
#include "CalculEtatCellule.hpp"
#include <time.h>
using namespace std;


class Grille{
    protected:
        vector<vector<Cellule*>> cellules;
        int hauteur_grille;
        int largeur_grille;
    public:
        Grille(vector<vector<Cellule*>> cells) : cellules(cells){
            this -> hauteur_grille = cells.size();
            this -> largeur_grille = cells[0].size();
        } /*Constructeur avec tableau de cellules prédéfinies*/
        Grille(int h, int l) : hauteur_grille(h), largeur_grille(l) {
            for(int i = 0; i < h; i++){
                cellules.push_back(vector<Cellule*>());
                for(int j =0; j<l; j++){
                    int state = rand() %2;
                    if(state == 0){
                        CelluleMorte *a = new CelluleMorte(i, j);
                        cellules[i].push_back(a);
                    }
                    if(state == 1){
                        CelluleVivante *a = new CelluleVivante(i, j);
                    }
                }
            }
        }/*Constructeur avec tableau de cellules aléatoirement définies*/
        vector<vector<Cellule*>> getGrille(){
            return cellules;
        }
        void miseAJour(vector <vector <Cellule*>> nouvtab){
            if(nouvtab.size() == hauteur_grille && nouvtab[0].size() == largeur_grille){
                cellules = nouvtab;
            }
            else{
                throw runtime_error("Taille entre le nouveau tableau et le tableau original différentes.");
            }
        }/*Met a jour le tableau de vecteurs contenu dans la classe*/
        void affichage(){} /*Je te laisse le soin de voir comment tu veux l'implémenter Nathan.*/
        void reinitialiserGrille(){
            for(int i =0; i<cellules.size(); i++){
                for(int j=0; j<cellules[i].size(); j++){
                    delete cellules[i][j];
                    CelluleMorte *a = new CelluleMorte(i, j);
                    cellules[i][j] = a;
                }
            }
        }/*Réinitialise la grille pour la rendre vide (que des cellules mortes)*/
        int ResteCellulesVivantes(){
            int compteur_vivantes = 0;
            for(vector<Cellule*> x : cellules){
                for(Cellule* y : x){
                    if (y->estVivante()){
                        compteur_vivantes ++;
                    }
                }
            }
            return compteur_vivantes;
        }/*Renvoie le nombre de cellules vivantes sur grille.*/
};
#endif