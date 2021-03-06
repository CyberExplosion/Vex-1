/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\brandon                                          */
/*    Created:      Sun Aug 11 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
vex::motor motor1(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor motor2(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor motor3(vex::PORT3, vex::gearSetting::ratio18_1, true);
vex::motor motor4(vex::PORT4, vex::gearSetting::ratio18_1, true);
vex::motor motor5(vex::PORT5, vex::gearSetting::ratio18_1, true);
vex::motor motor6(vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor motor7(vex::PORT7, vex::gearSetting::ratio18_1, true);
vex::motor motor8(vex::PORT8, vex::gearSetting::ratio18_1, true);
vex::motor motor9(vex::PORT9, vex::gearSetting::ratio18_1, true);
vex::motor motor10(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor motor11(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor motor12(vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor motor13(vex::PORT13, vex::gearSetting::ratio18_1, true);
vex::motor motor14(vex::PORT14, vex::gearSetting::ratio18_1, true);
vex::motor motor15(vex::PORT15, vex::gearSetting::ratio18_1, true);
vex::motor motor16(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor motor17(vex::PORT17, vex::gearSetting::ratio18_1, true);
vex::motor motor18(vex::PORT18, vex::gearSetting::ratio18_1, true);
vex::motor motor19(vex::PORT19, vex::gearSetting::ratio18_1, true);
vex::motor motor20(vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

void drive();
void sensorHeader();
void sensorWriter();
void Batterydata();
void competitionDate();
void controller1Data();
void controller2Data();
void motor1Data();
void motor2Data();
void motor3Data();
void motor4Data();
void motor5Data();
void motor6Data();
void motor7Data();
void motor8Data();
void motor9Data();
void motor10Data();
void motor11Data();
void motor12Data();
void motor13Data();
void motor14Data();
void motor15Data();
void motor16Data();
void motor17Data();
void motor18Data();
void motor19Data();
void motor20Data();
void BatteryHeader();
void competitionHeader();
void controller1Header();
void controller2Header();
void motor1Header();
void motor2Header();
void motor3Header();
void motor4Header();
void motor5Header();
void motor6Header();
void motor7Header();
void motor8Header();
void motor9Header();
void motor10Header();
void motor11Header();
void motor12Header();
void motor13Header();
void motor14Header();
void motor15Header();
void motor16Header();
void motor17Header();
void motor18Header();
void motor19Header();
void motor20Header();
void BatteryHeader2();
void competitionHeader2();
void controllerHeader2();
void motorHeader2();
void stopmotor();

vex::competition Competition;
std::ofstream ofs;

int main() {
  if (Brain.SDcard.isInserted()) {
    // create a file with long filename
    ofs.open("Run.csv", std::ofstream::out);
    sensorHeader();
    while (true) {

      sensorWriter();

      vex::task::sleep(10);

      drive();

      if (/*con.ButtonB.pressing() == 1 && con.ButtonX.pressing() == 1 &&
          con.ButtonUp.pressing() == 1 && con.ButtonDown.pressing() == 1 &&*/
          con.ButtonL1.pressing() == 1 && con.ButtonL2.pressing() == 1 &&
          con.ButtonR2.pressing() == 1 && con.ButtonR1.pressing() == 1) {
        break;
      }
    }

    ofs.close();
    Brain.Screen.printAt(10, 40, "done");
    stopmotor();
  } else {
    Brain.Screen.printAt(10, 40, "No SD Card");
  }
}

