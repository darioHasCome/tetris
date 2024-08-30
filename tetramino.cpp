#include"tetramino.h"

Tetramino::Tetramino(int y, int x, char A[ROWS][COLUMNS]) {
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                this->Position[i][j] = A[i][j];
            }
        }
        this->startingy = y;
        this->startingx = x;
    }

int Tetramino::getY() {
    return startingy;
}

int Tetramino::getX() {
    return startingx;
}

void Tetramino::getShape(char dest[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            dest[i][j] = Position[i][j];
        }
    }
}
void Tetramino::mvright() {
        this->startingx+=2;
        /* if(INSERIRE FUNZIONE DI COLLISIONE) {
            mvleft();
        }
        */
    }
void Tetramino::mvleft() {
        this->startingx-=2;
        /* if(INSERIRE FUNZIONE DI COLLISIONE) {
            mvright();
        }
        */
    }
void Tetramino::mvdown() {
        this->startingy++;
        /* if(INSERIRE FUNZIONE DI COLLISIONE) {
            mvup();
        }*/
    }
void Tetramino::mvup() {
        this->startingy--;  //questa non ha bisogno di caso alternativo perche` attivata solo come risposta a un mvdown impossibile
    }
Tetramino Tetramino::tetraSpawn(int y, int x) {
        pNode shapeNode = chooseShape();
        return Tetramino(y, x, shapeNode->shape);
    }

void Tetramino::clearTetramino(WINDOW* win) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (Position[i][j] != '\0') {
                mvwaddch(win, startingy + i, startingx + j, ' ');  // Cancella il carattere
            }
        }
    }
}
void Tetramino::printTetramino(WINDOW* win) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (Position[i][j] != '\0') {
                mvwaddch(win, startingy + i, startingx + j, Position[i][j]);
            }
        }
    }
    wrefresh(win);
}

void Tetramino::ruotasx() {
        char rotated[ROWS][COLUMNS] = {0};
        int col = 0;
        for (int i=0; i<=3; i++) {
            int row = 0;
            for(int j = 6; j >=0; j-=2) {
                
                rotated[row][col] = this->Position[i][j];
                rotated[row][col+1] = this->Position[i][j+1];
                row++;
            }
            col+= 2;
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                this->Position[i][j] = rotated[i][j];
            }
        }
        /* if(INSERIRE FUNZIONE DI COLLISIONE) {
            ruotadx();
        }*/
    }

void Tetramino::ruotadx() {
        char rotated[ROWS][COLUMNS] = {0};
        int col = 0;
        for (int i=3; i>=0; i--) {
            int row = 0;
            for(int j = 0; j <=6; j+=2) {
                rotated[row][col] = this->Position[i][j];
                rotated[row][col+1] = this->Position[i][j+1];
                row++;
            }
            col+= 2;
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                this->Position[i][j] = rotated[i][j];
            }
        }
        /* if(INSERIRE FUNZIONE DI COLLISIONE) {
            ruotadx();
        }*/
    }


                                                                                      
