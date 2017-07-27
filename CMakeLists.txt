cmake_minimum_required(VERSION 3.0.0)

project(CrispSynth)

set(LIBRARY_NAME
    crispsynth
)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

file(
        GLOB_RECURSE
        SRC_FILES
        ${CMAKE_SOURCE_DIR}/src/*
        ${CMAKE_SOURCE_DIR}/src/*/*
)

file(
        GLOB_RECURSE
        INCLUDE_FILES
        ${CMAKE_SOURCE_DIR}/include/{LIBRARY_NAME}/*
        ${CMAKE_SOURCE_DIR}/include/{LIBRARY_NAME}/*/*
)

include_directories(include/{LIBRARY_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${SRC_FILES}
)

INSTALL(TARGETS crispsynth
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION bin
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/${LIBRARY_NAME} DESTINATION include)

find_package(YamlCpp)
if(YAMLCPP_FOUND)
    include_directories(${YAMLCPP_INCLUDE_DIR})
    target_link_libraries(${LIBRARY_NAME} ${YAMLCPP_LIBRARY})
endif()

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
