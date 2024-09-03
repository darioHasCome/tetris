#include"menu.h"

void stampa_titolo() {
    mvprintw(7, 52, "TETRIS");
    refresh();
}

int mostra_menu() {
    int startx = 50, starty = 10;
    int width = 40, height = 10;
    int highlight = 1;
    int choice = 0;
    int c;

    WINDOW *menuwin = newwin(height, width, starty, startx);
    keypad(menuwin, TRUE); // Abilita la lettura dei tasti freccia
    refresh();

    const char *choices[] = {
        "Nuovo Gioco",
        "Classifica",
        "Uscire"
    };
    int n_choices = 3;

    stampa_titolo();

    while (1) {
        // Stampa il menu con l'opzione attualmente evidenziata
        for (int i = 0; i < n_choices; ++i) {
            if (highlight == i + 1) { // Evidenzia l'opzione corrente
                wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i + 1, 1, "%s", choices[i]);
                wattroff(menuwin, A_REVERSE);
            } else {
                mvwprintw(menuwin, i + 1, 1, "%s", choices[i]);
            }
        }

        c = wgetch(menuwin);

        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Tasto Enter
                choice = highlight;
                break;
            default:
                break;
        }
        if (choice != 0) // Quando viene selezionata un'opzione
            break;
    }

    delwin(menuwin);  // Elimina la finestra del menu prima di restituire la scelta
    return choice;
}
