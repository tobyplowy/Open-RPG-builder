cmake_minimum_required(VERSION 3.0)
project(dependencies)

option(LIBC "..." ON)

add_subdirectory(SDL2)
set_target_properties (SDL2 PROPERTIES FOLDER "third_party/SDL2")
set_target_properties (SDL2main PROPERTIES FOLDER "third_party/SDL2")
set_target_properties (SDL2-static PROPERTIES FOLDER "third_party/SDL2")
set_target_properties (uninstall PROPERTIES FOLDER "third_party/SDL2")