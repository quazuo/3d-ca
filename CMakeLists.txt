cmake_minimum_required(VERSION 3.16)
project(3dca)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

add_subdirectory(deps)

include_directories(
        deps/glfw/include/
        deps/glm/
        .
)

set(ALL_LIBS
        Vulkan::Vulkan
        glfw
)

file(GLOB IMGUI_SRCS
        "deps/imgui/*.h"
        "deps/imgui/*.cpp"
)

set(IMGUI_IMPL_SRCS
        deps/imgui/backends/imgui_impl_glfw.h
        deps/imgui/backends/imgui_impl_glfw.cpp
        deps/imgui/backends/imgui_impl_vulkan.h
        deps/imgui/backends/imgui_impl_vulkan.cpp
)

set_source_files_properties(
        ${IMGUI_SRCS}
        ${IMGUI_IMPL_SRCS}
        PROPERTIES COMPILE_FLAGS "-w"
)

file(GLOB deps_SRCS
        "deps/vma/*"
)

file(GLOB 3dca_SRCS
        "src/*"
        "src/render/*"
        "src/render/vk/*"
        "src/render/gui/*"
        "src/utils/*"
        "src/shaders/*"
)

add_executable(3dca ${3dca_SRCS} ${deps_SRCS} ${IMGUI_SRCS} ${IMGUI_IMPL_SRCS})
target_link_libraries(3dca ${ALL_LIBS})

file(GLOB shader_export_SRCS
        "shaders/export_tool/export.cpp"
)

add_executable(shader_export ${shader_export_SRCS})
