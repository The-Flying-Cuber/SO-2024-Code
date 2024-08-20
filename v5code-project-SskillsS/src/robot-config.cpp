#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport Expander = triport(PORT1);
motor Fleft = motor(PORT20, ratio6_1, true);
motor Sleft = motor(PORT19, ratio6_1, true);
motor Bleft = motor(PORT18, ratio6_1, true);
motor Fright = motor(PORT11, ratio6_1, false);
motor Sright = motor(PORT12, ratio6_1, false);
motor Bright = motor(PORT13, ratio6_1, false);
inertial Inertial = inertial(PORT16);
motor Left = motor(PORT14, ratio6_1, true);
motor Right = motor(PORT17, ratio6_1, false);
controller Controller1 = controller(primary);
digital_out RightDClimb = digital_out(Expander.B);
digital_out RightUClimb = digital_out(Expander.E);
digital_out RightWing = digital_out(Expander.A);
digital_out IntakeP = digital_out(Expander.G);
digital_out ClimbPTO = digital_out(Expander.H);
digital_out LeftUClimb = digital_out(Expander.C);
digital_out LeftWing = digital_out(Expander.D);
optical Optical = optical(PORT2);
digital_out LeftDClimb = digital_out(Expander.F);
digital_out LeftBackWing = digital_out(Brain.ThreeWirePort.G);
digital_out RightBackWing = digital_out(Brain.ThreeWirePort.H);
digital_out IntakeD = digital_out(Brain.ThreeWirePort.F);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}