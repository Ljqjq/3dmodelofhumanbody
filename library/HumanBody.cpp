#include "HumanBody.hpp";

HumanBody::HumanBody() {
    // The constructors of each member are called automatically,
    // which handles the file loading for each part.
}


void HumanBody::set_head_state(BodyState state) { head.set_state(state); }
void HumanBody::set_torso_state(BodyState state) { torso.set_state(state); }
void HumanBody::set_left_arm_state(BodyState state) { left_arm.set_state(state); }
void HumanBody::set_right_arm_state(BodyState state) { right_arm.set_state(state); }
void HumanBody::set_left_leg_state(BodyState state) { left_leg.set_state(state); }
void HumanBody::set_right_leg_state(BodyState state) { right_leg.set_state(state); }

void HumanBody::draw(int start_y, int start_x, const ConfigManager& config) {
    // Draw Head
    head.draw(start_y, start_x, config);
    int head_height = head.getHeight();
    int head_width = head.getWidth();

    
    // Draw Torso
    int torso_y = start_y + head_height;
    torso.draw(torso_y, start_x, config);
    int torso_width = torso.getWidth();
    int torso_height = torso.getHeight();

    // Draw Legs below the torso
    int leg_y = start_y + torso_height + head_height;
    int leg_width = left_leg.getWidth();
    
    left_leg.draw(leg_y, start_x-leg_width+2, config);

    right_leg.mirror();
    right_leg.draw(leg_y, start_x + leg_width-2, config);

    
    // Draw Arms on the sides of the torso
    int arm_y = torso_y;
    
    int arm_width = left_arm.getWidth();
    left_arm.draw(torso_y, start_x - arm_width, config);

    right_arm.mirror();
    right_arm.draw(torso_y, start_x + torso_width + 1, config);




}

