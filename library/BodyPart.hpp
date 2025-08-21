#ifndef BODYPART_HPP
#define BODYPART_HPP

#include <string>
#include <vector>
#include <cwchar> // For wide character types

#define API __attribute__((visibility("default")))

class API BodyPart {
private:
    std::vector<std::wstring> ascii_lines;
    int width = 0;
    int height = 0;

public:
    // Getters
    int getWidth() const;
    int getHeight() const;

    // Methods
    BodyPart();
    void load_from_file(const std::string& filename);
    void draw(int start_y, int start_x) const;
};

#endif // BODYPART_HPP