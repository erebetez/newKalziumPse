# - Try to find CFITSIO
# Once done this will define
#
#  CFITSIO_FOUND - system has CFITSIO
#  CFITSIO_INCLUDE_DIR - the CFITSIO include directory
#  CFITSIO_LIBRARIES - Link these to use CFITSIO

# Copyright (c) 2006, Jasem Mutlaq <mutlaqja@ikarustech.com>
# Based on FindLibfacile by Carsten Niehaus, <cniehaus@gmx.de>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

if (CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)

  # in cache already
  set(CFITSIO_FOUND TRUE)
  message(STATUS "Found CFITSIO: ${CFITSIO_LIBRARIES}")


else (CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)

  IF (NOT WIN32)
    find_package(PkgConfig)
    IF (PKG_CONFIG_FOUND)    
      pkg_check_modules(CFITSIO cfitsio)
    ENDIF (PKG_CONFIG_FOUND)
  ENDIF (NOT WIN32)

  find_path(CFITSIO_INCLUDE_DIR fitsio.h
    ${CFITSIO_INCLUDE_DIRS}
    ${_obIncDir}
    ${GNUWIN32_DIR}/include
  )

  find_library(CFITSIO_LIBRARIES NAMES cfitsio libcfitsio
    PATHS
    ${CFITSIO_LIBRARY_DIRS}
    ${_obLinkDir}
    ${GNUWIN32_DIR}/lib
  )

  if(CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)
    set(CFITSIO_FOUND TRUE)
  else (CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)
    set(CFITSIO_FOUND FALSE)
  endif(CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)


  if (CFITSIO_FOUND)
    if (NOT CFitsio_FIND_QUIETLY)
      message(STATUS "Found CFITSIO: ${CFITSIO_LIBRARIES}")
    endif (NOT CFitsio_FIND_QUIETLY)
  else (CFITSIO_FOUND)
    if (CFitsio_FIND_REQUIRED)
      message(FATAL_ERROR "CFITSIO not found. Please install libcfitsio0-devel and try again. http://indi.sf.net")
    endif (CFitsio_FIND_REQUIRED)
  endif (CFITSIO_FOUND)

  mark_as_advanced(CFITSIO_INCLUDE_DIR CFITSIO_LIBRARIES)

endif (CFITSIO_INCLUDE_DIR AND CFITSIO_LIBRARIES)
