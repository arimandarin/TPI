
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool adyacenteValida(tablero& t, pos p, int& f, int& c);
bool posicionValida(tablero& t, pos p);
bool posicionJugada(jugadas& j, pos p);
bool posicionTieneBanderita(banderitas& b, pos p);
//void agregarPosAJugadas(tablero& t, jugadas& j, banderitas& b, pos p);
bool esAdyacente121(pos p, jugadas& j, tablero& t);
bool es121Horizontal(pos p, jugadas& j, tablero& t);
bool es121Vertical(pos p, jugadas& j, tablero& t);



