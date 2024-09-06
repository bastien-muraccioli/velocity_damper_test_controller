#include "VelocityDamperTestController.h"

VelocityDamperTestController::VelocityDamperTestController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::MCController(rm, dt)
{
  config_.load(config);
  solver().addConstraintSet(contactConstraint);
  solver().addConstraintSet(kinematicsConstraint);
  solver().addTask(postureTask);
  solver().setContacts({{}});

  mc_rtc::log::success("VelocityDamperTestController init done ");
}

bool VelocityDamperTestController::run()
{
  return mc_control::MCController::run();
}

void VelocityDamperTestController::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::MCController::reset(reset_data);
}

CONTROLLER_CONSTRUCTOR("VelocityDamperTestController", VelocityDamperTestController)
