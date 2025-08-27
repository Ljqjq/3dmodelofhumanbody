#include "ConfigManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int color_from_string(const std::string& color_name) {
    if (color_name == "black") return COLOR_BLACK;
    if (color_name == "red") return COLOR_RED;
    if (color_name == "green") return COLOR_GREEN;
    if (color_name == "yellow") return COLOR_YELLOW;
    if (color_name == "blue") return COLOR_BLUE;
    if (color_name == "magenta") return COLOR_MAGENTA;
    if (color_name == "cyan") return COLOR_CYAN;
    if (color_name == "white") return COLOR_WHITE;
    return -1; // Indicate an invalid color
}

ConfigManager::ConfigManager() {
    // We can initialize with default values here
    state_to_color_pair[BodyState::normal] = 1;
    state_to_color_pair[BodyState::exhausted] = 2;
    state_to_color_pair[BodyState::damaged] = 3;
    state_to_color_pair[BodyState::critical] = 4;
}

void ConfigManager::load_colors_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open config file " << filename << std::endl;
        return;
    }

    std::string line;
    int pair_id = 1; // Start with the first color pair ID
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, equals, value;
        if (!(iss >> key >> equals >> value) || equals != "=") {
            continue; // Skip malformed lines
        }

        int foreground_color = color_from_string(value);
        int background_color = COLOR_BLACK; // Default background to black

        if (foreground_color != -1) {
            init_pair(pair_id, foreground_color, background_color);
            // Map the string key to the color pair ID
            if (key == "normal") {
                state_to_color_pair[BodyState::normal] = pair_id;
            } else if (key == "exhausted") {
                state_to_color_pair[BodyState::exhausted] = pair_id;
            } else if (key == "damaged") {
                state_to_color_pair[BodyState::damaged] = pair_id;
            } else if (key == "critical") {
                state_to_color_pair[BodyState::critical] = pair_id;
            }
            pair_id++;
        }
    }
    file.close();
}

int ConfigManager::get_color_pair(BodyState state) const {
    auto it = state_to_color_pair.find(state);
    if (it != state_to_color_pair.end()) {
        return it->second;
    }
    return 1; // Return default pair if not found
}
