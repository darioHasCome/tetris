#include "shapes.h"

Node::Node(const char s[ROWS][COLUMNS]){
        for(int i = 0; i<ROWS; i++) {
            for(int j = 0; j<COLUMNS; j++){
                shape[i][j] = s[i][j];
            }
        }
        next = nullptr;
    };

    //funzione di aggiunta forma. ritorna la testa della lista di forme.
pNode addShape (pNode head, char s[ROWS][COLUMNS]) {
    if(head==nullptr) {
        pNode h = new Node(s);
        return h;
    }
    pNode tmp = head;
    while(tmp->next!=nullptr) {
        tmp = tmp->next;
    }
    pNode curr = new Node(s);
    tmp->next = curr;
    return head;
}

//funzione che inizializza la lista. ritorna la testa
pNode initSList() {
    //creo variabili con le sette forme dentro.                              |                                   |                                       |
    char shape_O[ROWS][COLUMNS]     =    {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[',']','[',']','\0','\0','\0','\0','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_I[ROWS][COLUMNS]     =    {'\0','\0','\0','\0','\0','\0','\0','\0','[',']','[',']','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_L[ROWS][COLUMNS]     =    {'\0','\0','[',']','\0','\0','\0','\0','\0','\0','[',']','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_L_rev[ROWS][COLUMNS] =    {'\0','\0','\0','\0','[',']','\0','\0','[',']','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_S[ROWS][COLUMNS]     =    {'\0','\0','[',']','[',']','\0','\0','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_S_rev[ROWS][COLUMNS] =    {'[',']','[',']','\0','\0','\0','\0','\0','\0','[',']','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char shape_T[ROWS][COLUMNS]     =    {'[',']','[',']','[',']','\0','\0','\0','\0','[',']','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    //con addShape creo la lista di sette forme.
    pNode list = addShape(nullptr, shape_O);
    list = addShape(list, shape_I);
    list = addShape(list, shape_L);
    list = addShape(list, shape_L_rev);
    list = addShape(list, shape_S);
    list = addShape(list, shape_S_rev);
    list = addShape(list, shape_T);

    return list;
    };


pNode chooseShape() {
    int x = rand()%7;
    pNode tmp = initSList();
    while(x>0) {
        tmp = tmp->next;
        x--;
    }
    return tmp;
}


//qui sotto commentati gli output degli array bidimensionali contenenti le 7 forme

//[][][][]  0|        |
//          1|[][][][]|
//          2|        |   shape_I
//          3|_ _ _ _ |
//            01234567    

//[][]   0|        |
//[][]   1|  [][]  | shape_O
//       2|  [][]  |
//       3|_ _ _ _ |
//         01234567

//[]                                                 
//[][][]    0|  []    |                 
//          1|  [][][]|                 
//          2|        |   shape_L       
//          3|_ _ _ _ |                 
//            01234567
   
//    []  
//[][][]    0|    []  |
//          1|[][][]  |
//          2|        |   shape_L_reverse
//          3|_ _ _ _ |
//            01234567

//  [][]  
//[][]      0|  [][]  |
//          1|[][]    |
//          2|        |   shape_S
//          3|_ _ _ _ |
//            01234567

//[][]  
//  [][]    0|[][]    |
//          1|  [][]  |
//          2|        |    shape_S_reverse
//          3|_ _ _ _ |
//            01234567

//[][][]  
//  []      0|[][][]  |
//          1|  []    |
//          2|        |    shape_T
//          3|_ _ _ _ |
//            01234567
