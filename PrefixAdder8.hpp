#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>

class PrefixAdder8 {
private:
    std::vector<bool> A, B, G, P, C, S;

    void computeGeneratePropagate() {
        G.resize(8);
        P.resize(8);
        for (int i = 0; i < 8; ++i) {
            G[i] = A[i] & B[i];
            P[i] = A[i] ^ B[i];
        }
    }

    //Brent-Kung PPA
    void computePrefixTree() {
        C.resize(9);
        C[0] = true;  // Cin = 0

        std::vector<bool> G1(8), P1(8);
        std::vector<bool> G2(8), P2(8);
        std::vector<bool> G3(8), P3(8);

        // Level 1
        G1[1] = G[1] | (P[1] & G[0]);
        P1[1] = P[1] & P[0];
        G1[3] = G[3] | (P[3] & G[2]);
        P1[3] = P[3] & P[2];
        G1[5] = G[5] | (P[5] & G[4]);
        P1[5] = P[5] & P[4];
        G1[7] = G[7] | (P[7] & G[6]);
        P1[7] = P[7] & P[6];

        // Level 2
        G2[3] = G1[3] | (P1[3] & G1[1]);
        P2[3] = P1[3] & P1[1];
        G2[7] = G1[7] | (P1[7] & G1[5]);
        P2[7] = P1[7] & P1[5];

        // Level 3
        G3[7] = G2[7] | (P2[7] & G2[3]);

        // compute final carries
        C[1] = G[0];
        C[2] = G1[1];
        C[3] = G[2] | (P[2] & G1[1]);
        C[4] = G2[3];
        C[5] = G[4] | (P[4] & G2[3]);
        C[6] = G1[5] | (P1[5] & G2[3]);
        C[7] = G[6] | (P[6] & C[6]);
        C[8] = G3[7];
    }

    void computeSum() {
        S.resize(8);
        for (int i = 0; i < 8; ++i) {
            S[i] = P[i] ^ C[i];
        }
    }

public:
    PrefixAdder8(uint8_t a, uint8_t b) {
        A.resize(8);
        B.resize(8);
        for (int i = 0; i < 8; ++i) {
            A[i] = (a >> i) & 1;
            B[i] = (b >> i) & 1;
        }
        computeGeneratePropagate();
        computePrefixTree();
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

    void printDebug() const {
        std::cout << "Sum = " << std::bitset<8>(getSum()) << "\n";
        std::cout << "Cout = " << getCarryOut() << "\n";
    }
};
