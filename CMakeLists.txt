cmake_minimum_required(
    VERSION 3.1
)

set(EXECUTABLE_NAME "pong")

project(
    ${EXECUTABLE_NAME}
    VERSION 0.0.1
    DESCRIPTION "A pong game implementation"
    LANGUAGES CXX
)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

# Define sources and executable
add_executable(
    ${EXECUTABLE_NAME}
    src/main.cpp
    src/pong.cpp
    include/pong.hpp
)

include_directories(
    "${PROJECT_BINARY_DIR}"
)

# Detect and add SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES} ${SDL2_DEPENDENCIES})

# # Detect and add SFML
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# #Find any version 2.X of SFML
# #See the FindSFML.cmake file for additional details and instructions
# find_package(SFML 2 REQUIRED network audio graphics window system)
# if(SFML_FOUND)
#     include_directories(${SFML_INCLUDE_DIR})
#     target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
# endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${pong_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${pong_VERSION_MINOR}")
include(CPack)