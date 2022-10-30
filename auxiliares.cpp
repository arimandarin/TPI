//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool adyacenteValida(tablero& t, pos p, int& f, int& c) {

    int p0 = p.first;
    int p1 = p.second;
    int q0 = p0 + f;
    int q1 = p1 + c;

    return (q0 >= 0 && q0 < t.size() && q1 >= 0 && q1 < t[0].size() && (f != 0 || c != 0));
}

bool posicionValida(tablero& t, pos p) {

    int p0 = p.first;
    int p1 = p.second;

    return (p0 >= 0 && p0 < t.size() && p1 >= 0 && p1 < t[0].size());
}

bool posicionJugada(jugadas& j, pos p) {

    for (int i = 0; i < j.size(); i++){
        if (j[i].first == p){
            return true;
        }
    }

    return false;
}

bool posicionTieneBanderita(banderitas& b, pos p) {

    for (int i = 0; i < b.size(); i++){
        if (b[i] == p){
            return true;
        }
    }
    return false;
}

//void agregarPosAJugadas(tablero& t, jugadas& j, banderitas& b, pos p) {
//
//    bool posJugada = posicionJugada(j,p);
//    bool posBanderita = posicionTieneBanderita(b,p);
//
//    if ( not posJugada && not posBanderita && t[p.first][p.second] == cVACIA){
//        j.push_back(make_pair(p, minasAdyacentes(t,p)));
//    }
//}
//

bool esAdyacente121(pos p, jugadas& j, tablero& t) {

    bool res = false;

    pos pos1 = make_pair(p.first-1, p.second);
    pos pos2 = make_pair(p.first+1, p.second);
    pos pos3 = make_pair(p.first, p.second-1);
    pos pos4 = make_pair(p.first, p.second+1);

    if (es121Horizontal(pos1,j, t) || es121Horizontal(pos2,j, t) || es121Vertical(pos3,j, t) || es121Vertical(pos4,j, t)){
        res = true;
    }

    return res;

}

bool es121Horizontal(pos p, jugadas& j, tablero& t) {

    bool res = false;

    pos pos1 = make_pair(p.first, p.second-1);
    pos pos2 = make_pair(p.first, p.second+1);

    if ((posicionJugada(j,p) && minasAdyacentes(t,p) == 2 ) && (posicionJugada(j,pos1) && minasAdyacentes(t,pos1) == 1 ) && (posicionJugada(j,pos2) && minasAdyacentes(t,pos2) == 1 )){
        res = true;
    }

    return res;
}

bool es121Vertical(pos p, jugadas& j, tablero& t){

    bool res = false;

    pos pos1 = make_pair(p.first-1, p.second);
    pos pos2 = make_pair(p.first+1, p.second);

    if ((posicionJugada(j,p) && minasAdyacentes(t,p) == 2 ) && (posicionJugada(j,pos1) && minasAdyacentes(t,pos1) == 1 ) && (posicionJugada(j,pos2) && minasAdyacentes(t,pos2) == 1 )){
        res = true;
    }

    return res;
}






