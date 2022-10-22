add_executable(cdps main.cpp)

include_directories(patterns)
add_subdirectory(patterns)
target_link_libraries(cdps patterns)
