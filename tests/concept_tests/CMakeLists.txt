cmake_minimum_required(VERSION 3.4.0)
project(stl_concept_tests)

file(GLOB INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${INC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
