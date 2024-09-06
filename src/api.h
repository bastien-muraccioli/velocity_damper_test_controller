#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define VelocityDamperTestController_DLLIMPORT __declspec(dllimport)
#  define VelocityDamperTestController_DLLEXPORT __declspec(dllexport)
#  define VelocityDamperTestController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define VelocityDamperTestController_DLLIMPORT __attribute__((visibility("default")))
#    define VelocityDamperTestController_DLLEXPORT __attribute__((visibility("default")))
#    define VelocityDamperTestController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define VelocityDamperTestController_DLLIMPORT
#    define VelocityDamperTestController_DLLEXPORT
#    define VelocityDamperTestController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef VelocityDamperTestController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define VelocityDamperTestController_DLLAPI
#  define VelocityDamperTestController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef VelocityDamperTestController_EXPORTS
#    define VelocityDamperTestController_DLLAPI VelocityDamperTestController_DLLEXPORT
#  else
#    define VelocityDamperTestController_DLLAPI VelocityDamperTestController_DLLIMPORT
#  endif // VelocityDamperTestController_EXPORTS
#  define VelocityDamperTestController_LOCAL VelocityDamperTestController_DLLLOCAL
#endif // VelocityDamperTestController_STATIC
