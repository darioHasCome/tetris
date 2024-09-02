#include <ncurses.h>



class gameloop
{
private:
    /* data */
public:
    gameloop();
    bool checkline(WINDOW* win, int index_line);

    void deleteline(WINDOW* win, int index_line);
};
