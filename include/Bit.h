#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_BIT_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_BIT_H

#include <bitset>

class Bit {
private:
    std::bitset<1> bit;
public:
    void set(bool value) { bit[0] = value; }
    bool get() const { return bit[0]; }

    // Overload bitwise operators
    Bit operator&(const Bit& other) const { return Bit(bit & other.bit); }
    Bit operator|(const Bit& other) const { return Bit(bit | other.bit); }
    Bit operator^(const Bit& other) const { return Bit(bit ^ other.bit); }
    Bit operator~() const { return Bit(~bit); }

    explicit Bit(std::bitset<1> val) : bit(val) {}
    Bit() : bit(0){}
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_BIT_H
