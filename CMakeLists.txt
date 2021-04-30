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

set (CMAKE_CXX_STANDARD 11)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

# Define sources and executable
add_executable(
    ${EXECUTABLE_NAME}
    src/main.cpp
    src/game.cpp

    src/game.hpp
)

include_directories(
    "${PROJECT_BINARY_DIR}"
)

if (WIN32)
    option(MINGW_ROOT "MINGW_ROOT" "D:/MingW")
    set(SDL2_INCLUDE_DIRS ${MINGW_ROOT}/include/SDL2/)
    set(SDL2_LIBRARIES
        mingw32
        SDL2main
        SDL2
    )
    
    include_directories(${SDL2_INCLUDE_DIRS})
    link_directories(${MINGW_ROOT}/lib/ ${MINGW_ROOT}/mingw/lib/)
    target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES})
endif (WIN32)

if (NOT WIN32)
    # Detect and add SDL2
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES} ${SDL2_DEPENDENCIES})
endif ()

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