#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "tetramino.h"
#include "shapes.h"

int main() {
    // Inizializzazione NCurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));

    // Crea una finestra per il gioco
    WINDOW* win = newwin(20, 40, 0, 0);

    // Genera un tetramino casuale usando il metodo tetraSpawn
    Tetramino tetramino = Tetramino::tetraSpawn(5, 5);

    // Stampa il tetramino nella finestra
    tetramino.printTetramino(win);

    int ch;
    while ((ch = wgetch(stdscr)) != 'q') { // Premere 'q' per uscire
        tetramino.clearTetramino(win); // Cancella il tetramino dalla posizione corrente
        
        switch (ch) {
            case KEY_RIGHT:
                tetramino.mvright();
                break;
            case KEY_LEFT:
                tetramino.mvleft();
                break;
            case KEY_DOWN:
                tetramino.mvdown();
                break;
            case 'w': // Ruota a sinistra con 'w'
                tetramino.ruotasx();
                break;
            case 'e': // Ruota a destra con 'e'
                tetramino.ruotadx();
                break;
        }

        // Ridisegna il tetramino nella nuova posizione
        tetramino.printTetramino(win);
    }

    // Pulizia e uscita
    endwin();
    return 0;
}