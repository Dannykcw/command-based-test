// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * credit to Team 3229 programing
*/

#include "subsystems/DriveChain.h"

DriveChain::DriveChain() {
  // Implementation of subsystem constructor goes here.

  //Instantiate motor controllers
	leftLead = new rev::CANSparkMax(LEFT_LEAD_ID, rev::CANSparkMax::MotorType::kBrushless);
	rightLead = new rev::CANSparkMax(RIGHT_LEAD_ID, rev::CANSparkMax::MotorType::kBrushless);
	leftFollower = new rev::CANSparkMax(LEFT_FOLLOWER_ID, rev::CANSparkMax::MotorType::kBrushless);
	rightFollower = new rev::CANSparkMax(RIGHT_FOLLOWER_ID, rev::CANSparkMax::MotorType::kBrushless);

  //Restore Facory Defaults 
	leftLead->RestoreFactoryDefaults();
	rightLead->RestoreFactoryDefaults();
	leftFollower->RestoreFactoryDefaults();
	rightFollower->RestoreFactoryDefaults();

  leftFollower->Follow(*leftLead);
	rightFollower->Follow(*rightLead);

  driveTrain = new frc::DifferentialDrive(*leftLead, *rightLead);
}

DriveChain::~DriveChain()
{
  delete leftLead;
	delete rightLead;
	delete leftFollower;
	delete rightFollower;
	delete driveTrain;

}

frc2::CommandPtr DriveChain::DrivechainMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

void DriveChain::Drive(double Y, double X, double Z)
{

	driveTrain->ArcadeDrive(Y, X); 
	
}

void DriveChain::Stop()
{
    driveTrain->StopMotor();
}

bool DriveChain::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void DriveChain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveChain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}