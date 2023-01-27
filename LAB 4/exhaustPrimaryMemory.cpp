#include <iostream>

using namespace std;

int main() {
    while (true) {
        try {
            new char[1000000000ul];
        } catch (bad_alloc& e) {
            cout << "Out of memory" << endl;
            break;
        }
    }
    return 0;
}
