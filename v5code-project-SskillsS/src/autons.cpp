#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(4, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
 // Start Odom thread
thread cord = thread(odom_test);
//Set Odom Constants
//and Drive Constance
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 7;
  chassis.heading_max_voltage = 2;
  chassis.turn_max_voltage = 2;
  chassis.swing_max_voltage = 2;

//Set settle times
  chassis.drive_settle_time = 0;
  chassis.turn_settle_time = 0;
  chassis.swing_settle_time = 1;

  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)

  ///////////////////////////'First Two Red Balls'/////////////////////////////////
  //set up exit conditions for the first movment to push red balls 
  chassis.set_drive_exit_conditions(4, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  //first pass through point
  chassis.drive_to_point(0.0, -7.4);

  //'PUSH IN GOAL'//
  chassis.set_drive_exit_conditions(1, 10, 1400);
  chassis.drive_to_point(-9.0, -27.98);

  //move away from goal to get ready to line up
  chassis.set_drive_exit_conditions(1, 50, 1400);
  chassis.drive_to_point(-5.12, -23.05);
  chassis.set_drive_exit_conditions(1, 50, 1400);

  //Sets Up the max power for the swing turn
  chassis.swing_max_voltage = 12;
  chassis.turn_max_voltage = 5;
  chassis.heading_max_voltage = 12;

  //swing turn exit conditions
  chassis.set_swing_exit_conditions(0, 10, 1700);
  //swing turn with right side of bot 
  chassis.right_swing_to_angle(291.104);

  //sets up max voltages for the drive
  chassis.heading_max_voltage = 2;
  chassis.drive_max_voltage = 5;
  //lines up to get ready to match load

  //wait(10000000000, msec);
  //chassis.drive_to_point(0.76, -19.29);
  chassis.drive_to_point(1.65, -19.73);
  chassis.set_swing_exit_conditions(1, 10, 700);

  //wait(1000000, msec);

  
//////////////////////////////'Match Laod'////////////////////////////////////////////

  //IntakeP.set(false);

}

void six_ball(){
  thread cord = thread(odom_test);
//wait(10000000000000000, msec);
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 8;
  chassis.heading_max_voltage = 8;
  chassis.turn_max_voltage = 5;
  
  chassis.swing_max_voltage = 12;

  chassis.drive_settle_time = 50;
  chassis.turn_settle_time = 10;
  chassis.swing_settle_time = 10;

  IntakeP.set(false);
  //IntakeD.set(true);
  
  //wait(500, msec);
  // Left.spin(fwd, 200, rpm);
  // Right.spin(fwd, 200, rpm);
  // chassis.drive_to_point(7.8, 48.0);
  // chassis.drive_to_point(00, 00);
  //wait(10000000000000000, msec);
  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);

  chassis.drive_to_point(0, 8.7);
  //IntakeD.set(false);
  //chassis.drive_max_voltage = 12;
  chassis.drive_to_point(2.7, -30.3);
  chassis.drive_max_voltage = 8;

  
  chassis.turn_to_point(chassis.get_X_position() - (11.9 - chassis.get_X_position()),  chassis.get_Y_position() - (-44.5 - chassis.get_Y_position()));
  chassis.drive_to_point(8.4, -39.1);
  LeftBackWing.set(true);
  chassis.turn_to_angle(292.8);
  LeftBackWing.set(false);
  chassis.turn_to_point(12.4, -45.8);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  chassis.drive_to_point(12.4, -45.8);
  
  

  //wait(10000000000000000, msec);
  chassis.set_drive_exit_conditions(1, 300, 1000);
  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);

  chassis.drive_max_voltage = 12;
  chassis.drive_to_point(50.3, -51.8);

  chassis.set_drive_exit_conditions(1, 300, 700);

  

  //wait(100000000000000000, msec);
  //chassis.turn_to_point(chassis.get_X_position() - (30.2 - chassis.get_X_position()),  chassis.get_Y_position() - (-45.4 - chassis.get_Y_position()));
  chassis.drive_max_voltage = 8;
  chassis.drive_to_point(20.9, -50.8);

  chassis.drive_to_point(50.3, -51.8);
  //wait(100000000000000000, msec);
  chassis.drive_to_point(20.4, -45.8);

  chassis.set_drive_exit_conditions(1.5, 300, 5000);


  chassis.turn_max_voltage = 12;
  chassis.turn_to_point(43.9, -2.6);
  //wait(100000000000000000, msec);

  IntakeP.set(false);
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);

  chassis.turn_max_voltage = 12;
  chassis.turn_settle_time = 1;
  
  //chassis.drive_to_point(39.0, 3.6);
  chassis.drive_to_point(43.9, -2.6);
  //wait(100000000000000000, msec);

  chassis.drive_to_point(40.1, -7.1);
