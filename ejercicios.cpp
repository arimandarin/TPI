//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {

    int minas = 0;
    int p0 = p.first;
    int p1 = p.second;

    for(int fila = -1; fila<=1; fila++){
        for(int col = -1; col <=1; col++){

            if (adyacenteValida(t,p, fila, col) && t[p0+fila][p1+col] == cMINA){
                minas++;
            }
        }
    }

    return minas;

}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {

    for (int i = 0; i < b.size(); i++){
        if (b[i] == p){
            b.erase(b.begin()+i);
            return;
        }
    }

    if (not(posicionJugada(j,p))){
        b.push_back(p);
    }


}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {

    bool res = false;
    for (int i = 0; i < j.size(); i++){

        pair<int,int> p = j[i].first;
        int p0 = p.first;
        int p1 = p.second;

        if (t[p0][p1] == cMINA){
            res = true;
        }
    }

    return res;

}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {

    bool res = false;

    for (int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){
            pos p = make_pair(i,k);
            if (posicionValida(t,p)){
                if (t[i][k] == cVACIA && posicionJugada(j,p)){
                    res = true;
                }
            }
        }
    }
    return res;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {

    bool posJugada = posicionJugada(j,p);
    bool posBanderita = posicionTieneBanderita(b,p);

    if ( not posJugada && not posBanderita && t[p.first][p.second] == cVACIA){

        int cantidadMinasAdyacentes = minasAdyacentes(t,p);
        j.push_back(make_pair(p, cantidadMinasAdyacentes));

        if (cantidadMinasAdyacentes == 0){
            for(int fila = -1; fila<=1; fila++){
                for(int col = -1; col <=1; col++){
                    if (adyacenteValida(t,p, fila, col)){
                        pos q = make_pair(p.first+fila, p.second+col);
                        jugarPlus(t, b, q, j);
                    }
                }
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {

    bool hay = false;
    for (int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){

            pos q = make_pair(i,k);
            if (t[i][k] == cVACIA && posicionValida(t,q) && not posicionTieneBanderita(b,q) && not posicionJugada(j,q) && esAdyacente121(q, j, t)){
                p = q;
                j.push_back(make_pair(p, minasAdyacentes(t,p)));
                hay = true;
            }
        }
    }
    return hay;
}

