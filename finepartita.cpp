#include "finepartita.h"
#include <fstream>
#include <iostream>

using namespace std;

void salvanome(char nome[], int score) {
    ofstream outputFile("punteggio.txt", ios::app); // Apertura del file in modalità append
    outputFile << nome << " " << score << endl;
    // Forza la scrittura nel file e chiude il file
    outputFile.flush(); // Assicurati che il buffer sia svuotato
    outputFile.close(); // Chiudi il file
}

void finepartita(int score){
    char nome[30];
    nodelay(stdscr, FALSE);
    clear();  // Pulisce lo schermo
    move(10, 50);  // Posiziona il cursore
    printw("Game over");  // Stampa il messaggio
    move(11, 50);
    printw("Nome giocatore:");
    move(12, 50);
    refresh();  // Aggiorna lo schermo per mostrare il messaggio
    getch();  // Attende l'input dell'utente
    echo();
    getnstr(nome, 30);
    noecho();
    salvanome(nome, score);
    endwin();  // Termina la modalità ncurses
}

