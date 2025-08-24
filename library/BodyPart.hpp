#ifndef BODYPART_HPP
#define BODYPART_HPP

#include <string>
#include <vector>

// This macro is for Windows compatibility but is harmless on Unix-like systems.
#define API __attribute__((visibility("default")))

class API BodyPart {
private:
    std::vector<std::string> ascii_lines;
    int width = 0;
    int height = 0;

public:
    // Getters
    int getWidth() const;
    int getHeight() const;
    const std::vector<std::string>& get_lines() const;

    // Methods
    BodyPart();

    BodyPart get_mirrored() const;
    void load_from_file(const std::string& filename);
    void draw(int start_y, int start_x) const;
};

#endif // BODYPART_HPP