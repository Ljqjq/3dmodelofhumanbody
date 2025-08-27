#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <map>
#include <ncurses.h>
#include "BodyPart.hpp"

// Forward declaration to avoid circular dependencies
class BodyPart;

// A simple utility function to map string names to ncurses color codes.
int color_from_string(const std::string& color_name);

class API ConfigManager {
    private:
        std::map<BodyState, int> state_to_color_pair;
    
    public:
        ConfigManager();
        // Loads color configurations from a file and initializes ncurses color pairs.
        void load_colors_from_file(const std::string& filename);
        // Gets the ncurses color pair ID for a given BodyState.
        int get_color_pair(BodyState state) const;
};

#endif // CONFIGMANAGER_HPP