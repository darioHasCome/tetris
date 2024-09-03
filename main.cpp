#include <ncurses.h>
#include "menu.h"
#include "classifica.h"
#include "gameloop.h"

int main() {
    initscr();  // Inizializza lo schermo
    clear();    // Pulisce lo schermo
    noecho();   // Disabilita l'eco dei tasti premuti
    cbreak();   // Disabilita il buffering dell'input
    curs_set(0);// Nasconde il cursore

    int choice;
    bool flag = true;

    // Ciclo principale che mostra il menu finche` l'utente non sceglie di uscire
    while (flag) {
        choice = mostra_menu(); // Richiama la funzione del menu e ottiene la scelta
        // Gestione delle opzioni
        if (choice == 1) {
            gameloop();  // Avvia il gioco
        } else if (choice == 2) {
            classifica();  // Visualizza la classifica
        } else if (choice == 3) {
            flag = false;  // Esce dal ciclo e termina il programma
        }
        clear();  // Pulisce lo schermo prima di tornare al menu
    }

    endwin(); // Termina la finestra ncurses

    return 0;
}