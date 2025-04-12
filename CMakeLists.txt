cmake_minimum_required(VERSION 3.20)
project(PulseQ VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependency configuration
# Boost - try system package first
find_package(Boost 1.75 QUIET COMPONENTS system)
if(NOT Boost_FOUND)
  message(STATUS "Boost not found - downloading from source")
  FetchContent_Declare(
    Boost
    URL https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.gz
  )
  FetchContent_MakeAvailable(Boost)
endif()
find_package(Threads REQUIRED)

find_package(Catch2 3.4.0 QUIET COMPONENTS system)
if(NOT Catch2_FOUND)
  message(STATUS "Catch2 not found - downloading from source")
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
  )
  FetchContent_MakeAvailable(Catch2)
endif()

# Detect Apple Silicon
if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64" AND APPLE)
  set(APPLE_SILICON TRUE)
endif()

# Set different install paths
if(UNIX AND NOT APPLE)
  set(INSTALL_LIB_DIR lib/${CMAKE_LIBRARY_ARCHITECTURE} CACHE PATH "Installation directory for libraries")
elseif(APPLE)
  set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
endif()

# Common flags
add_compile_options(
  -Wall
  -Wextra
  -Wpedantic
  -Werror
)

# Apple Silicon specific
if(APPLE_SILICON)
  add_compile_options(-arch arm64)
  add_link_options(-arch arm64)
endif()

# Linux specific
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  add_compile_options(-pthread)
  add_link_options(-pthread)
endif()

# Main executable
add_executable(pulseq_bin  # Keep explicit binary name
  src/main.cpp
  src/networking/server.cpp
  src/queue/queue_manager.cpp
)

# Update all target references to pulseq_bin
target_include_directories(pulseq_bin PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${Boost_INCLUDE_DIRS}
)

target_link_libraries(pulseq_bin
  Boost::system
  Threads::Threads
)

# Testing setup
enable_testing()
add_subdirectory(test)
