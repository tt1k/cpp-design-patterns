project(demo LANGUAGES C CXX)

file(GLOB SOURCES *)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} cdps)