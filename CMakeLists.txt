# Minimum CMake version
cmake_minimum_required(VERSION 3.30)

# Project name
project(player)

# Add the 'src' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the 'third_party/imgui' directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends)

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

# Add source files (update with your actual source files)
add_executable(player 
    src/main.cpp 
    ${IMGUI_SOURCES}
    src/backend/Backend.cpp    
    src/backend/Backend.hpp    
)

# Link against DirectX 11 libraries
if (WIN32)
    target_link_libraries(player d3d11 dxgi dxguid d3dcompiler dwmapi)
endif()
