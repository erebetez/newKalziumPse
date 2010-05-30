# - Try to find all KDE-Edu libraries
# Once done this will define
#
#  LIBKDEEDU_FOUND - system has at least one LIBKDEEDU libraries
#  KEDUVOCDOCUMENT_FOUND - system has keduvocdocument library
#  KDEEDUUI_FOUND - system has kdeeduui library
#  LIBSCIENCE_FOUND - system has libscience library
#  LIBKDEEDU_INCLUDE_DIRS - the LIBKDEEDU include directories (all include directories together)
#  LIBKEDUVOCDOCUMENT_INCLUDE_DIR - the include directory of the keduvocdocument library
#  LIBKDEEDUUI_INCLUDE_DIR - the include directory of the kdeeduui library
#  LIBSCIENCE_INCLUDE_DIR - the include directory of the libscience library
#  LIBKEDUVOCDOCUMENT_LIBRARY - the keduvocdocument library
#  LIBKDEEDUUI_LIBRARY - the kdeeduui library
#  LIBSCIENCE_LIBRARY - the libscience library
#
#  copyright 2008 by Patrick Spendrin <ps_ml@gmx.de>
#  use this file as you like
#

if(LIBKDEEDU_INCLUDE_DIRS AND LIBSCIENCE_LIBRARY AND LIBKDEEDUUI_LIBRARY AND LIBKEDUVOCDOCUMENT_LIBRARY)

  # Already in cache
  set(LIBKDEEDU_FOUND TRUE)

else(LIBKDEEDU_INCLUDE_DIRS AND LIBSCIENCE_LIBRARY AND LIBKDEEDUUI_LIBRARY AND LIBKEDUVOCDOCUMENT_LIBRARY)
  find_path(LIBKEDUVOCDOCUMENT_INCLUDE_DIR keduvocdocument.h PATH_SUFFIXES libkdeedu)
  find_path(LIBKDEEDUUI_INCLUDE_DIR libkdeedu_ui_export.h PATH_SUFFIXES libkdeedu)
  find_path(LIBSCIENCE_INCLUDE_DIR libkdeedu_science_export.h PATH_SUFFIXES libkdeedu)
  set(LIBKDEEDU_INCLUDE_DIRS ${LIBKEDUVOCDOCUMENT_INCLUDE_DIR}
                             ${LIBKDEEDUUI_INCLUDE_DIR}
                             ${LIBSCIENCE_INCLUDE_DIR})

  find_library(LIBKEDUVOCDOCUMENT_LIBRARY keduvocdocument)
  find_library(LIBKDEEDUUI_LIBRARY kdeeduui)
  find_library(LIBSCIENCE_LIBRARY libscience)

  if(LIBKEDUVOCDOCUMENT_INCLUDE_DIR AND LIBKEDUVOCDOCUMENT_LIBRARY)
    set(KEDUVOCDOCUMENT_FOUND TRUE)
  endif(LIBKEDUVOCDOCUMENT_INCLUDE_DIR AND LIBKEDUVOCDOCUMENT_LIBRARY)

  if(LIBKDEEDUUI_INCLUDE_DIR AND LIBKDEEDUUI_LIBRARY)
    set(KDEEDUUI_FOUND TRUE)
  endif(LIBKDEEDUUI_INCLUDE_DIR AND LIBKDEEDUUI_LIBRARY)

  if(LIBSCIENCE_INCLUDE_DIR AND LIBSCIENCE_LIBRARY)
    set(LIBSCIENCE_FOUND TRUE)
  endif(LIBSCIENCE_INCLUDE_DIR AND LIBSCIENCE_LIBRARY)

  if(KEDUVOCDOCUMENT_FOUND OR KDEEDUUI_FOUND OR LIBSCIENCE_FOUND)
    set(LIBKDEEDU_FOUND TRUE)
  endif(KEDUVOCDOCUMENT_FOUND OR KDEEDUUI_FOUND OR LIBSCIENCE_FOUND)

  if(LIBKDEEDU_FOUND)
      if (NOT LIBKDEEDU_FIND_QUIETLY)
        if(KEDUVOCDOCUMENT_FOUND)
          message(STATUS "Found KEduVocDocument: ${LIBKEDUVOCDOCUMENT_LIBRARY}")
        endif(KEDUVOCDOCUMENT_FOUND)

        if(KDEEDUUI_FOUND)
          message(STATUS "Found kdeeduui: ${LIBKDEEDUUI_LIBRARY}")
        endif(KDEEDUUI_FOUND)

        if(LIBSCIENCE_FOUND)
          message(STATUS "Found libscience: ${LIBSCIENCE_LIBRARY}")
        endif(LIBSCIENCE_FOUND)
      endif (NOT LIBKDEEDU_FIND_QUIETLY)
  else(LIBKDEEDU_FOUND)
    if(KDEEDU_FIND_REQUIRED)
      message(FATAL_ERROR "Could NOT find any KDE Edu library")
    endif(KDEEDU_FIND_REQUIRED)
  endif(LIBKDEEDU_FOUND)

  mark_as_advanced(LIBKDEEDUUI_INCLUDE_DIR LIBKEDUVOCDOCUMENT_INCLUDE_DIR LIBSCIENCE_INCLUDE_DIR LIBKDEEDU_INCLUDE_DIRS
                   LIBKDEEDUUI_LIBRARY     LIBKEDUVOCDOCUMENT_LIBRARY     LIBSCIENCE_LIBRARY)

endif(LIBKDEEDU_INCLUDE_DIRS AND LIBSCIENCE_LIBRARY AND LIBKDEEDUUI_LIBRARY AND LIBKEDUVOCDOCUMENT_LIBRARY)