//wait(100000000000000000, msec);
chassis.turn_max_voltage = 7;
  chassis.turn_settle_time = 1;


  
  chassis.turn_to_point(47.7, -22.6);
  //wait(100000000000000000, msec);
  
  //wait(400, msec);
  
  //wait(200, msec);
  chassis.set_drive_exit_conditions(2, 1, 300);
  chassis.drive_max_voltage = 12;
  chassis.drive_to_point(47.7, -22.6);
  Left.spin(fwd, -200, rpm);
  Right.spin(fwd, -200, rpm);
  wait(200, msec);
  //wait(100000000000000000, msec);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  //chassis.drive_to_point(53.4, -13.6);
  chassis.drive_max_voltage = 6;

  //wait(100000000000000000, msec);

  //chassis.right_swing_to_angle(38.7);
  chassis.turn_max_voltage = 7;
  chassis.turn_settle_time = 1;

  chassis.turn_to_point(64.2, -5.0);
  chassis.turn_max_voltage = 5;
  IntakeP.set(false);
  //wait(100000000000000000, msec);

  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);


 //chassis.drive_to_point(59.3, 0.8);
  chassis.drive_to_point(64.2, -5.0);
  //wait(100000000000000000, msec);
 

 chassis.turn_to_point(64, -35.5);
 LeftWing.set(true);
 RightWing.set(true);

 Left.stop();
 Right.stop();
chassis.drive_max_voltage = 12;
Left.spin(fwd, -200, rpm);
  Right.spin(fwd, -200, rpm);
 chassis.drive_to_point(64, -40.5);
 LeftWing.set(false);
 RightWing.set(false);
 chassis.drive_to_point(60.5, -1.5);


  wait(1000000000000, msec);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}


void swing_test(){
thread cord = thread(odom_test);
//wait(10000000000000000, msec);
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 5;
  chassis.turn_max_voltage = 5;
  chassis.swing_max_voltage = 7;

  chassis.drive_settle_time = 10;
  chassis.turn_settle_time = 1;
  chassis.swing_settle_time = 1;

  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)
  IntakeP.set(false);
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);
  //wait(1000000000000, msec);
  LeftWing.set(true);
  wait(200, msec);

  //chassis.turn_to_point(9.86, 47.0);
  chassis.turn_to_point(12.08, 46.29);
  wait(100, msec);
  LeftWing.set(false);
  //wait(1000000000000, msec);
  //chassis.drive_to_point(9.86, 47.0);
  chassis.drive_to_point(12.08, 46.29);

  chassis.drive_to_point(9.62, 41.18);

  chassis.turn_to_point(23.22, 42.94);

  Left.spin(fwd, 200, rpm);
  Right.spin(fwd, 200, rpm);
  //wait(10000000000000000, msec);
  LeftWing.set(true);
  chassis.drive_to_point(34.39, 43.11);
  chassis.drive_to_point(23.22, 42.94);
  LeftWing.set(false);
  //wait(10000000000000000, msec);
  // LeftBackWing.set(true);
  // wait(200,msec);
  chassis.turn_max_voltage = 12;
  chassis.turn_to_point(-7.75, -0.87);

  //wait(10000000000000000, msec);


  chassis.turn_max_voltage = 5;
  chassis.drive_max_voltage = 8;
  chassis.drive_to_point(-3.99, -0.66);

  LeftBackWing.set(false);

  chassis.turn_to_point(chassis.get_X_position() - (-11.82 - chassis.get_X_position()),  chassis.get_Y_position() - (7.96 - chassis.get_Y_position()));
 //wait(10000000000000000, msec);
  chassis.drive_to_point(-16.42, 7.7);

  
  chassis.set_swing_exit_conditions(1, 1, 400);
  chassis.right_swing_to_angle(174.8);
  chassis.drive_to_point(-17.42, 16.27);

  chassis.drive_to_point(-14.85, 3.6);
  //wait(1000000000000000, msec);
  
  chassis.turn_to_point(chassis.get_X_position() - (-9.46 - chassis.get_X_position()),  chassis.get_Y_position() - (-3.98 - chassis.get_Y_position()));
  LeftBackWing.set(true);
  //chassis.turn_to_point(-9.46, -3.98);
  wait(200, msec);
  chassis.drive_to_point(-9.46, -3.98);

  chassis.turn_max_voltage = 5;
  
  //chassis.turn_to_angle(81.62);
  LeftBackWing.set(false);
  chassis.turn_max_voltage = 5;

  chassis.turn_to_point(0.95, -6.74);
  chassis.drive_to_point(0.95, -6.74);
  wait(500, msec);
  chassis.turn_to_point(34.3, -8.185);
  
  
  IntakeP.set(true);
  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);
  chassis.drive_max_voltage = 6;
  //LeftWing.set(true);
  chassis.drive_to_point(37.3, -8.185);
  
  wait(1000000000000000, msec);
  
}

