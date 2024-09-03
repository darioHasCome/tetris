#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
void stampa_titolo();
WINDOW* crea_finestra_menu(int height, int width, int starty, int startx);
void stampa_menu(WINDOW *menuwin, int highlight, const char *choices[], int n_choices);
int gestisci_input_menu(WINDOW *menuwin, int *highlight, int n_choices);
int mostra_menu();

#endif