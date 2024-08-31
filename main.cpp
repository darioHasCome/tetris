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
    box(win, 0, 0);
    wrefresh(win);

    // Genera un tetramino casuale usando il metodo tetraSpawn
    Tetramino tetramino = Tetramino::tetraSpawn(5, 5);

    // Stampa il tetramino nella finestra
    tetramino.printTetramino(win);
int ch;
    bool tetraminoFissato = false; // Aggiungi questa variabile per gestire il reset
    while ((ch = wgetch(stdscr)) != 'q') { // Premere 'q' per uscire
        tetramino.clearTetramino(win); // Cancella il tetramino dalla posizione corrente

        if (!tetraminoFissato) {
            switch (ch) {
                case KEY_RIGHT:
                    tetramino.mvright(win);
                    break;
                case KEY_LEFT:
                    tetramino.mvleft(win);
                    break;
                case KEY_DOWN:
                    tetraminoFissato = !tetramino.mvdown(win); // Se collide, fisso il tetramino
                    break;
                case 'w': // Ruota a sinistra con 'w'
                    tetramino.ruotasx(win);
                    break;
                case 'e': // Ruota a destra con 'e'
                    tetramino.ruotadx(win);
                    break;
                case 'r': // Reset tetramino
                    tetramino = Tetramino::tetraSpawn(5, 5);
                    tetraminoFissato = false;
                    break;
            }
        }

        // Ridisegna il bordo della finestra
        box(win, 0, 0); // Ripristina il bordo ad ogni iterazione

        // Ridisegna il tetramino nella nuova posizione
        tetramino.printTetramino(win);

        // Se il tetramino è fissato, genera uno nuovo
        if (tetraminoFissato) {
            tetramino = Tetramino::tetraSpawn(5, 5);
            tetraminoFissato = false;

            // Se il nuovo tetramino collide immediatamente, il gioco è finito
            if (tetramino.collide(win)) {
                break; // Esce dal ciclo e termina il gioco
            }
        }
    }

    // Pulizia e uscita
    endwin();
    return 0;
}