void close_side(){
  thread cord = thread(odom_test);
//wait(10000000000000000, msec);
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 5;
  chassis.turn_max_voltage = 5;
  chassis.swing_max_voltage = 7;

  chassis.drive_settle_time = 10;
  chassis.turn_settle_time = 1;
  chassis.swing_settle_time = 1;

  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)
  IntakeP.set(false);
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);
  //wait(1000000000000, msec);
  LeftWing.set(true);
  wait(200, msec);

  //chassis.turn_to_point(9.86, 47.0);
  chassis.turn_to_point(12.08, 46.29);
  wait(100, msec);
  LeftWing.set(false);
  //wait(1000000000000, msec);
  //chassis.drive_to_point(9.86, 47.0);
  chassis.drive_to_point(12.08, 46.29);

  chassis.drive_to_point(9.62, 41.18);

  chassis.turn_to_point(23.22, 42.94);

  Left.spin(fwd, 200, rpm);
  Right.spin(fwd, 200, rpm);
  //wait(10000000000000000, msec);
  LeftWing.set(true);
  chassis.drive_to_point(34.39, 43.11);
  chassis.drive_to_point(23.22, 42.94);
  LeftWing.set(false);
  //wait(10000000000000000, msec);
  // LeftBackWing.set(true);
  // wait(200,msec);
  chassis.turn_max_voltage = 12;
  chassis.turn_to_point(-7.75, -0.87);

  //wait(10000000000000000, msec);


  chassis.turn_max_voltage = 5;
  chassis.drive_max_voltage = 8;
  chassis.drive_to_point(-3.99, -0.66);

  LeftBackWing.set(false);

  chassis.turn_to_point(chassis.get_X_position() - (-11.82 - chassis.get_X_position()),  chassis.get_Y_position() - (7.96 - chassis.get_Y_position()));
 //wait(10000000000000000, msec);
  chassis.drive_to_point(-16.42, 7.7);

  
  chassis.set_swing_exit_conditions(1, 1, 400);
  chassis.right_swing_to_angle(174.8);
  chassis.drive_to_point(-17.42, 16.27);

  chassis.drive_to_point(-14.85, 3.6);
  //wait(1000000000000000, msec);
  
  chassis.turn_to_point(chassis.get_X_position() - (-9.46 - chassis.get_X_position()),  chassis.get_Y_position() - (-3.98 - chassis.get_Y_position()));
  LeftBackWing.set(true);
  //chassis.turn_to_point(-9.46, -3.98);
  wait(200, msec);
  chassis.drive_to_point(-9.46, -3.98);

  chassis.turn_max_voltage = 5;
  
  //chassis.turn_to_angle(81.62);
  LeftBackWing.set(false);
  chassis.turn_max_voltage = 5;

  chassis.turn_to_point(0.95, -6.74);
  chassis.drive_to_point(0.95, -6.74);
  wait(500, msec);
  chassis.turn_to_point(34.3, -8.185);
  
  
  IntakeP.set(true);
  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);
  //chassis.drive_max_voltage = 6;
  //LeftWing.set(true);
  chassis.drive_to_point(37.3, -8.185);

  chassis.drive_max_voltage = 12;

  chassis.drive_to_point(-9.53, -2.93);
  LeftWing.set(false);

  wait(1000000000000000, msec);
  
}


 

 int wing()
 {
  wait(1000, msec);
  //UpWing.set(true); 
  return 0;
 }
