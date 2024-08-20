#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Fleft                motor         20              
// Sleft                motor         19              
// Bleft                motor         18              
// Fright               motor         11              
// Sright               motor         12              
// Bright               motor         13              
// Inertial             inertial      16              
// Left                 motor         14              
// Right                motor         17              
// Controller1          controller                    
// RightDClimb          digital_out   B               
// RightUClimb          digital_out   E               
// RightWing            digital_out   A               
// Expander             triport       1               
// IntakeP              digital_out   G               
// ClimbPTO             digital_out   H               
// LeftUClimb           digital_out   C               
// LeftWing             digital_out   D               
// Optical              optical       2               
// LeftDClimb           digital_out   F               
// LeftBackWing         digital_out   G               
// RightBackWing        digital_out   H               
// IntakeD              digital_out   F               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,
//TANK_TWO_ROTATION,


//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(Fleft, Sleft, Bleft),

//Right Motors:
motor_group(Fright, Sright, Bright),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT16,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2.75,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
4,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.5,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
5,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

bool shoot = false;


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int current_auton_selection = 6;
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool auto_started = false;

int start = 7;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  LeftWing.set(false);
  RightWing.set(false);
  Inertial.calibrate();
  while(Inertial.isCalibrating()) {
    task::sleep(100);
  }

  // wait(2500, msec);
  if (start == 1 and current_auton_selection != 3)
  {
    IntakeP.set(true);
    
  }

  else if (start == 1 and current_auton_selection == 3)
  {
    IntakeP.set(true);
    
  }

  else
  {
    IntakeP.set(true);
  }

  LeftWing.set(false);
  RightWing.set(false);


  start = 2;

  //wait(10, msec);


  

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Drive Test");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "6 ball");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "win Point");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "close_side");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "skills");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "far_side");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      drive_test(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      drive_test();
      break;
    case 2:
      six_ball();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      close_side();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      skills();
      break;
    case 7:
      far_side();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


int Switch = 1;
int Switch2 = 1;
int Switch3 = 1;
int Switch4 = 1;
int Switch5 = 1;
int Switch6 = 1;
int Switch7 = 1;
int Switch8 = 1;


int C1()
{
  wait(50, timeUnits::msec);
  Switch = 2;
  return 0;
}

int C2()
{
  wait(50, timeUnits::msec);
  Switch = 1;
  return 0;
}

int B1()
{
  wait(50, timeUnits::msec);
  Switch4 = 2;
  return 0;
}

int B2()
{
  wait(50, timeUnits::msec);
  Switch4 = 1;
  return 0;
}


int K1()
{
  wait(50, timeUnits::msec);
  Switch2 = 2;
  return 0;
}

int K2()
{
  wait(50, timeUnits::msec);
  Switch2 = 1;
  return 0;
}

int W1()
{
  wait(50, timeUnits::msec);
  Switch3 = 2;
  return 0;
}

int W2()
{
  wait(50, timeUnits::msec);
  Switch3 = 1;
  return 0;
}


int Z1()
{
  wait(50, timeUnits::msec);
  Switch5 = 2;
  return 0;
}

int Z2()
{
  wait(50, timeUnits::msec);
  Switch5 = 1;
  return 0;
}

int P1()
{
  wait(50, timeUnits::msec);
  Switch6 = 2;
  return 0;
}

int P2()
{
  wait(50, timeUnits::msec);
  Switch6 = 1;
  return 0;
}
int P3()
{
  wait(50, timeUnits::msec);
  Switch7 = 2;
  return 0;
}

int P4()
{
  wait(50, timeUnits::msec);
  Switch7 = 1;
  return 0;
}
int P5()
{
  wait(50, timeUnits::msec);
  Switch8 = 2;
  return 0;
}

int P6()
{
  wait(50, timeUnits::msec);
  Switch8 = 1;
  return 0;
}


void usercontrol(void) {
  // User control code here, inside the loop
   IntakeP.set(false);
   LeftWing.set(false);
   RightWing.set(false);
   LeftBackWing.set(false);
   RightBackWing.set(false);
   //drive_test();
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    
    chassis.control_arcade();


   if (Controller1.ButtonY.pressing())
  {
    if (Switch2 == 1)
        {  
          IntakeP.set(true);       
          (vex::task(K1));
        }
        else if (Switch2 == 2)  
        {
          IntakeP.set(false);
          (vex::task(K2));
        }         
  }



  if (Controller1.ButtonL2.pressing())
  {
    if (Switch3 == 1)
        {  
          LeftWing.set(true);
          RightWing.set(true);       
          (vex::task(W1));
        }
        else if (Switch3 == 2)  
        {
          LeftWing.set(false);
          RightWing.set(false);
          (vex::task(W2));
        }         
  }

   if (Controller1.ButtonL1.pressing())
  {
    if (Switch == 1)
        {  
          LeftBackWing.set(true);
          RightBackWing.set(true);
                 
          (vex::task(C1));
        }
        else if (Switch == 2)  
        {
          LeftBackWing.set(false);
          RightBackWing.set(false);
          (vex::task(C2));
        }         
  }

  

  //  if (Controller1.ButtonR1.pressing() and chg == false )
  // {      
  //   thread shoot = thread(shoot1);
  // }

  // else if (Controller1.ButtonR1.pressing() and chg == true )
  // {      
  //   thread shoot = thread(shoot2);
  // }

    if(Controller1.ButtonR2.pressing())
    {
      Left.spin(fwd, 450, rpm);
      Right.spin(fwd, 450, rpm);
    }

    else if(Controller1.ButtonR1.pressing())
    {
      Left.spin(reverse, 600, rpm);
      Right.spin(reverse,600, rpm);
    }

    else if (shoot == false)
    {
      Left.stop(coast);
      Right.stop(coast);
    }

  if (Controller1.ButtonUp.pressing())
  {
    if (Switch6 == 1)
        {  
          ClimbPTO.set(true);       
          (vex::task(P1));
        }
        else if (Switch6 == 2)  
        {
          ClimbPTO.set(false);
          (vex::task(P2));
        }         
  }


  if (Controller1.ButtonRight.pressing())
  {
    if (Switch7 == 1)
        {  
          RightUClimb.set(true);
          LeftUClimb.set(true);
          RightDClimb.set(false);
          LeftDClimb.set(false);       
          (vex::task(P3));
        }
        else if (Switch7 == 2)  
        {
          RightUClimb.set(false);
          LeftUClimb.set(false);
          (vex::task(P4));
        }         
  }

  if (Controller1.ButtonUp.pressing())
  {
    RightUClimb.set(false);
    LeftUClimb.set(false);
    RightDClimb.set(true);
    LeftDClimb.set(true);       
    (vex::task(P4));       
  }



    if (Controller1.ButtonX.pressing())
  {
    if (Switch4 == 1)
        {  
          
          //Blocker2.set(true);      
          (vex::task(B1));
        }
        else if (Switch4 == 2)  
        {
          
          //Blocker2.set(false);
          (vex::task(B2));
        }         
  }

  if (Controller1.ButtonB.pressing())
  {
    if (Switch5 == 1)
        {  
          IntakeD.set(true);      
          (vex::task(Z1));
        }
        else if (Switch5 == 2)  
        {
          IntakeD.set(false);
          (vex::task(Z2));
        }         
  }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
