//WAP to show the working mechanism of expansion P-box in DES.
#include <iostream>
#include <bitset>
using namespace std;

// Expansion P-box table for DES
int pbox_table[] = {
    32,  1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};

// Function to perform the expansion P-box permutation
bitset<48> pbox_expansion(bitset<32> input) {
    bitset<48> output;
    for (int i = 0; i < 48; i++) {
        output[i] = input[pbox_table[i]-1];
    }
    return output;
}

int main() {
    bitset<32> input("00010010001101000101011001111000");

    bitset<48> output = pbox_expansion(input);
    cout << "P-Box \n\
        Input  (32-bit) : " << input <<"\n\
        Output (48-bit) : " << output << endl;

    return 0;
}


