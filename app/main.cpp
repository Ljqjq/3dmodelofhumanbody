#include <ncurses.h>
#include <iostream>
#include <locale.h>
#include "../library/HumanBody.hpp"

int main() {
    // Set locale for wide character support
    setlocale(LC_ALL, "");

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    HumanBody body;
    int start_x = 40; // Starting x-position for the torso
    int start_y = 20;  // Starting y-position for the torso

   

    clear();

    body.draw(start_y, start_x);
    refresh();
    getch();
    endwin();

    return 0;
}