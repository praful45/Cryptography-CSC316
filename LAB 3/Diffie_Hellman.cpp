//WAP to implement Diffe-Hellman key exchange algorithm.
#include <iostream>
#include<chrono>
using namespace std;
// Calculates a^b mod m
int mod_pow(int a, int b, int m) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    srand(time(NULL));
    int p=19;       // a prime number
    int g=13;        // primitive root of p

    cout << "Two global elements are \n\
        Prime number(p) = "<< p << "\n\
        Primitive root(g) = " << g << endl << endl;
    // Generate a random private key for Alice in the range [2, n-1]
    int Xa = rand() % p;

    // Generate a random private key for Bob in the range [2, n-1]
    int Xb = rand() % p;

    // Calculate Alice's public key
    int Ya = mod_pow(g, Xa, p);
    // Calculate Bob's public key
    int Yb = mod_pow(g, Xb, p);

    // Calculate the shared secret key for Alice
    int s_a = mod_pow(Yb, Xa, p);
    // Calculate the shared secret key for Bob
    int s_b = mod_pow(Ya, Xb, p);
    
    cout << "Alice's keys: \n\
        private key : "<< Xa << "\n\
        public key  : "<< Ya << endl << endl;
 
    cout << "Bob's keys: \n\
        private key : "<< Xb << "\n\
        public key  : "<< Yb << endl << endl;
        


    // Print the shared secret key for Alice and Bob
    cout << "Shared secret key calculated by\n\
        Alice: " << s_a << "\n\
        Bob: " << s_b << endl << endl;
    return 0;
}

