#include <ncurses.h>
#include <iostream>
#include <locale.h>
#include "../library/BodyPart.hpp"

int main() {
    // Set locale for wide character support
    setlocale(LC_ALL, "");

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // This is crucial for wide character support in ncurses
    // It tells ncurses to use the locale set above
    
    
   

    BodyPart test_part;
    test_part.load_from_file("../../assets/arm.txt"); // Or whatever file you use

    clear();
    test_part.draw(10, 20);

    refresh();
    getch();
    endwin();

    return 0;
}