void drive() {
  motor1.setVelocity(100, vex::velocityUnits::pct);
  motor2.setVelocity(100, vex::velocityUnits::pct);
  motor3.setVelocity(100, vex::velocityUnits::pct);
  motor4.setVelocity(100, vex::velocityUnits::pct);
  motor5.setVelocity(100, vex::velocityUnits::pct);
  motor6.setVelocity(100, vex::velocityUnits::pct);
  motor7.setVelocity(100, vex::velocityUnits::pct);
  motor8.setVelocity(100, vex::velocityUnits::pct);
  motor9.setVelocity(100, vex::velocityUnits::pct);
  motor10.setVelocity(100, vex::velocityUnits::pct);
  motor11.setVelocity(100, vex::velocityUnits::pct);
  motor12.setVelocity(100, vex::velocityUnits::pct);
  motor13.setVelocity(100, vex::velocityUnits::pct);
  motor14.setVelocity(100, vex::velocityUnits::pct);
  motor15.setVelocity(100, vex::velocityUnits::pct);
  motor16.setVelocity(100, vex::velocityUnits::pct);
  motor17.setVelocity(100, vex::velocityUnits::pct);
  motor18.setVelocity(100, vex::velocityUnits::pct);
  motor19.setVelocity(100, vex::velocityUnits::pct);
  motor20.setVelocity(100, vex::velocityUnits::pct);

  motor1.spin(vex::directionType::fwd);
  motor2.spin(vex::directionType::fwd);
  motor3.spin(vex::directionType::fwd);
  motor4.spin(vex::directionType::fwd);
  motor5.spin(vex::directionType::fwd);
  motor6.spin(vex::directionType::fwd);
  motor7.spin(vex::directionType::fwd);
  motor8.spin(vex::directionType::fwd);
  motor9.spin(vex::directionType::fwd);
  motor10.spin(vex::directionType::fwd);
  motor11.spin(vex::directionType::fwd);
  motor12.spin(vex::directionType::fwd);
  motor13.spin(vex::directionType::fwd);
  motor14.spin(vex::directionType::fwd);
  motor15.spin(vex::directionType::fwd);
  motor16.spin(vex::directionType::fwd);
  motor17.spin(vex::directionType::fwd);
  motor18.spin(vex::directionType::fwd);
  motor19.spin(vex::directionType::fwd);
  motor20.spin(vex::directionType::fwd);
}
void sensorHeader() {
  ofs << "time (msec),";
  BatteryHeader();
  //controller1Header();
  motor1Header();
  motor2Header();
  motor3Header();
  motor4Header();
  motor5Header();
  motor6Header();
  motor7Header();
  motor8Header();
  motor9Header();
  motor10Header();
  motor11Header();
  motor12Header();
  motor13Header();
  motor14Header();
  motor15Header();
  motor16Header();
  motor17Header();
  motor18Header();
  motor19Header();
  motor20Header();
  ofs << "\n";
  ofs << "senors,";
  BatteryHeader2();
 // controllerHeader2();
  for (int n = 20; n > 0; n--) {
    motorHeader2();
  }
  ofs << "\n";
}

void sensorWriter() {

  ofs << Brain.timer(vex::timeUnits::msec) << ",";

  Batterydata();
  //competitionDate();
  //controller1Data();
  motor1Data();
  motor2Data();
  motor3Data();
  motor4Data();
  motor5Data();
  motor6Data();
  motor7Data();
  motor8Data();
  motor9Data();
  motor10Data();
  motor11Data();
  motor12Data();
  motor13Data();
  motor14Data();
  motor15Data();
  motor16Data();
  motor17Data();
  motor18Data();
  motor19Data();
  motor20Data();

  ofs << "\n";
}

void Batterydata() {
  ofs << Brain.Battery.capacity(vex::percentUnits::pct) << ","
      << Brain.Battery.temperature(vex::temperatureUnits::fahrenheit) << ",";
}

void competitionDate() {
  ofs << Competition.isAutonomous() << "," << Competition.isDriverControl()
      << Competition.isCompetitionSwitch() << ","
      << Competition.isFieldControl() << Competition.isEnabled() << ",";
}

void controller1Data() {
  ofs << con.Axis1.position() << "," << con.Axis1.value() << ","
      << con.Axis2.position() << "," << con.Axis2.value() << ","
      << con.Axis3.position() << "," << con.Axis3.value() << ","
      << con.Axis4.position() << "," << con.Axis4.value() << ","
      << con.ButtonA.pressing() << "," << con.ButtonB.pressing() << ","
      << con.ButtonX.pressing() << "," << con.ButtonY.pressing() << ","
      << con.ButtonUp.pressing() << "," << con.ButtonDown.pressing() << ","
      << con.ButtonLeft.pressing() << "," << con.ButtonRight.pressing() << ","
      << con.ButtonL1.pressing() << "," << con.ButtonL2.pressing() << ","
      << con.ButtonR1.pressing() << "," << con.ButtonR2.pressing();
}

