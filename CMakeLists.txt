cmake_minimum_required(VERSION 3.0.0)

project(CrispSynth)

set(LIBRARY_NAME
    crispsynth
)

set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)

include_directories(${LIBRARY_HEADERS_DIR})

file(GLOB_RECURSE LIBRARY_HEADERS
    "${LIBRARY_HEADERS_DIR}/*.h"
    "${LIBRARY_HEADERS_DIR}/*/*.h"
)

set(LIBRARY_SOURCE_DIR
    src
)

include_directories(${LIBRARY_SOURCE_DIR})

file(GLOB_RECURSE LIBRARY_SOURCE
    "${LIBRARY_SOURCE_DIR}/*.cpp"
    "${LIBRARY_SOURCE_DIR}/*/*.cpp"
)

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCE}
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
