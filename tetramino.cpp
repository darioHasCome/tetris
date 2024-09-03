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

bool Tetramino::collide(WINDOW* win) {
    for (int y=0; y<ROWS; y++) {
        for (int x=0; x<COLUMNS; x++) {
            if(Position[y][x]!='\0'){
                int boardy = y+startingy;
                int boardx = x+startingx;
                char ch = mvwinch(win, boardy, boardx) & A_CHARTEXT;
                if (ch!=' ') return true;
            }
        }
    }
    return false;
}
void Tetramino::mvright(WINDOW* win) {
        this->startingx+=2;
        if(collide(win)) {
            mvleft(win);
        }
        
    }
void Tetramino::mvleft(WINDOW* win) {
        this->startingx-=2;
        if(collide(win)) {
            mvright(win);
        }
        
    }
bool Tetramino::mvdown(WINDOW* win) {
        this->startingy++;
        if(collide(win)) {
            mvup(win);
            return false;
        }
        return true;
    }
void Tetramino::mvup(WINDOW* win) {
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

void Tetramino::ruotasx(WINDOW* win) {
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
        if(collide(win)) {
            ruotadx(win);
        }
    }

void Tetramino::ruotadx(WINDOW* win) {
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
        if(collide(win)) {
            ruotadx(win);
        }
    }


                                                                                      
