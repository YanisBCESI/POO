#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Cellule{
    protected : 
        int voisins;
        const int coordonneeX;
        const int coordonneeY;
    public:
        Cellule(int X, int Y) : coordonneeX(X), coordonneeY(Y) {};
        int *getCoordonnees(){
            cout << "Coordonnées X : " << coordonneeX << endl;
            cout << "Coordonnées Y : " <<  coordonneeY << endl;
            int tab_coo [2] = {coordonneeX, coordonneeY};
            return tab_coo;
        }
        virtual bool estVivante(){}
        int getVoisins(){
            return voisins;
        }
        bool setVoisins(int x){
            if(0 <= x <= 8){
                voisins = x;
                return true;
            }
            return false;
        }
};

class CelluleMorte : public Cellule{
    public :
        bool estVivante() override {
            return false;
        }
};

class CelluleVivante : public Cellule{
    public :
        bool estVivante() override{
            return true;
        }
};