cmake_minimum_required(VERSION 3.30)
project(oiak_g6_Druszcz_Nowicki_Wilgus)

set(CMAKE_CXX_STANDARD 23)

add_executable(oiak_g6_Druszcz_Nowicki_Wilgus main.cpp
        include/FundamentalCarryOperator.h
        include/Bit.h
        src/FundamentalCarryOperator.cpp
        include/ParallelPrefixAdderElement.h
)
