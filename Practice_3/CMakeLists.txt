cmake_minimum_required(VERSION 3.23)
project (Practice_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practice_3
        main.cpp
        KinematicSolver/KinematicSolver.cpp
        KinematicSolver/KinematicSolver.hpp
        AnimationEngine/AnimationEngine.hpp
        MegaOriginalKinematicSolver.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Development/C++Project/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/Development/C++Project/SFML/SFML-2.5.1/include)
target_link_libraries(Practice_3 sfml-system sfml-window sfml-graphics sfml-audio)