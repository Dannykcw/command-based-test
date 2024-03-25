// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * credit to Team 3229 programing
*/

#include "subsystems/Drivetrain.h"

DriveTrain::DriveTrain() {
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

  m_robotDrive = new frc::DifferentialDrive(*leftLead, *rightLead);
}

DriveTrain::~DriveTrain()
{
  delete leftLead;
	delete rightLead;
	delete leftFollower;
	delete rightFollower;
	delete m_robotDrive;

}

frc2::CommandPtr DriveTrain::DrivetrainMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

void DriveTrain::Drive(double Y, double X)
{

	m_robotDrive->ArcadeDrive(Y, X); 
	
}

void DriveTrain::Stop()
{
    m_robotDrive->StopMotor();
}

bool DriveTrain::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void DriveTrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveTrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}