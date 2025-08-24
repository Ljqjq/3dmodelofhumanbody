#include "BodyPart.hpp"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <algorithm>

BodyPart::BodyPart() {}

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
    for (size_t y = 0; y < ascii_lines.size(); ++y) {
        const std::string& line = ascii_lines[y];
        mvaddstr(start_y + y, start_x, line.c_str());
    }
}

int BodyPart::getWidth() const { return width; }
int BodyPart::getHeight() const { return height; }

const std::vector<std::string>& BodyPart::get_lines() const {
    return ascii_lines;
}

BodyPart BodyPart::get_mirrored() const {
    BodyPart mirrored_part;
    mirrored_part.width = this->width;
    mirrored_part.height = this->height;
    
    for (const std::string& original_line : this->ascii_lines) {
        std::string mirrored_line = original_line;
        // Step 1: Transform specific characters for a correct mirror effect
        for (char& c : mirrored_line) {
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
        std::reverse(mirrored_line.begin(), mirrored_line.end());
        mirrored_part.ascii_lines.push_back(mirrored_line);
    }
    return mirrored_part;
}