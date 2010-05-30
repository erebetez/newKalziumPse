# Try to find the Gmm++
# GMM_FOUND - system has Gmm++
# GMM_INCLUDE_DIR - the Gmm++ include directory

# Copyright (c) 2008, Allen Winter <winter@kde.org>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

if (GMM_INCLUDE_DIR)

  # Already in cache, be silent
  set(GMM_FIND_QUIETLY TRUE)

else (GMM_INCLUDE_DIR)

  find_path(GMM_INCLUDE_DIR
            NAMES gmm/gmm.h)

  mark_as_advanced(GMM_INCLUDE_DIR)

endif (GMM_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GMM DEFAULT_MSG GMM_INCLUDE_DIR)
