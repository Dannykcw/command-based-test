#include "commands/TankDrive.h"

#include <utility>

#include "Robot.h"

TankDrive::TankDrive(DriveTrain* drivetrain,

                           std::function<double()> forward,

                           std::function<double()> rotation)

    : m_drivetrain{drivetrain},

      m_forward{std::move(forward)},

      m_rotation{std::move(rotation)} {

  AddRequirements(drivetrain);
};

TankDrive::~TankDrive() {
    delete m_drivetrain;
}

void TankDrive::Execute() {

  m_drivetrain->Drive(m_forward(), m_rotation());

}
