cmake_minimum_required(VERSION 3.0.0)

project(CrispSynth)

set(LIBRARY_NAME
    crispsynth
)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
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
    ${INCLUDE_FILES}
)

install(TARGETS crispsynth
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION bin
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/${LIBRARY_NAME} DESTINATION include)

find_package(Boost COMPONENTS system thread filesystem REQUIRED)
if (BOOST_FOUND)
    include_directories(Boost_INCLUDE_DIR)
    ADD_DEFINITIONS("-DHAS_BOOST")
endif()
target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES})

find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${LIBRARY_NAME} ${SFML_LIBRARIES})
endif()

find_package(OpenGL)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    target_link_libraries(${LIBRARY_NAME} ${OPENGL_LIBRARIES})
endif()

find_package(GLEW)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME} ${GLEW_LIBRARIES})
endif()

find_package(GLM)
if (GLM_FOUND)
    include_directories(${GLM_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME} ${GLM_LIBRARIES})
endif()

find_package(ASSIMP)
if (ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME} ${ASSIMP_LIBRARIES})
endif()

set(YAMLCPP_STATIC_LIBRARY TRUE)
find_package(Yaml-Cpp)
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

ADD_CUSTOM_TARGET(run_install COMMAND ${CMAKE_MAKE_PROGRAM} install)
