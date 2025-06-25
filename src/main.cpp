#include "../include/PrefixAdder8.hpp"
#include "../include/FlaggedPrefixAdder8.hpp"
#include "../include/FlaggedKoggeStone64.h"

int main(){
    uint64_t A = 0b1000000011100000001000001000000000000000001100000000000000100011;
    uint64_t B = 0b1000000011100000010000001000000000000000011000000000000000000110;

    FlaggedKoggeStone64 adder(A, B, 0, 0);
    adder.printDebug(A, B);
//    PrefixAdder8 adder(A, B);
//    adder.printDebug();
//
//    // Przykład 1: Normalne dodawanie (bez flag)
//    FlaggedPrefixAdder8 adder1(A, B, 0b00000000);
//    std::cout << "bez flag:\n";
//    adder1.printDebug();
//    std::cout << "\n";
//
//    // Przykład 2: Z flagami blokującymi carry
//    FlaggedPrefixAdder8 adder2(A, B, 0b00010000);
//    std::cout << "flaga na 4 bicie:\n";
//    adder2.printDebug();
//    std::cout << "\n";
    return 0;
}