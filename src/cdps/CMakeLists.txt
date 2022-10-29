project(cdps LANGUAGES C CXX)

file(GLOB SOURCES *)
add_library(${PROJECT_NAME} ${SOURCES})
