# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tug_turtlebot4_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tug_turtlebot4_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tug_turtlebot4_FOUND FALSE)
  elseif(NOT tug_turtlebot4_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tug_turtlebot4_FOUND FALSE)
  endif()
  return()
endif()
set(_tug_turtlebot4_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tug_turtlebot4_FIND_QUIETLY)
  message(STATUS "Found tug_turtlebot4: 0.0.0 (${tug_turtlebot4_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tug_turtlebot4' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tug_turtlebot4_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tug_turtlebot4_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tug_turtlebot4_DIR}/${_extra}")
endforeach()
