#include <cstdlib>
#ifndef SHAPESLIST_H
#define SHAPESLIST_H

const int ROWS = 4;
const int COLUMNS = 8;

struct Node;

typedef Node* pNode;

struct Node {
    char shape[ROWS][COLUMNS];
    Node* next;

    Node(const char s[ROWS][COLUMNS]);
};
    // Funzione per aggiungere una forma alla lista
pNode addShape(pNode head, char s[ROWS][COLUMNS]);

    // Funzione per inizializzare la lista di forme
pNode initSList();


pNode chooseShape();

#endif