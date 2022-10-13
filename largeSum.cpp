#include <iostream>
#include <cstring>

using namespace std;

int computation ();

int main (const int argc, const char* const argv[]) { // Main function with command line arguments

    char carry = 0;
    int x = strlen(argv[1]) + 1;
    const int length1 = strlen(argv[1]);
    const int length2 = strlen(argv[2]);

    bool greater = false;

    char one[length1];
    char two[length2];

    if (strlen(argv[2]) > strlen(argv[1])) {
        x = strlen(argv[2]) + 1;
        greater = true;
    }

    char sum[x];

    for (int i = strlen(argv[1]) - 1; i >= 0; i--)
        one[i] = argv[1][i];

    for (int i = strlen(argv[2]) - 1; i >= 0; i--)
        two[i] = argv[2][i];
    
    for (int i = strlen(argv[1]) - 1; i >= 0; i--) {
        if (one[i] = '0')
            one[i] = 0;
    }

}