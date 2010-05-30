project(newPeriodSystem)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(
   ${QT_INCLUDES} 
   ${CMAKE_CURRENT_BINARY_DIR}
   )

set(newPeriodSystem_SRCS main.cpp periodsystembase.cpp)
qt4_automoc(${newPeriodSystem_SRCS})
add_executable(PeriodSystem ${newPeriodSystem_SRCS})
target_link_libraries(PeriodSystem ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} science)
