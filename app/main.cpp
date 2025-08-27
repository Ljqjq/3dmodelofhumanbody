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

 // Start color mode
    start_color();
    use_default_colors();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    
    HumanBody body;

    // Set unique colors for each body part
    body.set_colors(5, 5, 1, 3);

    int start_x = 40; // Starting x-position for the torso
    int start_y = 20;  // Starting y-position for the torso

   

    clear();
    attron(COLOR_PAIR(2));
    printw("And this in a green background!\n");

    body.draw(start_y, start_x);
    refresh();
    getch();
    endwin();

    return 0;
}