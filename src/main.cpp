#include "../include/HalfAdder.h"
#include "../include/FundamentalCarryOperator.h"
#include "../include/SumGenerator.h"

int main(){
    int carryIn = 0;
    int x0 = 1;
    int y0 = 1;
    int x1 = 0;
    int y1 = 1;
    int x2 = 1;
    int y2 = 1;
    int x3 = 0;
    int y3 = 0;
//     1010 + 1010
    SumGenerator sumGenerator0(0);
    SumGenerator sumGenerator1(1);
    SumGenerator sumGenerator2(2);
    SumGenerator sumGenerator3(3);
    SumGenerator sumGenerator4(4);
    FundamentalCarryOperator fco22(2, &sumGenerator3);
    FundamentalCarryOperator fco32(3, &sumGenerator4);
    FundamentalCarryOperator fco11(1, std::vector<FundamentalCarryOperator*>{&fco22, &fco32}, &sumGenerator2);
//    FundamentalCarryOperator fco11(1, &sumGenerator2);
    FundamentalCarryOperator fco31(3, std::vector<FundamentalCarryOperator*>{&fco32});

    HalfAdder halfAdder0(Bit(x0), Bit(y0), 0, std::vector<FundamentalCarryOperator*>{&fco11}, &sumGenerator0);
    halfAdder0.assignGenerationPropagationSumGenerator(&sumGenerator1);
    HalfAdder halfAdder1(Bit(x1), Bit(y1), 1, std::vector<FundamentalCarryOperator*>{&fco11}, &sumGenerator1);
    HalfAdder halfAdder2(Bit(x2), Bit(y2), 2, std::vector<FundamentalCarryOperator*>{&fco22, &fco31}, &sumGenerator2);
    HalfAdder halfAdder3(Bit(x3), Bit(y3), 3, std::vector<FundamentalCarryOperator*>{&fco31}, &sumGenerator3);

    halfAdder0.execute();
    halfAdder1.execute();
    halfAdder2.execute();
    halfAdder3.execute();
    fco11.execute();
    fco31.execute();
    fco22.execute();
    fco32.execute();
    sumGenerator0.execute();
    sumGenerator1.execute();
    sumGenerator2.execute();
    sumGenerator3.execute();
    sumGenerator4.execute();

    return 0;
}