void controller2Data() {
  ofs << "," << con.Axis1.position() << "," << con.Axis1.value() << ","
      << con.Axis2.position() << "," << con.Axis2.value() << ","
      << con.Axis3.position() << "," << con.Axis3.value() << ","
      << con.Axis4.position() << "," << con.Axis4.value() << ","
      << con.ButtonA.pressing() << "," << con.ButtonB.pressing() << ","
      << con.ButtonX.pressing() << "," << con.ButtonY.pressing() << ","
      << con.ButtonUp.pressing() << "," << con.ButtonDown.pressing() << ","
      << con.ButtonLeft.pressing() << "," << con.ButtonRight.pressing() << ","
      << con.ButtonL1.pressing() << "," << con.ButtonL2.pressing() << ","
      << con.ButtonR1.pressing() << "," << con.ButtonR2.pressing();
}
void motor1Data() {
  ofs << "," << motor1.efficiency(vex::percentUnits::pct) << ","
      << motor1.velocity(vex::velocityUnits::rpm) << ","
      << motor1.velocity(vex::velocityUnits::dps) << ","
      << motor1.velocity(vex::velocityUnits::pct) << ","
      << motor1.rotation(vex::rotationUnits::deg) << ","
      << motor1.rotation(vex::rotationUnits::rev) << ","
      << motor1.rotation(vex::rotationUnits::raw) << ","
      << motor1.torque(vex::torqueUnits::Nm) << ","
      << motor1.torque(vex::torqueUnits::InLb) << ","
      << motor1.current(vex::currentUnits::amp) << ","
      << motor1.power(vex::powerUnits::watt) << ","
      << motor1.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor1.temperature(vex::percentUnits::pct);
}

void motor2Data() {
  ofs << "," << motor2.efficiency(vex::percentUnits::pct) << ","
      << motor2.velocity(vex::velocityUnits::rpm) << ","
      << motor2.velocity(vex::velocityUnits::dps) << ","
      << motor2.velocity(vex::velocityUnits::pct) << ","
      << motor2.rotation(vex::rotationUnits::deg) << ","
      << motor2.rotation(vex::rotationUnits::rev) << ","
      << motor2.rotation(vex::rotationUnits::raw) << ","
      << motor2.torque(vex::torqueUnits::Nm) << ","
      << motor2.torque(vex::torqueUnits::InLb) << ","
      << motor2.current(vex::currentUnits::amp) << ","
      << motor2.power(vex::powerUnits::watt) << ","
      << motor2.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor2.temperature(vex::percentUnits::pct);
}

void motor3Data() {
  ofs << "," << motor3.efficiency(vex::percentUnits::pct) << ","
      << motor3.velocity(vex::velocityUnits::rpm) << ","
      << motor3.velocity(vex::velocityUnits::dps) << ","
      << motor3.velocity(vex::velocityUnits::pct) << ","
      << motor3.rotation(vex::rotationUnits::deg) << ","
      << motor3.rotation(vex::rotationUnits::rev) << ","
      << motor3.rotation(vex::rotationUnits::raw) << ","
      << motor3.torque(vex::torqueUnits::Nm) << ","
      << motor3.torque(vex::torqueUnits::InLb) << ","
      << motor3.current(vex::currentUnits::amp) << ","
      << motor3.power(vex::powerUnits::watt) << ","
      << motor3.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor3.temperature(vex::percentUnits::pct);
}

void motor4Data() {
  ofs << "," << motor4.efficiency(vex::percentUnits::pct) << ","
      << motor4.velocity(vex::velocityUnits::rpm) << ","
      << motor4.velocity(vex::velocityUnits::dps) << ","
      << motor4.velocity(vex::velocityUnits::pct) << ","
      << motor4.rotation(vex::rotationUnits::deg) << ","
      << motor4.rotation(vex::rotationUnits::rev) << ","
      << motor4.rotation(vex::rotationUnits::raw) << ","
      << motor4.torque(vex::torqueUnits::Nm) << ","
      << motor4.torque(vex::torqueUnits::InLb) << ","
      << motor4.current(vex::currentUnits::amp) << ","
      << motor4.power(vex::powerUnits::watt) << ","
      << motor4.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor4.temperature(vex::percentUnits::pct);
}

