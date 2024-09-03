#ifndef CLASSIFICA_H
#define CLASSIFICA_H

#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <string>
// Struttura per memorizzare i dati di un giocatore
struct Giocatore {
    std::string nome;
    int punteggio;
};

// Funzione che ordina i punteggi nel file "punteggio.txt"
void ordinaClassifica();

// Funzione che legge e visualizza la classifica
void classifica();

#endif