void skills(){
// Start Odom thread
thread cord = thread(odom_test);
//Set Odom Constants
//and Drive Constance
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 7;
  chassis.heading_max_voltage = 2;
  chassis.turn_max_voltage = 2;
  chassis.swing_max_voltage = 2;

//Set settle times
  chassis.drive_settle_time = 0;
  chassis.turn_settle_time = 0;
  chassis.swing_settle_time = 1;

  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)

  ///////////////////////////'First Two Red Balls'/////////////////////////////////
  //set up exit conditions for the first movment to push red balls 
  chassis.set_drive_exit_conditions(4, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  //first pass through point
  chassis.drive_to_point(0.0, -7.4);

  //'PUSH IN GOAL'//
  chassis.set_drive_exit_conditions(1, 10, 1400);
  chassis.drive_to_point(-9.0, -27.98);

  //move away from goal to get ready to line up
  chassis.set_drive_exit_conditions(1, 50, 1400);
  chassis.drive_to_point(-5.12, -23.05);
  chassis.set_drive_exit_conditions(1, 50, 1400);

  //Sets Up the max power for the swing turn
  chassis.swing_max_voltage = 12;
  chassis.turn_max_voltage = 5;
  chassis.heading_max_voltage = 12;

  //swing turn exit conditions
  chassis.set_swing_exit_conditions(0, 10, 1700);
  //swing turn with right side of bot 
  chassis.right_swing_to_angle(291.104);

  //sets up max voltages for the drive
  chassis.heading_max_voltage = 2;
  chassis.drive_max_voltage = 5;
  //lines up to get ready to match load

  //wait(10000000000, msec);
  //chassis.drive_to_point(0.76, -19.29);
  chassis.drive_to_point(-2.11, -19.97);
  chassis.set_swing_exit_conditions(1, 10, 1000);

  //wait(1000000, msec);

  
//////////////////////////////'Match Laod'////////////////////////////////////////////

  IntakeP.set(false);
  RightBackWing.set(true);

  //makes a vareable to count balls
  //int c = 0;

  //runs slapper at 80% speed
  Left.spin(fwd, 480, rpm);
  Right.spin(fwd, 480, rpm);

  //'Just Incase sensor fails'////////////
  //wait(23000, msec);                 //
  // Left.stop(coast);                  //
  // Right.stop(coast);                 //
  ////////////////////////////////////////
  
  //'shoots slapper until 44 balls are shot'//
  // while( c < 40)
  // {
  //   //waits until it see's a ball
  //   waitUntil(Optical.isNearObject() == true);
  //   //waits until it no longer see's a ball
  //   waitUntil(Optical.isNearObject() == false);
  //   //increases ball counter by 1
  //   c = c + 1;
  // }
  wait(23000, msec);
  RightBackWing.set(false);

  // stops the slapper

  Left.stop(coast);
  Right.stop(coast);
  Left.spin(reverse, 480, rpm);
  Right.spin(reverse, 480, rpm);
  //wait(1000, msec);
  /////////////////////////////////////////////


  chassis.drive_max_voltage = 9;

  chassis.set_swing_exit_conditions(5, 1, 700);
  chassis.left_swing_to_angle(345.37);


  chassis.set_drive_exit_conditions(3, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  chassis.drive_to_point(-8.83, 11.1);

  chassis.set_drive_exit_conditions(4, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  //chassis.drive_to_point(-30.95, 33.70);

  chassis.set_drive_exit_conditions(1, 10, 5000);
  chassis.drive_max_voltage = 10;
  chassis.turn_to_point(-65.85, 57.64);


  //chassis.drive_to_point(-10.31, -25.87);

  //GO UNDER BAR
  //thread Wing = thread(wing);
  chassis.set_drive_exit_conditions(1, 10, 3000);
  chassis.drive_to_point(-65.85, 57.64);

  //wait(100000000000, msec);
  chassis.drive_max_voltage = 8;

  chassis.set_drive_exit_conditions(10, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  //UpWing.set(true); 

  chassis.turn_to_point(-84.99, 62.68);
  //chassis.turn_to_point(chassis.get_X_position() - (-84.99 - chassis.get_X_position()),  chassis.get_Y_position() - (62.68 - chassis.get_Y_position()));
  
  chassis.drive_to_point(-84.99, 62.68);


  chassis.set_drive_exit_conditions(1, 10, 1400);
  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 7;

  //chassis.drive_to_point(-10.31, -25.87);

  //UpWing.set(false); 

  //GO PUSH IN RED GOAL
  chassis.drive_to_point(-105.28, 51.07);

  chassis.drive_max_voltage = 8;
  chassis.heading_max_voltage = 5;


  chassis.drive_to_point(-96.20, 61.68);

  //wait(1000000000000, msec);

  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 5;

  chassis.turn_to_point(-109.46, 45.23);
  chassis.drive_to_point(-109.46, 45.23);

   chassis.drive_max_voltage = 8;

  chassis.turn_to_point(chassis.get_X_position() - (-93.50 - chassis.get_X_position()),  chassis.get_Y_position() - (60.15 - chassis.get_Y_position()));
  chassis.drive_to_point(-93.50, 60.15);

  chassis.turn_to_point(-68.89, 22.39);  
  chassis.drive_to_point(-68.89, 22.39);

  chassis.turn_to_point(-113.76, 32.75);  
  //LeftWing.set(true);



//////////////////////////////////////////////////
  chassis.set_drive_exit_conditions(8, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

 // chassis.drive_to_point(-98.50, 20.45);

  

  chassis.set_drive_exit_conditions(1, 30, 5000);
  chassis.drive_max_voltage = 7;
  chassis.heading_max_voltage = 3;

  //////////////////////////////////////////////

  //First push

  chassis.set_drive_exit_conditions(1, 30, 1400);
  chassis.drive_to_point(-107.39, 26.55);
  chassis.set_drive_exit_conditions(1, 30, 5000);
  chassis.turn_max_voltage = 12;
  chassis.turn_to_angle(315);

  chassis.drive_to_point(-77.18, 16.82);

  chassis.turn_to_point(-87.61, 2.65);  
  chassis.drive_to_point(-87.61, 2.65);

  chassis.turn_to_point(-117.05, 29.11); 

  chassis.set_drive_exit_conditions(1, 30, 1400);
  LeftWing.set(true);
  RightWing.set(true); 
  chassis.drive_to_point(-117.05, 29.11);

  chassis.set_drive_exit_conditions(1, 30, 5000);

  LeftWing.set(false);
  RightWing.set(false); 

  chassis.drive_to_point(-94.06, 6.48);

  chassis.turn_to_point(chassis.get_X_position() - (-112.70 - chassis.get_X_position()),  chassis.get_Y_position() - (-16.54 - chassis.get_Y_position()));
  //wait(1000000000000, msec);
  chassis.drive_to_point(-112.70, -16.54);


  chassis.turn_to_point(-111.37, 6.2); 

  chassis.set_drive_exit_conditions(1, 30, 1400);
  LeftWing.set(true);
  RightWing.set(true); 
  //chassis.drive_to_point(-111.37, 6.2);

  chassis.set_drive_exit_conditions(10, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  
  chassis.drive_max_voltage = 7;
  chassis.heading_max_voltage = 4;

  chassis.drive_to_point(-110.48, 15.16);
  chassis.drive_max_voltage = 9;
  chassis.set_drive_exit_conditions(4, 0, 1400);

  

  chassis.drive_to_point(-115.1, 23.21);

  chassis.set_drive_exit_conditions(1, 0, 800);
  chassis.drive_max_voltage = 12;

  chassis.drive_to_point(-123.4, 30.96);
////////////////////////////////////////////////
//last push done time for side
  chassis.drive_max_voltage = 7;
  chassis.set_drive_exit_conditions(1, 0, 1400);
  chassis.drive_to_point(-107.45, 15.81);

  LeftWing.set(false);
  RightWing.set(false); 


  chassis.turn_to_point(-115.52, -22.29); 
  Left.spin(fwd, 200, rpm);
  Right.spin(fwd, 200, rpm);
  
  chassis.drive_to_point(-115.52, -22.29);

  chassis.turn_to_point(-142.84, -1.05); 
  LeftWing.set(true);
  //UpWing.set(true); 
  chassis.drive_to_point(-142.84, -1.05);
  LeftWing.set(false);
  //UpWing.set(false);

  IntakeP.set(true);

  Left.stop(coast);
  Right.stop(coast);

  chassis.turn_to_point(chassis.get_X_position() - (-148.18 - chassis.get_X_position()),  chassis.get_Y_position() - (-24.29 - chassis.get_Y_position()));
  //wait(1000000000000, msec);
  chassis.drive_to_point(-148.18, -24.29);


  chassis.turn_to_point(-154.54, -19.78); 

  //UpWing.set(true); 
  //LeftWing.set(true);
 
  
  chassis.drive_to_point(-154.54, -19.78);

  chassis.turn_to_point(-157.46, 6.11);

  chassis.set_drive_exit_conditions(12, 0, 1400);
  chassis.set_turn_exit_conditions(4, 0, 1400);

  
  chassis.drive_max_voltage = 7;
  chassis.heading_max_voltage = 4;
  chassis.drive_to_point(-157.46, 6.11);

  chassis.set_drive_exit_conditions(1, 0, 1400);
  chassis.drive_max_voltage = 9;
  
  chassis.drive_to_point(-147.94, 17.15);

  //UpWing.set(false); 
  LeftWing.set(false); 

  //wait(100000000000000000, msec);
  chassis.turn_to_point(chassis.get_X_position() - (-156.4 - chassis.get_X_position()),  chassis.get_Y_position() - (8.2 - chassis.get_Y_position()));
  chassis.drive_to_point(-156.4, 8.2);

  chassis.turn_to_point(-147.0, 22.0);
  chassis.drive_to_point(-147.0, 22.0);

  chassis.turn_to_point(chassis.get_X_position() - (-155.7 - chassis.get_X_position()),  chassis.get_Y_position() - (11.4 - chassis.get_Y_position()));
  chassis.drive_to_point(-155.7, 11.4);

  chassis.turn_to_point(-147.0, 22.0);
  chassis.drive_to_point(-147.0, 22.0);

  //chassis.turn_to_point(chassis.get_X_position() - (-156.4 - chassis.get_X_position()),  chassis.get_Y_position() - (8.2 - chassis.get_Y_position()));
  chassis.drive_to_point(-156.4, 8.2);
  wait(100000000000000000, msec);
  chassis.drive_to_point(-150.0, 4.6);

  chassis.turn_to_point(-145.7, -17.2);
  chassis.drive_to_point(-145.7, -17.2);

  IntakeP.set(false);
  //BarHang.set(true);

  chassis.drive_max_voltage = 9;

  chassis.set_drive_exit_conditions(1, 0, 2000);
  chassis.turn_to_point(-103.8, -58.2);
  chassis.drive_to_point(-103.8, -58.2);



  wait(1000000000000, msec);



}

void far_side(){

  thread cord = thread(odom_test);
//wait(10000000000000000, msec);
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 8;
  chassis.turn_max_voltage = 7;
  
  chassis.swing_max_voltage = 7;

  chassis.drive_settle_time = 50;
  chassis.turn_settle_time = 1;
  chassis.swing_settle_time = 10;


  IntakeP.set(false);
  RightWing.set(true);
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);

  wait(200, msec);

  //drive_to_point(X_position, Y_position, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout)
  chassis.drive_to_point(0, 13.3);
  RightWing.set(false);

  chassis.turn_to_angle(324.7);
  IntakeP.set(false);
  //wait(1000000000000, msec);
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);

  chassis.drive_to_point(-24.4, 46.6);
  
  ///////////////////////////////
  //wait(1000000000000, msec);

  chassis.drive_to_point(-22.3, 41.5);
  LeftWing.set(true);
  chassis.turn_to_point(8.6, 45.9);
  
  //IntakeP.set(true);
  LeftWing.set(true);
  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);
  chassis.drive_max_voltage = 12;
  chassis.drive_to_point(11.6, 43.7);

  chassis.drive_to_point(-2.3, 46.3);
  chassis.drive_max_voltage = 12;
  LeftWing.set(false);

  
  // chassis.drive_to_point(3.6, 57.0);
  chassis.turn_to_point(-25.9, 28.7);
  //wait(1000000000000000, msec);
  IntakeP.set(false);
  
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);
  chassis.drive_to_point(-22.7, 30.8);

  wait(200, msec);



  chassis.turn_to_point(5.4, 8.0);
  //IntakeP.set(true);
  
  chassis.drive_max_voltage = 8;
  //wait(10000000000000000, msec);
  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);
  chassis.drive_to_point(5.4, 8.0);
  // Left.spin(fwd, -600, rpm);
  // Right.spin(fwd, -600, rpm);

  //wait(300, msec);
  
  chassis.drive_max_voltage = 12;

  chassis.turn_to_point(4.9, -7.8);
  //wait(1000000000000000, msec);
  chassis.drive_to_point(4.4, -3.5);
  //wait(1000000000000000, msec);

  chassis.turn_to_point(-27.4, -9.7);
  wait(200, msec);
  IntakeP.set(false);
  chassis.drive_max_voltage = 8;
  
  
  Left.spin(fwd, 600, rpm);
  Right.spin(fwd, 600, rpm);
  //wait(1000000000000000, msec);
  chassis.drive_to_point(-30.4, -8.7);
  chassis.drive_max_voltage = 12;
  //wait(500, msec);
  //wait(1000000000000000, msec);

  chassis.drive_to_point(6.8, -6.9);


  chassis.turn_to_point(chassis.get_X_position() - (21.3 - chassis.get_X_position()),  chassis.get_Y_position() - (3.2 - chassis.get_Y_position()));
  //UpWing.set(true);
  chassis.drive_max_voltage = 8;
  LeftBackWing.set(true);
  chassis.drive_to_point(21.3, 3.2);
  LeftBackWing.set(false);
  chassis.turn_max_voltage = 12;
  chassis.turn_to_point(chassis.get_X_position() - (25.2 - chassis.get_X_position()),  chassis.get_Y_position() - (27.8 - chassis.get_Y_position()));
  chassis.turn_max_voltage = 7;
  chassis.turn_to_point(chassis.get_X_position() - (23.4 - chassis.get_X_position()),  chassis.get_Y_position() - (5.9 - chassis.get_Y_position()));
  RightBackWing.set(true);
  // chassis.turn_to_point(26.0, 20.3);
  //wait(1000000000000000, msec);
  chassis.set_drive_exit_conditions(1, 0, 400);
  chassis.drive_max_voltage = 12;
  chassis.heading_max_voltage = 5;
  chassis.drive_to_point(23.55, 7.58);

  chassis.set_drive_exit_conditions(1, 0, 700);
  chassis.drive_max_voltage = 12;

  

  chassis.drive_to_point(28.8, 30.28);
  //UpWing.set(false);

  // chassis.turn_to_point(chassis.get_X_position() - (28.7 - chassis.get_X_position()),  chassis.get_Y_position() - (21.2 - chassis.get_Y_position()));
  // chassis.drive_to_point(28.7, 21.2);

  //wait(1000000000000000, msec);
 
  RightBackWing.set(false);
  chassis.drive_to_point(23.61, 14.97);

  //chassis.turn_to_angle(90);
  chassis.turn_max_voltage = 12;
  chassis.turn_to_point(17.99, 38.08);

  Left.spin(fwd, -600, rpm);
  Right.spin(fwd, -600, rpm);
  //wait(100000000000000, msec);
  chassis.drive_to_point(28.8, 38.08);

  chassis.drive_to_point(23.61, 14.97);
  // Fright.spin(fwd, 600, rpm);
  // Fleft.spin(fwd, 600, rpm);
  // Bright.spin(fwd, 600, rpm);
  // Bleft.spin(fwd, 600, rpm);
  // Sright.spin(fwd, 600, rpm);
  // Sleft.spin(fwd, 600, rpm);

  wait(100000000000000, msec);
  
}