void motor5Data() {
  ofs << "," << motor5.efficiency(vex::percentUnits::pct) << ","
      << motor5.velocity(vex::velocityUnits::rpm) << ","
      << motor5.velocity(vex::velocityUnits::dps) << ","
      << motor5.velocity(vex::velocityUnits::pct) << ","
      << motor5.rotation(vex::rotationUnits::deg) << ","
      << motor5.rotation(vex::rotationUnits::rev) << ","
      << motor5.rotation(vex::rotationUnits::raw) << ","
      << motor5.torque(vex::torqueUnits::Nm) << ","
      << motor5.torque(vex::torqueUnits::InLb) << ","
      << motor5.current(vex::currentUnits::amp) << ","
      << motor5.power(vex::powerUnits::watt) << ","
      << motor5.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor5.temperature(vex::percentUnits::pct);
}

void motor6Data() {
  ofs << "," << motor6.efficiency(vex::percentUnits::pct) << ","
      << motor6.velocity(vex::velocityUnits::rpm) << ","
      << motor6.velocity(vex::velocityUnits::dps) << ","
      << motor6.velocity(vex::velocityUnits::pct) << ","
      << motor6.rotation(vex::rotationUnits::deg) << ","
      << motor6.rotation(vex::rotationUnits::rev) << ","
      << motor6.rotation(vex::rotationUnits::raw) << ","
      << motor6.torque(vex::torqueUnits::Nm) << ","
      << motor6.torque(vex::torqueUnits::InLb) << ","
      << motor6.current(vex::currentUnits::amp) << ","
      << motor6.power(vex::powerUnits::watt) << ","
      << motor6.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor6.temperature(vex::percentUnits::pct);
}

void motor7Data() {
  ofs << "," << motor7.efficiency(vex::percentUnits::pct) << ","
      << motor7.velocity(vex::velocityUnits::rpm) << ","
      << motor7.velocity(vex::velocityUnits::dps) << ","
      << motor7.velocity(vex::velocityUnits::pct) << ","
      << motor7.rotation(vex::rotationUnits::deg) << ","
      << motor7.rotation(vex::rotationUnits::rev) << ","
      << motor7.rotation(vex::rotationUnits::raw) << ","
      << motor7.torque(vex::torqueUnits::Nm) << ","
      << motor7.torque(vex::torqueUnits::InLb) << ","
      << motor7.current(vex::currentUnits::amp) << ","
      << motor7.power(vex::powerUnits::watt) << ","
      << motor7.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor7.temperature(vex::percentUnits::pct);
}

void motor8Data() {
  ofs << "," << motor8.efficiency(vex::percentUnits::pct) << ","
      << motor8.velocity(vex::velocityUnits::rpm) << ","
      << motor8.velocity(vex::velocityUnits::dps) << ","
      << motor8.velocity(vex::velocityUnits::pct) << ","
      << motor8.rotation(vex::rotationUnits::deg) << ","
      << motor8.rotation(vex::rotationUnits::rev) << ","
      << motor8.rotation(vex::rotationUnits::raw) << ","
      << motor8.torque(vex::torqueUnits::Nm) << ","
      << motor8.torque(vex::torqueUnits::InLb) << ","
      << motor8.current(vex::currentUnits::amp) << ","
      << motor8.power(vex::powerUnits::watt) << ","
      << motor8.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor8.temperature(vex::percentUnits::pct);
}

void motor9Data() {
  ofs << "," << motor9.efficiency(vex::percentUnits::pct) << ","
      << motor9.velocity(vex::velocityUnits::rpm) << ","
      << motor9.velocity(vex::velocityUnits::dps) << ","
      << motor9.velocity(vex::velocityUnits::pct) << ","
      << motor9.rotation(vex::rotationUnits::deg) << ","
      << motor9.rotation(vex::rotationUnits::rev) << ","
      << motor9.rotation(vex::rotationUnits::raw) << ","
      << motor9.torque(vex::torqueUnits::Nm) << ","
      << motor9.torque(vex::torqueUnits::InLb) << ","
      << motor9.current(vex::currentUnits::amp) << ","
      << motor9.power(vex::powerUnits::watt) << ","
      << motor9.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor9.temperature(vex::percentUnits::pct);
}

