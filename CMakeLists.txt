cmake_minimum_required(VERSION 3.5)
project(hq_sim CXX)

include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cc)

aux_source_directory(models MODEL_SRC)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/models
)

target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${MODEL_SRC})