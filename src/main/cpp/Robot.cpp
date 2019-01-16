


#include <iostream>

#include <smartdashboard/SmartDashboard.h>
#include <iostream>
#include <string>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <wpilib.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "ctre/Phoenix.h"
using namespace std;
class Robot : public frc::IterativeRobot {
private:
	TalonSRX *left1;
	TalonSRX *left2;
	TalonSRX *right1;
	TalonSRX *right2;
	TalonSRX *mid;
	TalonSRX *rope;
	frc::RobotDrive *drive;
	frc::Joystick *controller;
public:
	void RobotInit() {
		left1 = new TalonSRX(2);
		left2 = new TalonSRX(8);
		right1 = new TalonSRX(4);
		right2 = new TalonSRX(6);
		mid = new TalonSRX(10);
		rope = new TalonSRX(12);
		controller = new frc::Joystick(0);  }
	void TeleopInit() {}
	void TeleopPeriodic() {
		Drive(
		controller->GetRawAxis(1),
		controller->GetRawAxis(4),
		controller->GetRawAxis(5));  }
	void Drive(float LY, float RX, float RY){
		float leftMotorOutput = 0;
		float rightMotorOutput = 0;
		if(LY > 0.2)  {
			leftMotorOutput = (LY*-1 - (RX*.7/2.5));
			rightMotorOutput = (LY - (RX*.7/2.5));    }
		if(LY < -0.2)  {
			leftMotorOutput = (LY*-1 - (RX*.7/2.5));
			rightMotorOutput = (LY - (RX*.7/2.5));    }
		
		if(LY<0.2){
			if(LY>-0.2){
				if(RX < -0.2){
					leftMotorOutput = -RX;
					rightMotorOutput = -RX; }
				if(RX > 0.2){
				leftMotorOutput = -RX;
				rightMotorOutput = -RX; }}}
		right1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,rightMotorOutput*.8);
		left1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,leftMotorOutput*.8);
		right2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,rightMotorOutput*.8);
		left2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,leftMotorOutput*.8);
		     }
};
int main(){
	frc::StartRobot<Robot>();
}

