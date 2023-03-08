//WAP to implement Elgamal Cryptographic System
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to compute modular exponentiation (a^b mod n)
int mod_exp(int a, int b, int n) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % n;
        }
        a = (a * a) % n;
        b /= 2;
    }
    return res;
}

int main() {
    srand(time(0)); // Seed the random number generator

    const int p = 13; // A prime number
    const int g = 5; // A primitive root modulo p
    int a = rand() % (p-2) + 1; // Random private key a in the range [1, p-2]
    int h = mod_exp(g, a, p); // Compute public key h = g^a mod p
    cout << "Private key: " << a << endl;
    cout << "Public key: (" << p << ", " << g << ", " << h << ")" << endl;

    // Encryption
    int k = rand() % (p-2) + 1; // Random integer k in the range [1, p-2]
    int m = 9; // Plaintext message
    int c1 = mod_exp(g, k, p); // Compute c1 = g^k mod p
    int c2 = (m * mod_exp(h, k, p)) % p; // Compute c2 = m*(h^k) mod p
    cout << "Plaintext message: " << m << endl;
    cout << "Ciphertext: (" << c1 << ", " << c2 << ")" << endl;

    // Decryption
    int c1_inv = mod_exp(c1, p-1-a, p); // Compute (c1^a)^-1 mod p using Fermat's Little Theorem
    int m_dec = (c2 * c1_inv) % p; // Compute decrypted message m = c2*(c1^a)^-1 mod p
    cout << "Decrypted message: " << m_dec << endl;

    return 0;
}

