#include <ncurses.h>
#include <iostream>
#include <locale.h>
#include "../library/HumanBody.hpp"
#include "../library/ConfigManager.hpp"

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

    ConfigManager config_manager;
    config_manager.load_colors_from_file("../config/colors.conf");
    

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    
    HumanBody body;

    // Set unique colors for each body part
    body.set_head_state(BodyState::normal);
    body.set_torso_state(BodyState::exhausted);
    body.set_left_arm_state(BodyState::normal);
    body.set_right_arm_state(BodyState::damaged);
    body.set_left_leg_state(BodyState::normal);
    body.set_right_leg_state(BodyState::critical);

    int start_x = 40; // Starting x-position for the torso
    int start_y = 20;  // Starting y-position for the torso

   

    clear();
    attron(COLOR_PAIR(2));
    printw("And this in a green background!\n");

    body.draw(start_y, start_x, config_manager);
    refresh();
    getch();
    endwin();

    return 0;
}