#ifndef CALCULETATCELLULE_HPP
#define CALCULETATCELLULE_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Cellule.hpp"
#include "grille.hpp"
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
            int compteur_voisins;
            for(int i = 0; i < TotalCellules.size(); i++){
                for(int j = 0; j < TotalCellules[i].size(); j++){
                    compteur_voisins = 0;
                    for(int horizontale = i-1 ; horizontale <= i +1; horizontale ++){
                        if(horizontale < 0){
                            horizontale = TotalCellules.size()-1;
                        }
                        if(horizontale > TotalCellules.size()-1){
                            horizontale = 0;
                        }
                        for(int verticale = j-1; verticale <= j+1; verticale ++){
                            if(verticale < 0){
                                verticale = TotalCellules.size()-1;
                            }
                            if(verticale > TotalCellules.size()-1){
                                verticale = 0;
                            }
                            if(i, j == horizontale, verticale){
                                verticale ++;
                            }
                            if(TotalCellules[horizontale][verticale]->estVivante()){
                                compteur_voisins++;
                            }
                        }
                    }
                    if(2<= compteur_voisins<= 3){
                        delete TotalCellules[i][j];
                        CelluleVivante *a = new CelluleVivante(i, j);
                        TotalCellules[i][j] = a;
                    }
                    if(compteur_voisins <= 1 || compteur_voisins >=4){
                        delete TotalCellules[i][j];
                        CelluleMorte *a = new CelluleMorte(i, j);
                        TotalCellules[i][j] = a;                        
                    }
                }
            }
            return TotalCellules;
        }
        
};

#endif