#ifndef CALCULETATCELLULE_HPP
#define CALCULETATCELLULE_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Cellule.hpp"
using namespace std;

class CalculEtatCellule{
    protected:
        vector<vector<Cellule *>> TotalCellules;
    public:
        CalculEtatCellule(vector<vector<Cellule * >> grille_init) : TotalCellules(grille_init) {}
        void SetTotalCellules(vector<vector<Cellule *>> grille_maj){
            TotalCellules = grille_maj;
        }
        vector<vector<Cellule *>> CalculGrille(){
            int hauteur = TotalCellules.size();
            int largeur = TotalCellules[0].size();
            vector<vector<Cellule*>> nouvelleGrille(hauteur, vector<Cellule*>(largeur, nullptr));
            for(int i=0; i<hauteur; i++){
                for(int j=0; j<largeur; j++){
                    int voisins = 0;
                    for(int dx=-1; dx<=1; dx++){
                        for(int dy=-1; dy<=1; dy++){
                            if(dx==0 && dy==0) continue;
                            int nx = (i + dx + hauteur) % hauteur;
                            int ny = (j + dy + largeur) % largeur;
                            if(TotalCellules[nx][ny]->estVivante())
                                voisins++;
                        }
                    }
                    TotalCellules[i][j]->setVoisins(voisins);
                    if(TotalCellules[i][j]->estVivante()){
                        if(voisins == 2 || voisins == 3)
                            nouvelleGrille[i][j] = new CelluleVivante(i, j);
                        else
                            nouvelleGrille[i][j] = new CelluleMorte(i, j);
                    } else {
                        if(voisins == 3)
                            nouvelleGrille[i][j] = new CelluleVivante(i, j);
                        else
                            nouvelleGrille[i][j] = new CelluleMorte(i, j);
                    }
                }
            }
            // Supprimer l'ancienne grille pour éviter fuite mémoire
            for(int i=0; i<hauteur; i++){
                for(int j=0; j<largeur; j++){
                    delete TotalCellules[i][j];
                }
            }

            TotalCellules = nouvelleGrille;
            return TotalCellules;
        }
};

#endif