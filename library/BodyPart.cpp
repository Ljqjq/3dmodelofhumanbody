#include "BodyPart.hpp"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>

BodyPart::BodyPart() {}

void BodyPart::load_from_file(const std::string& filename) {
    // Use a codecvt converter to read the file as wide characters
    std::locale loc("");
    std::wifstream file(filename);
    file.imbue(loc);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::wstring line;
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
        const std::wstring& line = ascii_lines[y];
        // Use mvaddwstr for wide strings instead of mvaddch
        mvaddwstr(start_y + y, start_x, line.c_str());
    }
}

// Getters implementation (remain unchanged)
int BodyPart::getWidth() const {
    return width;
}

int BodyPart::getHeight() const {
    return height;
}