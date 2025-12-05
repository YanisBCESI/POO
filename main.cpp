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
        int attente;
        int compteur_meme = 0;
        vector<vector<Cellule*>> a = {{new CelluleMorte(0,0)}};
        cout << "Combien de temps souhaitez vous qu'il s'écoule entre 2 itérations (en ms) ?" << endl;
        cin >> attente;
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
            sf::sleep(sf::milliseconds(attente));
            a = grille_jeu.getGrille();
        }
    }
    return 0;
}
