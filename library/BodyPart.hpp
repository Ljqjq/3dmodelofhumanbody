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
    int color_pair_id = 0;

public:
    // Getters
    int getWidth() const;
    int getHeight() const;
    const std::vector<std::string>& get_lines() const;

    // Constructors
    BodyPart();

    BodyPart(const BodyPart& other); // Copy constructor
    BodyPart(BodyPart&& other) noexcept; // Move constructor
    BodyPart& operator=(const BodyPart& other); // Copy assignment operator
    BodyPart& operator=(BodyPart&& other) noexcept; // Move assignment operator
    
    // Methods 

    void set_color(int color_pair);
    void mirror();
    void load_from_file(const std::string& filename);
    void draw(int start_y, int start_x) const;
};

#endif // BODYPART_HPP