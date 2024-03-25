#pragma once

#include <functional>

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

class TankDrive : public frc2::CommandHelper<frc2::Command, TankDrive> {
    public:
        TankDrive(DriveTrain* drivetrain, std::function<double()> forward, std::function<double()> rotation);
        ~TankDrive();
        void Execute() override;

    private:
        // This is a refrence of the DriveTrain subsystem object
        DriveTrain* m_drivetrain;
        std::function<double()> m_forward;
        std::function<double()> m_rotation;
};