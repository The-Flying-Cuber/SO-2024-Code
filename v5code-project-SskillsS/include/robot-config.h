using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Fleft;
extern motor Sleft;
extern motor Bleft;
extern motor Fright;
extern motor Sright;
extern motor Bright;
extern inertial Inertial;
extern motor Left;
extern motor Right;
extern controller Controller1;
extern digital_out RightDClimb;
extern digital_out RightUClimb;
extern digital_out RightWing;
extern triport Expander;
extern digital_out IntakeP;
extern digital_out ClimbPTO;
extern digital_out LeftUClimb;
extern digital_out LeftWing;
extern optical Optical;
extern digital_out LeftDClimb;
extern digital_out LeftBackWing;
extern digital_out RightBackWing;
extern digital_out IntakeD;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );