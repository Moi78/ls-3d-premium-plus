cmake_minimum_required(VERSION 3.7...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
   cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
   cmake_policy(VERSION 3.16)
endif()

project(lspremium VERSION 1.0 LANGUAGES CXX)

add_definitions("-std=c++17")
add_definitions("-fpermissive")

add_subdirectory("./ls-3d-premium-plus/")
add_subdirectory("./CustomExecutable/")
