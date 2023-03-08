//WAP to implement the working mechanism of s-box 1 in DES.
#include <iostream>
#include <bitset>
using namespace std;
/*
S-box (substitution-box) is a crucial component of the DES algorithm. 
It is used to perform the nonlinear substitution step in the Feistel network of DES.
 There are eight different S-boxes, each of which takes a 6-bit input and produces a 4-bit output.

*/
// S-Box 1 definition
int sBox1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

// Function to apply S-Box 1
bitset<4> applySBox1(bitset<6> input) {
    // Get row number and column number
    int row = (input[5] << 1) + input[0];
    int col = (input[4] << 3) + (input[3] << 2) + (input[2] << 1) + input[1];

    // Lookup value in S-Box 1 and return result as bitset
    int output = sBox1[row][col];
    return bitset<4>(output);
}

int main() {
    // Example input
    bitset<6> input("010101");

    // Apply S-Box 1 and print result
    bitset<4> output = applySBox1(input);
    cout << "S-Box 1: \n\
        Input  (6-bit) : " << input << "\n\
        Output (4-bit) : " << output << endl;

    return 0;
}


