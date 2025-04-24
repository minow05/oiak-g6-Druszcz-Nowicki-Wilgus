#include <iostream>
#include "../include/SumGenerator.h"
#include "../include/Bit.h"

void SumGenerator::execute() {
    if (column == 0) {
        sum = halfSum ^ carry;
    } else {
        sum = halfSum ^ ((propagation & carry) | generation);
    }
    std::cout << column << ": " << sum.get() << "\n" ;
}

void SumGenerator::setHalfSum(Bit halfSum) {
    this->halfSum = halfSum;
}

void SumGenerator::setCarry(Bit carry) {
    this->carry = carry;
}

void SumGenerator::setGeneration(Bit generation) {
    this->generation = generation;
}

void SumGenerator::setPropagation(Bit propagation) {
    this->propagation = propagation;
}

SumGenerator::SumGenerator(int column) :
column(column)
{}
