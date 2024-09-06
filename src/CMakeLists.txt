set(controller_SRC VelocityDamperTestController.cpp)

set(controller_HDR VelocityDamperTestController.h)

add_controller(${PROJECT_NAME} ${controller_SRC} ${controller_HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS
                                                 "-DVelocityDamperTestController_EXPORTS")