void motor10Data() {
  ofs << "," << motor10.efficiency(vex::percentUnits::pct) << ","
      << motor10.velocity(vex::velocityUnits::rpm) << ","
      << motor10.velocity(vex::velocityUnits::dps) << ","
      << motor10.velocity(vex::velocityUnits::pct) << ","
      << motor10.rotation(vex::rotationUnits::deg) << ","
      << motor10.rotation(vex::rotationUnits::rev) << ","
      << motor10.rotation(vex::rotationUnits::raw) << ","
      << motor10.torque(vex::torqueUnits::Nm) << ","
      << motor10.torque(vex::torqueUnits::InLb) << ","
      << motor10.current(vex::currentUnits::amp) << ","
      << motor10.power(vex::powerUnits::watt) << ","
      << motor10.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor10.temperature(vex::percentUnits::pct);
}

void motor11Data() {
  ofs << "," << motor11.efficiency(vex::percentUnits::pct) << ","
      << motor11.velocity(vex::velocityUnits::rpm) << ","
      << motor11.velocity(vex::velocityUnits::dps) << ","
      << motor11.velocity(vex::velocityUnits::pct) << ","
      << motor11.rotation(vex::rotationUnits::deg) << ","
      << motor11.rotation(vex::rotationUnits::rev) << ","
      << motor11.rotation(vex::rotationUnits::raw) << ","
      << motor11.torque(vex::torqueUnits::Nm) << ","
      << motor11.torque(vex::torqueUnits::InLb) << ","
      << motor11.current(vex::currentUnits::amp) << ","
      << motor11.power(vex::powerUnits::watt) << ","
      << motor11.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor11.temperature(vex::percentUnits::pct);
}

void motor12Data() {
  ofs << "," << motor12.efficiency(vex::percentUnits::pct) << ","
      << motor12.velocity(vex::velocityUnits::rpm) << ","
      << motor12.velocity(vex::velocityUnits::dps) << ","
      << motor12.velocity(vex::velocityUnits::pct) << ","
      << motor12.rotation(vex::rotationUnits::deg) << ","
      << motor12.rotation(vex::rotationUnits::rev) << ","
      << motor12.rotation(vex::rotationUnits::raw) << ","
      << motor12.torque(vex::torqueUnits::Nm) << ","
      << motor12.torque(vex::torqueUnits::InLb) << ","
      << motor12.current(vex::currentUnits::amp) << ","
      << motor12.power(vex::powerUnits::watt) << ","
      << motor12.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor12.temperature(vex::percentUnits::pct);
}

void motor13Data() {
  ofs << "," << motor13.efficiency(vex::percentUnits::pct) << ","
      << motor13.velocity(vex::velocityUnits::rpm) << ","
      << motor13.velocity(vex::velocityUnits::dps) << ","
      << motor13.velocity(vex::velocityUnits::pct) << ","
      << motor13.rotation(vex::rotationUnits::deg) << ","
      << motor13.rotation(vex::rotationUnits::rev) << ","
      << motor13.rotation(vex::rotationUnits::raw) << ","
      << motor13.torque(vex::torqueUnits::Nm) << ","
      << motor13.torque(vex::torqueUnits::InLb) << ","
      << motor13.current(vex::currentUnits::amp) << ","
      << motor13.power(vex::powerUnits::watt) << ","
      << motor13.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor13.temperature(vex::percentUnits::pct);
}

void motor14Data() {
  ofs << "," << motor14.efficiency(vex::percentUnits::pct) << ","
      << motor14.velocity(vex::velocityUnits::rpm) << ","
      << motor14.velocity(vex::velocityUnits::dps) << ","
      << motor14.velocity(vex::velocityUnits::pct) << ","
      << motor14.rotation(vex::rotationUnits::deg) << ","
      << motor14.rotation(vex::rotationUnits::rev) << ","
      << motor14.rotation(vex::rotationUnits::raw) << ","
      << motor14.torque(vex::torqueUnits::Nm) << ","
      << motor14.torque(vex::torqueUnits::InLb) << ","
      << motor14.current(vex::currentUnits::amp) << ","
      << motor14.power(vex::powerUnits::watt) << ","
      << motor14.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor14.temperature(vex::percentUnits::pct);
}

