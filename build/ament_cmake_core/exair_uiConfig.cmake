# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_exair_ui_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED exair_ui_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(exair_ui_FOUND FALSE)
  elseif(NOT exair_ui_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(exair_ui_FOUND FALSE)
  endif()
  return()
endif()
set(_exair_ui_CONFIG_INCLUDED TRUE)

# output package information
if(NOT exair_ui_FIND_QUIETLY)
  message(STATUS "Found exair_ui: 0.1.0 (${exair_ui_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'exair_ui' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT exair_ui_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(exair_ui_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${exair_ui_DIR}/${_extra}")
endforeach()
