#include <ncurses.h>



void stampa_titolo(){
    mvprintw(7, 52, "TETRIS");
    refresh();
}


int main() {
    initscr();  // Inizializza lo schermo
    clear();    // Pulisce lo schermo
    noecho();   // Disabilita l'eco dei tasti premuti
    cbreak();   // Disabilita il buffering dell'input
    curs_set(0);// Nasconde il cursore

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
    while(1) {
        // Stampa il menu con l'opzione attualmente evidenziata
        for(int i = 0; i < n_choices; ++i) {
            if(highlight == i + 1) { // Evidenzia l'opzione corrente
                wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i+1, 1, "%s", choices[i]);
                wattroff(menuwin, A_REVERSE);
            } else {
                mvwprintw(menuwin, i+1, 1, "%s", choices[i]);
            }
        }

        c = wgetch(menuwin);

        switch(c) {
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
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
        if(choice != 0) // Quando viene selezionata un'opzione
            break;
    }

    // Gestione delle opzioni
    if(choice == 1) {
        // Aggiungi qui il codice per iniziare un nuovo gioco
    } else if(choice == 2) {
      
        // Aggiungi qui il codice per visualizzare la classifica
    } else if(choice == 3) {
    
        endwin();
        // usciamo dal gioco 
    }
    

    endwin(); // Termina la finestra ncurses

    return 0;
}
