project(newPeriodSystem)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules )

find_package(Qt4 REQUIRED)
find_package(OpenBabel2 REQUIRED) # find and setup OpenBabel

include_directories(
   ${QT_INCLUDES}
   ${CMAKE_CURRENT_BINARY_DIR}
   ${OPENBABEL2_INCLUDE_DIR}
   )

set(newPeriodSystem_SRCS main.cpp mainWindow.cpp periodictablescene_p.cpp periodictableview.cpp elementitem_p.cpp)
qt4_automoc(${newPeriodSystem_SRCS})
add_executable(PeriodSystem ${newPeriodSystem_SRCS})
target_link_libraries(PeriodSystem ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${OPENBABEL2_LIBRARIES} science)
