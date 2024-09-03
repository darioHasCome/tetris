#include "shapes.h"
#include<ncurses.h>
#ifndef TETRAMINO_H
#define TETRAMINO_H


class Tetramino {
protected:
    int startingy;
    int startingx;
    char Position[ROWS][COLUMNS];

public:
    // Costruttore
    Tetramino(int y, int x, char A[ROWS][COLUMNS]);
    int getY();
    int getX();
    void getShape(char dest[ROWS][COLUMNS]);
    bool collide(WINDOW* win);
    //metodi per il movimento
    void mvright(WINDOW* win);
    void mvleft(WINDOW* win);
    bool mvdown(WINDOW* win);
    void mvup(WINDOW* win);
    //metodi per cancellare e scrivere un tetramino
    void clearTetramino(WINDOW* win);
    void printTetramino(WINDOW* win);

    //metodo per creare un tetramino casuale in date coordinate.    SE TETRASPAWN CREA UNA COLLISIONE, GAMEOVER.
    static Tetramino tetraSpawn(int y, int x);

    // Metodi per ruotare il Tetramino
    void ruotasx(WINDOW* win);
    void ruotadx(WINDOW* win);
};

#endif // TETRAMINO_H