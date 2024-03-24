// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#ifndef OPERATOR_CONTANTS_H
#define OPERATOR_CONTANTS_H

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;
inline constexpr int kDriverManipulatorPort = 1;

} 

#endif // OPERATOR_CONTANTS_H

#ifndef CONTROLLER_INPUTS_H
#define CONTROLLER_INPUTS_H

struct ControllerInputs {
    // Driving
    float driver_LeftTriggerAxis;    // Backwards Throttle - Left Trigger
    float driver_RightTriggerAxis;   // Forwards Throttle - Right Trigger
    double driver_leftX;             // Turning - Left Joystick

    // Manipulation
    float mani_LeftTriggerAxis;      // Intake  - Left Trigger
    float mani_RightTriggerAxis;     // Speaker Outtake - Right Trigger
    bool mani_LeftBumper;            // Eject - Left Bumper
    bool mani_RightBumper;           // Amplifier Outtake - Right Bumper
    double mani_leftX;               // Left Lifter - Left Joystick
    double mani_rightX;              // Right Lifter - Right Joystick
};

#endif // CONTROLLER_INPUTS_H
