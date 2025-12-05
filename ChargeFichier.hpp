#ifndef CHARGEURGRILLE_HPP
#define CHARGEURGRILLE_HPP

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Cellule.hpp"

using namespace std;

class ChargeurGrille{
public:     
    ChargeurGrille(){}
    static vector<vector<Cellule*>> chargerDepuisFichier(const string& nomFichier) {
        ifstream fichier(nomFichier);
        if (!fichier.is_open()) {
            throw runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
        }

        int hauteur, largeur;
        fichier >> largeur >> hauteur;

        vector<vector<Cellule*>> grille(largeur, vector<Cellule*>(hauteur, nullptr));

        for(int i = 0; i < largeur; i++) {
            for(int j = 0; j < hauteur; j++) {
                int valeur;
                fichier >> valeur;

                if(!fichier) {
                    throw runtime_error("Erreur de lecture dans le fichier (ligne trop courte ?)");
                }

                if (valeur == 1)
                    grille[i][j] = new CelluleVivante(i, j);
                else
                    grille[i][j] = new CelluleMorte(i, j);
            }
        }

        return grille;
    }
    static void chargerDansFichier(const string& fichier_entree, const vector<vector<Cellule*>>& grille){
        string nombase = fichier_entree;
        int indice = nombase.rfind(".txt");
        if(indice != string::npos){
            nombase = nombase.substr(0, indice);
        }
        string nomsortie = nombase + "_out.txt";
        ofstream fichier(nomsortie);
        if(!fichier.is_open()){
            throw runtime_error("Impossible d'ouvrir le fichier " + nomsortie);
        }
        int hauteur = grille.size();
        int largeur = grille[0].size();
        fichier << hauteur << " " << largeur << "\n";
        for(int i = 0; i < hauteur; i++){
            for(int j = 0; j < largeur; j++){
                if(grille[i][j] -> estVivante()){
                    fichier << 1;
                }
                else{
                    fichier << 0;
                }
                if(j < largeur - 1){
                    fichier << " ";
                }
            }
            fichier << "\n";
        }
        fichier.close();
    }
};

#endif