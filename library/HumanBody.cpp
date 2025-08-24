#include "HumanBody.hpp";

HumanBody::HumanBody() {
    // The constructors of each member are called automatically,
    // which handles the file loading for each part.
}

void HumanBody::draw(int start_y, int start_x) {
    // Draw Head
    head.draw(start_y, start_x);
    int head_height = head.getHeight();
    int head_width = head.getWidth();

    
    // Draw Torso
    int torso_y = start_y + head_height;
    torso.draw(torso_y, start_x);
    int torso_width = torso.getWidth();
    int torso_height = torso.getHeight();

    // Draw Legs below the torso
    int leg_y = start_y + torso_height + head_height;
    int leg_width = left_leg.getWidth();
    
    left_leg.draw(leg_y, start_x-leg_width+2);

    BodyPart right_leg = left_leg.get_mirrored();
    right_leg.draw(leg_y, start_x + leg_width-2);

    
    // Draw Arms on the sides of the torso
    int arm_y = torso_y;
    
    int arm_width = left_arm.getWidth();
    left_arm.draw(torso_y, start_x - arm_width);

    BodyPart right_arm = left_arm.get_mirrored();
    right_arm.draw(torso_y, start_x + torso_width + 1);




}

