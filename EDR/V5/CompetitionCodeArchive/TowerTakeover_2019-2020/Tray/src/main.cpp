/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <algorithm>
#include <cmath>


using namespace vex;

vex::motor LM1 = vex::motor(vex::PORT20,false);
vex::motor LM2 = vex::motor(vex::PORT10,false);
vex::motor RM1 = vex::motor(vex::PORT11,true);
vex::motor RM2 = vex::motor(vex::PORT1,true);
 
vex::controller Controller2 = vex::controller();
 
vex::motor LeftArm = vex::motor(vex::PORT19,false);
vex::motor RightArm = vex::motor(vex::PORT12,true);
 
vex::motor LeftSpin = vex::motor(vex::PORT9,true);
vex::motor RightSpin = vex::motor(vex::PORT2,false);
 
vex::motor Pivot = vex::motor(vex::PORT15,true);

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  int slow=100;
  LM2.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
LM1.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
RM2.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
RM1.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
vex::task::sleep( 2000 );
LM1.stop();
LM2.stop();
RM1.stop();
RM2.stop();
LM2.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
LM1.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
RM2.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
RM1.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
vex::task::sleep( 1000 );
LM1.stop();
LM2.stop();
RM1.stop();
RM2.stop();
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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

     // mecanum drive
 LM2.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
 LM1.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
 RM2.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
 RM1.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
 int speed = 100;
 int slow=75;

 //spin control
 if(Controller2.ButtonL2.pressing())
  {
  LeftSpin.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RightSpin.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  }
else if(Controller2.ButtonL1.pressing())
  {
  LeftSpin.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RightSpin.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  }
else
  {
  LeftSpin.stop(vex::brakeType::hold);
  RightSpin.stop(vex::brakeType::hold);
  }
//arm control
 if(Controller2.ButtonDown.pressing())
  {
  LeftArm.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
  RightArm.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
  }
else if(Controller2.ButtonUp.pressing())
  {
  LeftArm.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
  RightArm.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
  }
else
  {
  LeftArm.stop(vex::brakeType::hold);
  RightArm.stop(vex::brakeType::hold);
  }

//pivot
 if(Controller2.ButtonR2.pressing())
  {
  Pivot.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
  }
else if(Controller2.ButtonR1.pressing())
  {
  Pivot.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
  }
else
  {
  Pivot.stop(vex::brakeType::hold);
  }

     //Sleep the task for a short amount of time to prevent wasted resources.
   vex::task::sleep(20);
  }
  vexcodeInit();
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

}
