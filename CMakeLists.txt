cmake_minimum_required(VERSION 3.30)
project(oiak_g6_Druszcz_Nowicki_Wilgus)

set(CMAKE_CXX_STANDARD 23)

add_executable(oiak_g6_Druszcz_Nowicki_Wilgus src/main.cpp
        include/FlaggedPrefixAdder8.hpp
        include/PrefixAdder8.hpp
        include/FlaggedKoggeStone64.h
        src/FlaggedKoggeStone64.cpp
        include/FlaggedAdder.h
)
