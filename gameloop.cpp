#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "tetramino.h"
#include "shapes.h"
#include "gameloop.h"
#include <cmath>

/*

 - linee check 
 - cancelliamo le linee e aggiungiamo i punti -

*/

int countDigits(int num) {
    if (num == 0) return 1;  // Caso speciale per 0
    return std::floor(std::log10(num) + 1);
}

bool gameloop::checkline(WINDOW* win, int index_riga)
{
    for(int x=0;x<20;x++)
    {
        char ch = mvwinch(win, index_riga, x)& A_CHARTEXT;
        if (ch == ' ') return false;
    }
    return true;
}

void gameloop::deleteline(WINDOW* win, int index_riga)
{
    //fa scendere di uno tutti i pixel dalla linea cancellata
    for(int y=index_riga;y>2;y--)
    {
        for(int x=0;x<20;x++)
        {
            char ch = mvwinch(win, y-1, x)& A_CHARTEXT;
            mvwaddch(win, y, x, ch);
        }
    }
}

gameloop::gameloop() {
    // Inizializzazione NCurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));
    nodelay(stdscr, TRUE); // Imposta l'input non bloccante

    // Crea una finestra per il gioco
    int height,width, start_y, start_x;
    height=15;
    width=20;
    start_y = 0;
    start_x = 0;
    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();
    box(win, 000, 000);
    move (0,20);
    printw("SCORE:");
    move (1,20);
    printw("LEVEL:");
    move (2,20);
    printw("FULL LINES:");
    refresh();
    wrefresh(win);
    int time = 0;
    initscr();
    curs_set(0);
    // Genera un tetramino casuale usando il metodo tetraSpawn
    Tetramino tetramino = Tetramino::tetraSpawn(0, 5);

    // Stampa il tetramino nella finestra
    tetramino.printTetramino(win);
    int ch;
    bool tetraminoFissato = false; // Aggiungi questa variabile per gestire il reset
    while (true) { // Premere 'q' per uscire
        ch = getch(); // Legge l'input senza bloccare
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

        mvprintw(3, 20, "Tempo: %i", time/100);
        mvdelch(3,28);
        mvdelch(3,29);
        mvdelch(3,30);
        time++;
        if(time%100==0)
        {
            tetraminoFissato = !tetramino.mvdown(win); // Se collide, fisso il tetramino
        }
        napms(10);
        }

        // Ridisegna il bordo della finestra
        box(win, 0, 0); // Ripristina il bordo ad ogni iterazione

        // Ridisegna il tetramino nella nuova posizione
        tetramino.printTetramino(win);

        // Se il tetramino è fissato, genera uno nuovo
        if (tetraminoFissato) {
            tetramino = Tetramino::tetraSpawn(1, 5);
            tetraminoFissato = false;
            for(int y=2;y<height-1;y++)
                {
                    if(checkline(win,y)){
                      deleteline(win,y);  
                    } 
                }
            // Se il nuovo tetramino collide immediatamente, il gioco è finito
            if (tetramino.collide(win)) {
                napms(1000);
                tetramino.printTetramino(win);
                break; // Esce dal ciclo e termina il gioco
            }
        }
    }
}