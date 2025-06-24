cmake_minimum_required(VERSION 3.5)

project(Tic-Tac-Toe)

add_executable(tic-tac-toe main.cpp)
target_link_libraries(tic-tac-toe ncurses)
