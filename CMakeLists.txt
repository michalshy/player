# Minimum CMake version
cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Project name
project(player)

# Add the 'src' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the 'third_party/imgui' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/misc/cpp)

# Add miniaudio library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/miniaudio)

# ImGui source files (use absolute paths)
set(IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_win32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_dx11.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/misc/cpp/imgui_stdlib.cpp
)

# Recursively find all .cpp and .hpp files in src/
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
)

# Add miniaudio implementation file if not already included
set(MINIAUDIO_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/miniaudio/miniaudio.c
)

# Add source files (update with your actual source files)
add_executable(player 
    ${PROJECT_SOURCES}
    ${IMGUI_SOURCES}
    ${MINIAUDIO_SOURCES}
)

# Link against DirectX 11 libraries
if (WIN32)
    target_link_libraries(player d3d11 dxgi dxguid d3dcompiler dwmapi)
endif()

# Copy media directory to build directory after build
add_custom_command(TARGET player POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/media $<TARGET_FILE_DIR:player>/media
)
