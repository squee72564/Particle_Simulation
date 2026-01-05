cmake_minimum_required(VERSION 3.8)

project(particle_simulation CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(particle_simulation "src/main.cpp")

target_sources(particle_simulation PRIVATE 
    "src/ParticleManager.cpp"
)

target_include_directories(particle_simulation PRIVATE
    "include"
)

target_link_libraries(particle_simulation PRIVATE
    OpenGL::GL
    glfw
    glad::glad
    glm::glm-header-only
    fmt::fmt-header-only
)
