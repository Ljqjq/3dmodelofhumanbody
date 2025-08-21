# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(ncurses_human_body CXX)

# Add the library
add_library(
    ncurses_human_body_lib SHARED
    library/BodyPart.cpp
)

# Tell the compiler where to find library headers
target_include_directories(
    ncurses_human_body_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/library
)

# Explicitly link the library to ncurses and tinfo
target_link_libraries(
    ncurses_human_body_lib PRIVATE ncurses tinfo
)

# Set the output directory for the library
set_target_properties(ncurses_human_body_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# Add the main application executable
add_executable(
    ncurses_human_body_app
    app/main.cpp
)

# Link the executable to our library and ncurses
# The order is critical: link your library first, then the libraries it depends on
target_link_libraries(
    ncurses_human_body_app
    PRIVATE
    ncurses_human_body_lib  # Our library must be linked first
    ncurses tinfo           # Then the libraries our code depends on
)

# Set the output directory for the executable
set_target_properties(ncurses_human_body_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)