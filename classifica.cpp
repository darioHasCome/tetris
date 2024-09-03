#include "classifica.h"  // Includi l'header file
using namespace std;
// Definizione delle funzioni dichiarate nell'header file

void ordinaClassifica() {
    const int MAX_GIOCATORI = 100;
    Giocatore giocatori[MAX_GIOCATORI];  // Usa la struttura Giocatore dichiarata nell'header
    int numGiocatori = 0;

    // Apri il file per la lettura
    ifstream inputFile("punteggio.txt");
    if (!inputFile.is_open()) {
        cerr << "Errore: impossibile aprire il file punteggio.txt" << endl;
        return;
    }

    // Leggi i dati dal file
    while (inputFile >> giocatori[numGiocatori].nome >> giocatori[numGiocatori].punteggio) {
        numGiocatori++;
        if (numGiocatori >= MAX_GIOCATORI) {
            break; // Evita di superare la dimensione massima dell'array
        }
    }
    inputFile.close();

    // Ordina i dati usando un semplice bubble sort
    for (int i = 0; i < numGiocatori - 1; i++) {
        for (int j = 0; j < numGiocatori - i - 1; j++) {
            if (giocatori[j].punteggio < giocatori[j + 1].punteggio) {
                Giocatore temp = giocatori[j];
                giocatori[j] = giocatori[j + 1];
                giocatori[j + 1] = temp;
            }
        }
    }

    // Riscrivi il file con i dati ordinati
    ofstream outputFile("punteggio.txt");
    if (!outputFile.is_open()) {
        cerr << "Errore: impossibile aprire il file punteggio.txt per la scrittura" << endl;
        return;
    }

    for (int i = 0; i < numGiocatori; i++) {
        outputFile << giocatori[i].nome << " " << giocatori[i].punteggio << endl;
    }
    outputFile.close();
}

// Funzione che legge un file e lo stampa sul terminale usando ncurses
void classifica() {
    string line; 
    clear(); 
    ordinaClassifica();
    ifstream inputFile("punteggio.txt"); /* Dichiarazione di tipo */
    if (inputFile.is_open())
    {
        while (getline(inputFile, line)) {
            printw("%s\n", line.c_str());  // Usa printw di ncurses per stampare il testo
            refresh();
        }
        inputFile.close();
    }

    refresh();     
    getch(); 
    endwin(); 
}