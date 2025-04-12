# test/CMakeLists.txt
find_package(Catch2 REQUIRED)
add_executable(test_queue unit/test_queue.cpp)

target_include_directories(test_queue PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(test_queue
  PRIVATE Catch2::Catch2
)
