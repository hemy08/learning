cmake_minimum_required(VERSION 3.27)
project(LEARNING_CPP)

SET(CMAKE_CXX_STANDARD 17)

SET(PRJ_ROOT ${PROJECT_SOURCE_DIR})

FILE(GLOB_RECURSE SRC_LIST
        ${PROJECT_SOURCE_DIR}/src/*.c
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/src/exercise/*.c
        ${PROJECT_SOURCE_DIR}/src/exercise/*.cpp
        ${PROJECT_SOURCE_DIR}/src/learning/*.c
        ${PROJECT_SOURCE_DIR}/src/learning/*.cpp
        ${PROJECT_SOURCE_DIR}/src/learning/*.c
        ${PROJECT_SOURCE_DIR}/src/learning/*.cpp
)

FILE(GLOB_RECURSE PUBLIC_SRC
        ${PROJECT_SOURCE_DIR}/src/public/*.c
        ${PROJECT_SOURCE_DIR}/src/public/*.cpp
        ${PROJECT_SOURCE_DIR}/public/*.c
        ${PROJECT_SOURCE_DIR}/public/*.cpp
)

FILE(GLOB_RECURSE OPEN_SRC
        ${PROJECT_SOURCE_DIR}/open_src/cJSON/*.c
        ${PROJECT_SOURCE_DIR}/open_src/cJSON/*.cpp)

LIST(APPEND SRC_FILES ${SRC_LIST})
LIST(APPEND SRC_FILES ${PUBLIC_SRC})
LIST(APPEND SRC_FILES ${OPEN_SRC})

SET(HEAD_FILES
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/public
        ${PROJECT_SOURCE_DIR}/open_src/cJSON
        src/leetcode
        src/exercise
        src/learning
        src/learning/src
)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/public
        ${PROJECT_SOURCE_DIR}/open_src/cJSON
        src/leetcode
        src/exercise
        src/learning
        src/learning/src
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-attributes")

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES})