void motor15Data() {
  ofs << "," << motor15.efficiency(vex::percentUnits::pct) << ","
      << motor15.velocity(vex::velocityUnits::rpm) << ","
      << motor15.velocity(vex::velocityUnits::dps) << ","
      << motor15.velocity(vex::velocityUnits::pct) << ","
      << motor15.rotation(vex::rotationUnits::deg) << ","
      << motor15.rotation(vex::rotationUnits::rev) << ","
      << motor15.rotation(vex::rotationUnits::raw) << ","
      << motor15.torque(vex::torqueUnits::Nm) << ","
      << motor15.torque(vex::torqueUnits::InLb) << ","
      << motor15.current(vex::currentUnits::amp) << ","
      << motor15.power(vex::powerUnits::watt) << ","
      << motor15.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor15.temperature(vex::percentUnits::pct);
}

void motor16Data() {
  ofs << "," << motor16.efficiency(vex::percentUnits::pct) << ","
      << motor16.velocity(vex::velocityUnits::rpm) << ","
      << motor16.velocity(vex::velocityUnits::dps) << ","
      << motor16.velocity(vex::velocityUnits::pct) << ","
      << motor16.rotation(vex::rotationUnits::deg) << ","
      << motor16.rotation(vex::rotationUnits::rev) << ","
      << motor16.rotation(vex::rotationUnits::raw) << ","
      << motor16.torque(vex::torqueUnits::Nm) << ","
      << motor16.torque(vex::torqueUnits::InLb) << ","
      << motor16.current(vex::currentUnits::amp) << ","
      << motor16.power(vex::powerUnits::watt) << ","
      << motor16.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor16.temperature(vex::percentUnits::pct);
}

void motor17Data() {
  ofs << "," << motor17.efficiency(vex::percentUnits::pct) << ","
      << motor17.velocity(vex::velocityUnits::rpm) << ","
      << motor17.velocity(vex::velocityUnits::dps) << ","
      << motor17.velocity(vex::velocityUnits::pct) << ","
      << motor17.rotation(vex::rotationUnits::deg) << ","
      << motor17.rotation(vex::rotationUnits::rev) << ","
      << motor17.rotation(vex::rotationUnits::raw) << ","
      << motor17.torque(vex::torqueUnits::Nm) << ","
      << motor17.torque(vex::torqueUnits::InLb) << ","
      << motor17.current(vex::currentUnits::amp) << ","
      << motor17.power(vex::powerUnits::watt) << ","
      << motor17.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor17.temperature(vex::percentUnits::pct);
}

void motor18Data() {
  ofs << "," << motor18.efficiency(vex::percentUnits::pct) << ","
      << motor18.velocity(vex::velocityUnits::rpm) << ","
      << motor18.velocity(vex::velocityUnits::dps) << ","
      << motor18.velocity(vex::velocityUnits::pct) << ","
      << motor18.rotation(vex::rotationUnits::deg) << ","
      << motor18.rotation(vex::rotationUnits::rev) << ","
      << motor18.rotation(vex::rotationUnits::raw) << ","
      << motor18.torque(vex::torqueUnits::Nm) << ","
      << motor18.torque(vex::torqueUnits::InLb) << ","
      << motor18.current(vex::currentUnits::amp) << ","
      << motor18.power(vex::powerUnits::watt) << ","
      << motor18.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor18.temperature(vex::percentUnits::pct);
}

void motor19Data() {
  ofs << "," << motor19.efficiency(vex::percentUnits::pct) << ","
      << motor19.velocity(vex::velocityUnits::rpm) << ","
      << motor19.velocity(vex::velocityUnits::dps) << ","
      << motor19.velocity(vex::velocityUnits::pct) << ","
      << motor19.rotation(vex::rotationUnits::deg) << ","
      << motor19.rotation(vex::rotationUnits::rev) << ","
      << motor19.rotation(vex::rotationUnits::raw) << ","
      << motor19.torque(vex::torqueUnits::Nm) << ","
      << motor19.torque(vex::torqueUnits::InLb) << ","
      << motor19.current(vex::currentUnits::amp) << ","
      << motor19.power(vex::powerUnits::watt) << ","
      << motor19.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor19.temperature(vex::percentUnits::pct);
}

