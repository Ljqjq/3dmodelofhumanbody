#ifndef HUMANBODY_HPP
#define HUMANBODY_HPP

#include "Torso.hpp"
#include "Leg.hpp"
#include "Arm.hpp"
#include "Head.hpp"

class API HumanBody {
private:
    Torso torso;
    Leg left_leg;
    Leg right_leg;
    Arm left_arm;
    Arm right_arm;
    Head head;

public:
    HumanBody();
    void draw(int start_y, int start_x);
    void set_colors(int head_color, int torso_color, int arm_color, int leg_color);
};

#endif // HUMANBODY_HPP