#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Cellule{
    protected : 
        int voisins;
        int coordonneeX;
        int coordonneeY;
    public:
        Cellule(int X, int Y) : coordonneeX(X), coordonneeY(Y) {};
        int *getCoordonnees(){
            cout << "Coordonnées X : " << coordonneeX << endl;
            cout << "Coordonnées Y : " <<  coordonneeY << endl;
            int tab_coo [2] = {coordonneeX, coordonneeY};
            return tab_coo;
        }
        void setCoordonnees(int x, int y){
            coordonneeX = x;
            coordonneeY = y;
        }
        virtual bool estVivante(){}
        virtual int getVoisins(){}
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
        CelluleMorte(int x, int y) : Cellule(x, y) {}
        bool estVivante() override {
            return false;
        }
        int getVoisins() override{
            if (voisins > 3 || voisins < 2){
                return voisins;
            }
            throw runtime_error("Cellule morte possède assez de voisins vivants");
        }
};

class CelluleVivante : public Cellule{
    public :
        CelluleVivante(int x, int y) : Cellule(x,y) {}
        bool estVivante() override{
            return true;
        }
        int getVoisins() override{
            if (voisins >=2 && voisins <= 3){
                return voisins;
            }
            throw runtime_error("Cellule vivante possède trop (peu) de voisins vivants");
        }
};