// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Drivetrain.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  /**
   * Use this method to define bindings between conditions and commands. These
   * are useful for automating robot behaviors based on button and sensor input.
   *
   * <p>Should be called during Robot::RobotInit().
   *
   * <p>Event binding methods are available on the frc2::Trigger class.
   */
  void ConfigureBindings();

  void UpdateController();
  
 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  frc2::CommandXboxController m_maniController{
      OperatorConstants::kDriverManipulatorPort};

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  // This is the DriveTrain subsystem object
  DriveTrain m_drivetrain;
};
