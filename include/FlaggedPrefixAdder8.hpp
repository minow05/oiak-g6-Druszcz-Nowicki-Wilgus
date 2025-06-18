#ifndef FLAGGED_PREFIX_ADDER_8_HPP
#define FLAGGED_PREFIX_ADDER_8_HPP

#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>

class FlaggedPrefixAdder8 {
private:
    std::vector<bool> A, B, G, P, notK, C, S;
    bool inc, cmp;

    void computeGeneratePropagate() {
        G.resize(8);
        P.resize(8);
        notK.resize(8);

        for (int i = 0; i < 8; ++i) {
            G[i] = A[i] & B[i];
            P[i] = A[i] ^ B[i];
            notK[i] = A[i] | B[i]; // notK = A OR B
        }
    }

    // Poprawiony Flagged Brent-Kung prefix adder
    void computeFlaggedPrefixTree() {
        C.resize(9);
        C[0] = inc; // inc = 1 -> carry-in = 1 (late increment)

        std::vector<bool> G_curr(8), notK_curr(8);
        std::vector<bool> G_next(8), notK_next(8);
        
        for (int i = 0; i < 8; ++i) {
            G_curr[i] = G[i];
            notK_curr[i] = notK[i];
        }

        // Level 1:
        for (int i = 0; i < 8; ++i) {
            G_next[i] = G_curr[i];
            notK_next[i] = notK_curr[i];
        }
        
        for (int i = 1; i < 8; i += 2) {
            G_next[i] = G_curr[i] | (notK_curr[i] & G_curr[i - 1]);
            notK_next[i] = notK_curr[i] & notK_curr[i - 1];
        }
        
        G_curr = G_next;
        notK_curr = notK_next;

        // Level 2:
        for (int i = 3; i < 8; i += 4) {
            G_next[i] = G_curr[i] | (notK_curr[i] & G_curr[i - 2]);
            notK_next[i] = notK_curr[i] & notK_curr[i - 2];
        }
        
        G_curr = G_next;
        notK_curr = notK_next;

        // Level 3:
        G_next[7] = G_curr[7] | (notK_curr[7] & G_curr[3]);
        notK_next[7] = notK_curr[7] & notK_curr[3];
        
        
        G_curr = G_next;
        notK_curr = notK_next;

        std::vector<bool> G_final(8), notK_final(8);
        for (int i = 0; i < 8; ++i) {
            G_final[i] = G_curr[i];
            notK_final[i] = notK_curr[i];
        }

        // Level 3 backward: propaguj z pozycji 7 do 5, 6
        for (int i = 4; i < 7; ++i) {
            if (i != 7) {
                G_final[i] = G_final[i] | (notK_final[i] & G_final[7]);
                notK_final[i] = notK_final[i] & notK_final[7];
            }
        }

        // Level 2 backward: propaguj z pozycji 3, 7 do 1, 2, 5, 6
        for (int i = 0; i < 8; ++i) {
            if (i != 3 && i != 7) {
                int ref_pos = (i < 4) ? 3 : 7;
                if (ref_pos < 8) {
                    G_final[i] = G_final[i] | (notK_final[i] & G_final[ref_pos]);
                    notK_final[i] = notK_final[i] & notK_final[ref_pos];
                }
            }
        }

        // Level 1 backward: propaguj z pozycji nieparzystych do parzystych
        for (int i = 0; i < 8; i += 2) {
            if (i + 1 < 8) {
                G_final[i] = G_final[i] | (notK_final[i] & G_final[i + 1]);
                notK_final[i] = notK_final[i] & notK_final[i + 1];
            }
        }

        // Oblicz ostateczne carry
        for (int i = 0; i < 8; ++i) {
            C[i + 1] = G_final[i] | (notK_final[i] & C[0]);
        }
    }

    void computeSum() {
        S.resize(8);
        for (int i = 0; i < 8; ++i) {
            bool baseSum = P[i] ^ C[i];
            S[i] = cmp ? !baseSum : baseSum; // cmp=1 -> negacja sumy
        }
    }

public:
    FlaggedPrefixAdder8(uint8_t a, uint8_t b, bool incControl = false, bool cmpControl = false) {
        A.resize(8);
        B.resize(8);
        inc = incControl;
        cmp = cmpControl;

        for (int i = 0; i < 8; ++i) {
            A[i] = (a >> i) & 1;
            B[i] = (b >> i) & 1;
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

    void setControl(bool incControl, bool cmpControl) {
        inc = incControl;
        cmp = cmpControl;
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

        std::cout << "inc   = " << inc << "\n";
        std::cout << "cmp   = " << cmp << "\n";

        std::cout << "Sum   = " << std::bitset<8>(getSum()) << "\n";
        std::cout << "Cout  = " << getCarryOut() << "\n";
    }
};

#endif // FLAGGED_PREFIX_ADDER_8_HPP