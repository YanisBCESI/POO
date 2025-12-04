#ifndef VERIF_HPP
#define VERIF_HPP

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Cellule.hpp"
#include "ChargeFichier.hpp"

class Verif{
    protected :
        vector<vector<Cellule*>> grille1;
        vector<vector<Cellule*>> grille2;
    public:
        Verif(vector<vector<Cellule*>> g1, vector<vector<Cellule*>> g2) : grille1(g1), grille2(g2) {}
        bool estMeme(){
            bool est_meme = true;
            for(int i = 0; i < grille1.size(); i++){
                for(int j =0; j < grille1[0].size(); j++){
                    if (grille1[i][j]->estVivante() != grille2[i][j]->estVivante()){
                        est_meme = false;
                    }
                }
            }
            return est_meme;
        }
};

#endif