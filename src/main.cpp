#include "../include/PrefixAdder8.hpp"
#include "../include/FlaggedPrefixAdder8.hpp"
#include "../include/FlaggedKoggeStone64.h"

int main(){
    uint8_t A = 0b10010001;
    uint8_t B = 0b00010001;
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
    FlaggedKoggeStone64 adder(A, B);
    adder.printDebug();

    return 0;
}