#include <ncurses.h>
#include "menu.h"
#include "classifica.h"
#include "gameloop.h"

void stampa_titolo() {
    mvprintw(7, 52, "TETRIS");
    refresh();
}

WINDOW* crea_finestra_menu(int height, int width, int starty, int startx) {
    WINDOW *menuwin = newwin(height, width, starty, startx);
    keypad(menuwin, TRUE); // Abilita la lettura dei tasti freccia
    refresh();
    return menuwin;
}

void stampa_menu(WINDOW *menuwin, int highlight, const char *choices[], int n_choices) {
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) { // Evidenzia l'opzione corrente
            wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, "%s", choices[i]);
            wattroff(menuwin, A_REVERSE);
        } else {
            mvwprintw(menuwin, i + 1, 1, "%s", choices[i]);
        }
    }
    wrefresh(menuwin); // Aggiorna la finestra del menu per riflettere le modifiche
}

int gestisci_input_menu(WINDOW *menuwin, int *highlight, int n_choices) {
    int c = wgetch(menuwin);

    switch (c) {
        case KEY_UP:
            if (*highlight == 1)
                *highlight = n_choices;
            else
                --(*highlight);
            break;
        case KEY_DOWN:
            if (*highlight == n_choices)
                *highlight = 1;
            else
                ++(*highlight);
            break;
        case 10: // Tasto Enter
            return *highlight;
        default:
            break;
    }
    return 0; // Nessuna scelta effettuata
}

int mostra_menu() {
    int startx = 50, starty = 10;
    int width = 40, height = 10;
    int highlight = 1;
    int choice = 0;

    const char *choices[] = {
        "Nuovo Gioco",
        "Classifica",
        "Uscire"
    };
    int n_choices = 3;

    WINDOW *menuwin = crea_finestra_menu(height, width, starty, startx);
    stampa_titolo(); // Stampa il titolo del gioco
    bool flag = true;
    while (flag) {
        stampa_menu(menuwin, highlight, choices, n_choices); // Stampa le opzioni del menu

        choice = gestisci_input_menu(menuwin, &highlight, n_choices); // Gestisce l'input dell'utente
        if (choice != 0) // Se è stata effettuata una scelta
            flag = false;
    }

    delwin(menuwin);  // Elimina la finestra del menu prima di restituire la scelta
    return choice;
}