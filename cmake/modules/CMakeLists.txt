# explicitely install the "public" cmake files

set(cmakeFiles
  FindKDEEdu.cmake
  FindMarbleWidget.cmake
)

install(FILES ${cmakeFiles} DESTINATION ${DATA_INSTALL_DIR}/cmake/modules)

