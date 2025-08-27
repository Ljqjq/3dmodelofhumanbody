#ifndef HUMANBODY_HPP
#define HUMANBODY_HPP

#include "Torso.hpp"
#include "Leg.hpp"
#include "Arm.hpp"
#include "Head.hpp"
#include "ConfigManager.hpp"

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
    void draw(int start_y, int start_x, const ConfigManager& config);
    void set_colors(int head_color, int torso_color, int arm_color, int leg_color);
    void set_head_state(BodyState state);
    void set_torso_state(BodyState state);
    void set_left_arm_state(BodyState state);
    void set_right_arm_state(BodyState state);
    void set_left_leg_state(BodyState state);
    void set_right_leg_state(BodyState state);
};

#endif // HUMANBODY_HPP