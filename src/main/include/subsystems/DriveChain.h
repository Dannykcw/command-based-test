// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef DRIVESYSTEM_H
#define DRIVESYSTEM_H

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/drive/DifferentialDrive.h>

class DriveChain : public frc2::SubsystemBase
{
public:
  DriveChain();
  ~DriveChain();

  /**
   * Example command factory method.
   */
  frc2::CommandPtr DrivechainMethodCommand();

  void Drive(double Y, double X, double Z);

  void Stop();

  /**
   * An example method querying a boolean state of the subsystem (for example, a
   * digital sensor).
   *
   * @return value of some boolean subsystem state, such as a digital sensor.
   */
  bool ExampleCondition();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax *leftLead;      // Front left, leader
  rev::CANSparkMax *rightLead;     // Front right, leader
  rev::CANSparkMax *leftFollower;  // Back left, follower
  rev::CANSparkMax *rightFollower; // Back right, follower

  frc::DifferentialDrive *driveTrain;

  double kMaxOutput = .4, kMinOutput = -.4;

  // Constants for ports and unique id
  const int LEFT_LEAD_ID = 1;
  const int LEFT_FOLLOWER_ID = 2;
  const int RIGHT_LEAD_ID = 3;
  const int RIGHT_FOLLOWER_ID = 4;

  const float SMOOTH_TIME = 0.4;
	const float SAFETY_TIMEOUT = 2.0;

  const float DRIVE_REGULAR = 0.7;
  const float DRIVE_SLOW = 0.4;
  const float DRIVE_RAMP_TIME = 5.0;
};

#endif // DRIVESYSTEM_H