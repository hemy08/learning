cmake_minimum_required(VERSION 3.26)
project(LEARNING_C C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/main.c ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE TEST_SRC ${PROJECT_SOURCE_DIR}/testcase/*.c ${PROJECT_SOURCE_DIR}/testcase/*.cpp)

list(APPEND SRC_FILES ${TEST_SRC})
list(APPEND SRC_FILES ${SRC_LIST})

set(HEAD_FILES
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/uthash
        src/public
        src/leetcode
        src/include
        src/learning
        testcase
)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/uthash
        src/public
        src/leetcode
        src/include
        src/learning
        testcase
)

link_directories(${PROJECT_SOURCE_DIR}/lib)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-attributes")

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES})

target_link_libraries(${PROJECT_NAME} -liconv)
add_definitions(-w -fgnu89-inline)
