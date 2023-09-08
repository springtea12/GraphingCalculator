cmake_minimum_required(VERSION 3.24)
project(GraphingCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphingCalculator main.cpp includes/animate/animate.cpp includes/rpn/rpn.cpp includes/shunting_yard/shunting_yard.cpp includes/sidebar/sidebar.cpp includes/stub/stub.cpp includes/textbox/textbox.h includes/token/integer.cpp includes/token/function.cpp includes/token/leftparen.cpp includes/token/operator.cpp includes/token/rightparen.cpp includes/token/token.cpp)
target_link_libraries(GraphingCalculator sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
