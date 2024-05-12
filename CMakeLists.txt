cmake_minimum_required(VERSION 3.16)

project(MyGWCAProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")
add_library(my_gwca_library SHARED src/dllmain.cpp)

add_compile_options(/MP /permissive-)
target_compile_definitions(my_gwca_library PRIVATE NOMINMAX)

# Import GWCA as a dependency
include(FetchContent)
FetchContent_Declare(
        gwca
        GIT_REPOSITORY https://github.com/gwdevhub/gwca.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(gwca)
target_link_libraries(my_gwca_library PRIVATE gwca)
