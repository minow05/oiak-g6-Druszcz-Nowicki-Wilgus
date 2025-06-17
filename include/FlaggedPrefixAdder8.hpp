#ifndef FLAGGED_PREFIX_ADDER_8_HPP
#define FLAGGED_PREFIX_ADDER_8_HPP

#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>

class FlaggedPrefixAdder8 {
private:
    std::vector<bool> A, B, G, P, K, C, S;
    std::vector<bool> flags;

    void computeGeneratePropagate() {
        G.resize(8);
        P.resize(8);
        K.resize(8);
        
        for (int i = 0; i < 8; ++i) {
            G[i] = A[i] & B[i];
            P[i] = A[i] ^ B[i];
            // Kill signal - when flag is set, it kills the carry propagation
            K[i] = flags[i];
        }
    }

    // Flagged Brent-Kung PPA
    void computeFlaggedPrefixTree() {
        C.resize(9);
        C[0] = false;  // Cin = 0

        std::vector<bool> G1(8), P1(8), K1(8);
        std::vector<bool> G2(8), P2(8), K2(8);
        std::vector<bool> G3(8), P3(8), K3(8);

        // Level 1 - compute (G,P,K) pairs
        for (int i = 1; i < 8; i += 2) {
            G1[i] = G[i] | (P[i] & G[i-1] & !K[i-1]);
            P1[i] = P[i] & P[i-1] & !K[i-1];
            K1[i] = K[i] | K[i-1];
        }

        // Level 2
        for (int i = 3; i < 8; i += 4) {
            G2[i] = G1[i] | (P1[i] & G1[i-2] & !K1[i-2]);
            P2[i] = P1[i] & P1[i-2] & !K1[i-2];
            K2[i] = K1[i] | K1[i-2];
        }

        // Level 3
        if (!K2[3]) {
            G3[7] = G2[7] | (P2[7] & G2[3]);
            P3[7] = P2[7] & P2[3];
        } else {
            G3[7] = G2[7];
            P3[7] = false;
        }
        K3[7] = K2[7] | K2[3];

        // Compute final carries with flag consideration
        C[1] = G[0] & !K[0];
        
        if (!K1[1]) {
            C[2] = G1[1];
        } else {
            C[2] = false;
        }
        
        C[3] = (G[2] | (P[2] & G1[1])) & !K[2] & !(K[2] | K1[1]);
        
        if (!K2[3]) {
            C[4] = G2[3];
        } else {
            C[4] = false;
        }
        
        C[5] = (G[4] | (P[4] & G2[3])) & !K[4] & !(K[4] | K2[3]);
        
        if (!K1[5] && !K2[3]) {
            C[6] = G1[5] | (P1[5] & G2[3]);
        } else {
            C[6] = G1[5] & !K1[5];
        }
        
        C[7] = (G[6] | (P[6] & C[6])) & !K[6];
        
        if (!K3[7]) {
            C[8] = G3[7];
        } else {
            C[8] = false;
        }
    }

    void computeSum() {
        S.resize(8);
        for (int i = 0; i < 8; ++i) {
            S[i] = P[i] ^ C[i];
        }
    }

public:
    FlaggedPrefixAdder8(uint8_t a, uint8_t b, uint8_t flagMask = 0) {
        A.resize(8);
        B.resize(8);
        flags.resize(8);
        
        for (int i = 0; i < 8; ++i) {
            A[i] = (a >> i) & 1;
            B[i] = (b >> i) & 1;
            flags[i] = (flagMask >> i) & 1;
        }
        
        computeGeneratePropagate();
        computeFlaggedPrefixTree();
        computeSum();
    }

    uint8_t getSum() const {
        uint8_t result = 0;
        for (int i = 0; i < 8; ++i) {
            result |= (S[i] << i);
        }
        return result;
    }

    bool getCarryOut() const {
        return C[8];
    }

    void setFlags(uint8_t flagMask) {
        for (int i = 0; i < 8; ++i) {
            flags[i] = (flagMask >> i) & 1;
        }
        // Recompute with new flags
        computeGeneratePropagate();
        computeFlaggedPrefixTree();
        computeSum();
    }

    void printDebug() const {
        std::cout << "A     = " << std::bitset<8>([this]() {
            uint8_t a = 0;
            for (int i = 0; i < 8; ++i) a |= (A[i] << i);
            return a;
        }()) << "\n";
        
        std::cout << "B     = " << std::bitset<8>([this]() {
            uint8_t b = 0;
            for (int i = 0; i < 8; ++i) b |= (B[i] << i);
            return b;
        }()) << "\n";
        
        std::cout << "Flags = " << std::bitset<8>([this]() {
            uint8_t f = 0;
            for (int i = 0; i < 8; ++i) f |= (flags[i] << i);
            return f;
        }()) << "\n";
        
        std::cout << "Sum   = " << std::bitset<8>(getSum()) << "\n";
        std::cout << "Cout  = " << getCarryOut() << "\n";
        
        std::cout << "Carries: ";
        for (int i = 0; i <= 8; ++i) {
            std::cout << C[i];
        }
        std::cout << "\n";
    }
};

#endif // FLAGGED_PREFIX_ADDER_8_HPP