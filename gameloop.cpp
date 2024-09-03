#include "gameloop.h"

// Funzione per contare le cifre di un numero
int gameloop::countDigits(int num) {
    if (num == 0) return 1;  // Caso speciale per 0
    return std::floor(std::log10(num) + 1);
}

// Funzione per controllare se una linea è completa
bool gameloop::checkline(WINDOW* win, int index_riga) {
    for(int x = 0; x < 20; x++) {
        char ch = mvwinch(win, index_riga, x) & A_CHARTEXT;
        if (ch == ' ') return false;
    }
    return true;
}

// Funzione per cancellare una linea completa e aggiornare lo score
void gameloop::deleteline(WINDOW* win, int index_riga) {
    score += 100; // Aumenta il punteggio di 100

    // Fa scendere di uno tutti i pixel dalla linea cancellata
    for(int y = index_riga; y > 2; y--) {
        for(int x = 0; x < 20; x++) {
            char ch = mvwinch(win, y - 1, x) & A_CHARTEXT;
            mvwaddch(win, y, x, ch);
        }
    }
    move(0, 20);
    printw("SCORE: %d", score);
    refresh();
}

// Costruttore della classe gameloop
gameloop::gameloop() {
    // Inizializzazione NCurses
    clear(); // Pulisce lo schermo
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));
    nodelay(stdscr, TRUE); // Imposta l'input non bloccante

    // Crea una finestra per il gioco
    int height = 15, width = 20, start_y = 0, start_x = 0;
    score = 0; // Inizializza il punteggio
    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();
    box(win, 0, 0);
    move(0, 20);
    printw("SCORE: %d", score);
    move(1, 20);
    printw("LEVEL:");
    move(2, 20);
    printw("FULL LINES:");
    refresh();
    wrefresh(win);
    int time = 0;
    curs_set(0);

    // Genera un tetramino casuale usando il metodo tetraSpawn
    Tetramino tetramino = Tetramino::tetraSpawn(0, 5);

    // Stampa il tetramino nella finestra
    tetramino.printTetramino(win);
    int ch;
    bool tetraminoFissato = false;

    while (true) {
        ch = getch();
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
                    tetraminoFissato = !tetramino.mvdown(win);
                    break;
                case 'w':
                    tetramino.ruotasx(win);
                    break;
                case 'e':
                    tetramino.ruotadx(win);
                    break;
                case 'r':
                    tetramino = Tetramino::tetraSpawn(5, 5);
                    tetraminoFissato = false;
                    break;
            }
            // Visualizza il tempo
            mvprintw(3, 20, "Tempo: %i", time / 100);
            refresh();
            time++;
            if (time % 100 == 0) {
                tetraminoFissato = !tetramino.mvdown(win);
            }
            napms(10);
        }

        box(win, 0, 0); // Ripristina il bordo ad ogni iterazione

        tetramino.printTetramino(win);

        if (tetraminoFissato) {
            tetramino = Tetramino::tetraSpawn(1, 5);
            tetraminoFissato = false;
            for (int y = 2; y < height - 1; y++) {
                if (checkline(win, y)) {
                    deleteline(win, y);
                }
            }

            if (tetramino.collide(win)) {
                napms(1000);
                tetramino.printTetramino(win);
                finepartita(score);
                break;
            }
        }
    }
}