cmake_minimum_required(VERSION 3.20)

project(particle_simulation CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_library(particle_simulation_core STATIC)

target_sources(particle_simulation_core PRIVATE
    "src/core/ParticleManager.cpp"
)

target_include_directories(particle_simulation_core PUBLIC
    "include"
)

target_link_libraries(particle_simulation_core PUBLIC
    glm::glm-header-only
)

add_executable(particle_simulation "src/main.cpp")

target_link_libraries(particle_simulation PRIVATE
    particle_simulation_core
    OpenGL::GL
    glfw
    glad::glad
)

include(CTest)

if(BUILD_TESTING)
    find_package(GTest CONFIG REQUIRED)

    add_executable(particle_simulation_tests
        "src/__tests__/ParticleManagerTest.cpp"
    )

    target_link_libraries(particle_simulation_tests PRIVATE
        particle_simulation_core
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(particle_simulation_tests)
endif()
