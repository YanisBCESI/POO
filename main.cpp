#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Cellule.hpp"
#include "grille.hpp"
#include "CalculEtatCellule.hpp"
#include "ChargeFichier.hpp"
#include "Affichage.hpp"
#include "verif.hpp"
using namespace std;

vector<vector<Cellule *>> jeu_vie = {{new CelluleMorte(0, 0), new CelluleMorte(1, 0),new CelluleMorte(2, 0),new CelluleMorte(3, 0),new CelluleMorte(4, 0),new CelluleMorte(5, 0),new CelluleMorte(6, 0),new CelluleMorte(7, 0),new CelluleMorte(8, 0),new CelluleMorte(9, 0)},
                                    {new CelluleMorte(0, 1), new CelluleMorte(1, 1),new CelluleMorte(2, 1),new CelluleMorte(3, 1),new CelluleMorte(4, 1),new CelluleMorte(5, 1),new CelluleMorte(6, 1),new CelluleMorte(7, 1),new CelluleMorte(8, 1),new CelluleMorte(9, 1)},
                                    {new CelluleMorte(0, 2), new CelluleMorte(1, 2),new CelluleMorte(2, 2),new CelluleMorte(3, 2),new CelluleMorte(4, 2),new CelluleMorte(5, 2),new CelluleMorte(6, 2),new CelluleMorte(7, 2),new CelluleMorte(8, 2),new CelluleMorte(9, 2)},
                                    {new CelluleMorte(0, 3), new CelluleMorte(1, 3),new CelluleMorte(2, 3),new CelluleVivante(3, 3),new CelluleMorte(4, 3),new CelluleMorte(5, 3),new CelluleMorte(6, 3),new CelluleMorte(7, 3),new CelluleMorte(8, 3),new CelluleMorte(9, 3)},
                                    {new CelluleMorte(0, 4), new CelluleMorte(1, 4),new CelluleMorte(2, 4),new CelluleMorte(3, 4),new CelluleVivante(4, 4),new CelluleMorte(5, 4),new CelluleMorte(6, 4),new CelluleMorte(7, 4),new CelluleMorte(8, 4),new CelluleMorte(9, 4)},
                                    {new CelluleMorte(0, 5), new CelluleMorte(1, 5),new CelluleVivante(2, 5),new CelluleVivante(3, 5),new CelluleVivante(4, 5),new CelluleMorte(5, 5),new CelluleMorte(6, 5),new CelluleMorte(7, 5),new CelluleMorte(8, 5),new CelluleMorte(9, 5)},
                                    {new CelluleMorte(0, 6), new CelluleMorte(1, 6),new CelluleMorte(2, 6),new CelluleMorte(3, 6),new CelluleMorte(4, 6),new CelluleMorte(5, 6),new CelluleMorte(6, 6),new CelluleMorte(7, 6),new CelluleMorte(8, 6),new CelluleMorte(9, 6)},
                                    {new CelluleMorte(0, 7), new CelluleMorte(1, 7),new CelluleMorte(2, 7),new CelluleMorte(3, 7),new CelluleMorte(4, 7),new CelluleMorte(5, 7),new CelluleMorte(6, 7),new CelluleMorte(7, 7),new CelluleMorte(8, 7),new CelluleMorte(9, 7)},
                                    {new CelluleMorte(0, 8), new CelluleMorte(1, 8),new CelluleMorte(2, 8),new CelluleMorte(3, 8),new CelluleMorte(4, 8),new CelluleMorte(5, 8),new CelluleMorte(6, 8),new CelluleMorte(7, 8),new CelluleMorte(8, 8),new CelluleMorte(9, 8)},
                                    {new CelluleMorte(0, 9), new CelluleMorte(1, 9),new CelluleMorte(2, 9),new CelluleMorte(3, 9),new CelluleMorte(4, 9),new CelluleMorte(5, 9),new CelluleMorte(6, 9),new CelluleMorte(7, 9),new CelluleMorte(8, 9),new CelluleMorte(9, 9)}
                                };


int main(){
    srand(time(NULL));
    string nomfichier;
    cout << "Nom du fichier (sensible a la case) : ";
    cin >> nomfichier;
    ChargeurGrille loader;
    Grille grille_jeu = loader.chargerDepuisFichier(nomfichier);
    CalculEtatCellule calculateur = {grille_jeu.getGrille()};
    int mode;
    cout << "Quel mode souhaitez-vous lancer  : \n [1] Mode console \n [2] Mode graphique." << endl;
    cin >> mode;
    if(mode == 1){
        int it;
        string ans;
        cout << "Voulez-vous lancer le mode test ? o/n (sensible a la case)." << endl;;
        cin >> ans;
        if(ans == "o"){
            string fichier_test;
            cout << "Quel est votre fichier de test ? (sensible a la case)." << endl;
            cin >> fichier_test;
            Grille grille_test = loader.chargerDepuisFichier(fichier_test);
            cout << "Quel est le nombre d'itérations souhaité ?" << endl;
            cin >> it;
            for(int i = 0; i <= it; i++){
                calculateur.SetTotalCellules(grille_jeu.getGrille());
                auto stock = calculateur.CalculGrille();
                grille_jeu.miseAJour(stock);
            }
            Verif testeur(grille_jeu.getGrille(), grille_test.getGrille());
            if(testeur.estMeme()){
                cout << "Les deux fichiers sont identiques, le code a été correctement exécuté.";
            }
            else{
                cout << "Les deux fichiers ne sont pas identiques, erreur d'exécution du code.";
            }
        }
        else{
            cout << "Donnez le nombre d'itérations voulues pour l'exécution." << endl;
            cin >> it;
            for(int i = 0; i <= it; i++){
                calculateur.SetTotalCellules(grille_jeu.getGrille());
                auto stock = calculateur.CalculGrille();
                grille_jeu.miseAJour(stock);
            }
            loader.chargerDansFichier(nomfichier, grille_jeu.getGrille());
        }
    }
    if(mode == 2){
        FenetreAffichage fenetre = {grille_jeu.getHauteur(), grille_jeu.getLargeur(), "Jeu de la vie"};
        while(fenetre.estOuverte()){
            if(grille_jeu.ResteCellulesVivantes() == 0){
                fenetre.fermer();
                return 0;
            }
            fenetre.afficher(grille_jeu.getGrille());
            calculateur.SetTotalCellules(grille_jeu.getGrille());
            auto stock = calculateur.CalculGrille();
            grille_jeu.miseAJour(stock);
            sf::sleep(sf::milliseconds(1000));
        }
    }
    return 0;
}
