//1)Write a program to show working of initial and final permutation box DES.
#include <iostream>
#include <bitset>
using namespace std;
int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7};

int FP[] = {40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25};
bitset<64> initialPermutation(bitset<64> input) {
    bitset<64> ip_bits;     // initial permutation bits 
    for (int i = 0; i < 64; i++)
        ip_bits[i] = input[IP[i] - 1];
    return ip_bits; 
}

bitset<64> finalPermutation(bitset<64> ip_bits) {
    bitset<64> fp_bits;     // final permutation bits
    for (int i = 0; i < 64; i++)
        fp_bits[i] = ip_bits[FP[i] - 1];
    return fp_bits; 
}
int main() {
    string input = "1101101110111011101101110111011101101110111011101101110111011101";
    bitset<64> input_bits(input);

    bitset<64> ip_bits = initialPermutation(input_bits);  
    bitset<64> fp_bits = finalPermutation(ip_bits);

    cout << "Original message    : " << input << endl << endl; 
    cout << "Initial Permutation : " << ip_bits << endl;
    cout << "Final Permutation   : " << fp_bits << endl;

    return 0;
}

