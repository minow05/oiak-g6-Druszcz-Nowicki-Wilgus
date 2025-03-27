cmake_minimum_required(VERSION 3.30)
project(oiak_g6_Druszcz_Nowicki_Wilgus)

set(CMAKE_CXX_STANDARD 23)

add_executable(oiak_g6_Druszcz_Nowicki_Wilgus src/main.cpp
        include/FundamentalCarryOperator.h
        include/Bit.h
        src/FundamentalCarryOperator.cpp
        include/HalfAdder.h
        include/SumGenerator.h
        include/Builder.h
        src/HalfAdder.cpp
        src/SumGenerator.cpp
)