void motor20Data() {
  ofs << "," << motor20.efficiency(vex::percentUnits::pct) << ","
      << motor20.velocity(vex::velocityUnits::rpm) << ","
      << motor20.velocity(vex::velocityUnits::dps) << ","
      << motor20.velocity(vex::velocityUnits::pct) << ","
      << motor20.rotation(vex::rotationUnits::deg) << ","
      << motor20.rotation(vex::rotationUnits::rev) << ","
      << motor20.rotation(vex::rotationUnits::raw) << ","
      << motor20.torque(vex::torqueUnits::Nm) << ","
      << motor20.torque(vex::torqueUnits::InLb) << ","
      << motor20.current(vex::currentUnits::amp) << ","
      << motor20.power(vex::powerUnits::watt) << ","
      << motor20.temperature(vex::temperatureUnits::fahrenheit) << ","
      << motor20.temperature(vex::percentUnits::pct);
}

void BatteryHeader2() { ofs << "capacity,temperature,"; }

void competitionHeader2() {
  ofs << "isAutonomous,isDriverControl,isCompetitionSwitch,isFieldControl,"
         "isEnabled,";
}

void controllerHeader2() {
  ofs << "Axis1 (position),Axis1 (value),Axis2 "
         "(position),Axis2 (value),Axis3 (position),Axis3 (value),Axis4 "
         "(position),Axis4 "
         "(value),ButtonA,ButtonB,ButtonX,ButtonY,ButtonUp,ButtonDown,"
         "ButtonLeft,ButtonRight,ButtonL1,ButtonL2,ButtonR1,ButtonR2,";
}

void motorHeader2() {
  ofs << "efficiency "
         "(percent),velocity (rpm),velocity (degrees per second),velocity "
         "(percent),rotation (degrees),rotation (rev),rotation (raw),torque "
         "(Nm),torque (InLb),current (amp),power (watt),temperature "
         "(fahrenheit),temperature (percent),";
}

void BatteryHeader() { ofs << "Battery,,"; }
void competitionHeader() { ofs << "Competition,,,,,"; }
void controller1Header() { ofs << "Controller1,,,,,,,,,,,,,,,,,,,,"; }
void controller2Header() { ofs << "Controller2,,,,,,,,,,,,,,,,,,,,"; }
void motor1Header() { ofs << "Motor1,,,,,,,,,,,,,"; }
void motor2Header() { ofs << "Motor2,,,,,,,,,,,,,"; }
void motor3Header() { ofs << "Motor3,,,,,,,,,,,,,"; }
void motor4Header() { ofs << "Motor4,,,,,,,,,,,,,"; }
void motor5Header() { ofs << "Motor5,,,,,,,,,,,,,"; }
void motor6Header() { ofs << "Motor6,,,,,,,,,,,,,"; }
void motor7Header() { ofs << "Motor7,,,,,,,,,,,,,"; }
void motor8Header() { ofs << "Motor8,,,,,,,,,,,,,"; }
void motor9Header() { ofs << "Motor9,,,,,,,,,,,,,"; }
void motor10Header() { ofs << "Motor10,,,,,,,,,,,,,"; }
void motor11Header() { ofs << "Motor11,,,,,,,,,,,,,"; }
void motor12Header() { ofs << "Motor12,,,,,,,,,,,,,"; }
void motor13Header() { ofs << "Motor13,,,,,,,,,,,,,"; }
void motor14Header() { ofs << "Motor14,,,,,,,,,,,,,"; }
void motor15Header() { ofs << "Motor15,,,,,,,,,,,,,"; }
void motor16Header() { ofs << "Motor16,,,,,,,,,,,,,"; }
void motor17Header() { ofs << "Motor17,,,,,,,,,,,,,"; }
void motor18Header() { ofs << "Motor18,,,,,,,,,,,,,"; }
void motor19Header() { ofs << "Motor19,,,,,,,,,,,,,"; }
void motor20Header() { ofs << "Motor20,,,,,,,,,,,,,"; }

void stopmotor() {
  motor1.stop();
  motor2.stop();
  motor3.stop();
  motor4.stop();
  motor5.stop();
  motor6.stop();
  motor7.stop();
  motor8.stop();
  motor9.stop();
  motor10.stop();
  motor11.stop();
  motor12.stop();
  motor13.stop();
  motor14.stop();
  motor15.stop();
  motor16.stop();
  motor17.stop();
  motor18.stop();
  motor19.stop();
  motor20.stop();
}