#include "BodyPart.hpp"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <algorithm>

BodyPart::BodyPart() {}

// Copy Constructor
BodyPart::BodyPart(const BodyPart& other)
    : ascii_lines(other.ascii_lines),
      width(other.width),
      height(other.height),
      color_pair_id(other.color_pair_id) {}

// Move Constructor
BodyPart::BodyPart(BodyPart&& other) noexcept
    : ascii_lines(std::move(other.ascii_lines)),
      width(other.width),
      height(other.height),
      color_pair_id(other.color_pair_id) {
    // Leave the moved-from object in a valid, empty state
    other.width = 0;
    other.height = 0;
    other.color_pair_id = 0;
}

// Copy Assignment Operator
BodyPart& BodyPart::operator=(const BodyPart& other) {
    if (this != &other) { // Handle self-assignment
        ascii_lines = other.ascii_lines;
        width = other.width;
        height = other.height;
        color_pair_id = other.color_pair_id;
    }
    return *this;
}

// Move Assignment Operator
BodyPart& BodyPart::operator=(BodyPart&& other) noexcept {
    if (this != &other) { // Handle self-assignment
        ascii_lines = std::move(other.ascii_lines);
        width = other.width;
        height = other.height;
        color_pair_id = other.color_pair_id;
        
        // Leave the moved-from object in a valid, empty state
        other.width = 0;
        other.height = 0;
        other.color_pair_id = 0;
    }
    return *this;
}


void BodyPart::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    int max_width = 0;
    while (std::getline(file, line)) {
        ascii_lines.push_back(line);
        if (line.length() > max_width) {
            max_width = line.length();
        }
    }
    file.close();

    height = ascii_lines.size();
    width = max_width;
}

void BodyPart::draw(int start_y, int start_x) const {
    // Check if a color has been set and if ncurses is in color mode
    if (color_pair_id > 0 && has_colors()) {
        attron(COLOR_PAIR(color_pair_id));
    }
    
    for (size_t y = 0; y < ascii_lines.size(); ++y) {
        const std::string& line = ascii_lines[y];
        mvaddstr(start_y + y, start_x, line.c_str());
    }
    
    // Turn off color attributes after drawing
    if (color_pair_id > 0 && has_colors()) {
        attroff(COLOR_PAIR(color_pair_id));
    }
}

int BodyPart::getWidth() const { return width; }
int BodyPart::getHeight() const { return height; }

void BodyPart::set_color(int color_pair) {
    color_pair_id = color_pair;
}

const std::vector<std::string>& BodyPart::get_lines() const {
    return ascii_lines;
}

void BodyPart::mirror() {
    for (std::string& line : this->ascii_lines) {
        // Step 1: Transform specific characters for a correct mirror effect
        for (char& c : line) {
            switch (c) {
                case '/': c = '\\'; break;
                case '\\': c = '/'; break;
                case '(': c = ')'; break;
                case ')': c = '('; break;
                case '[': c = ']'; break;
                case ']': c = '['; break;
                case '{': c = '}'; break;
                case '}': c = '{'; break;
            }
        }
        // Step 2: Reverse the string
        std::reverse(line.begin(), line.end());
    }
}