#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "tetramino.h"
#include "shapes.h"
#include "finepartita.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

class gameloop {
private:
    int score;

    // Funzione per contare le cifre di un numero
    int countDigits(int num);

    // Funzione per controllare se una linea è completa
    bool checkline(WINDOW* win, int index_riga);

    // Funzione per cancellare una linea completa e aggiornare lo score
    void deleteline(WINDOW* win, int index_riga);

public:
    // Costruttore della classe gameloop che esegue il ciclo di gioco
    gameloop();
};

#endif