#include <iostream>
#include <cstring>

using namespace std;

int computation ();

int main (const int argc, const char* const argv[]) { // Main function with command line arguments

    int x = strlen(argv[1]) + 1;
    const int length1 = strlen(argv[1]);
    const int length2 = strlen(argv[2]);

    char number1[length1];
    char number2[length2];

    if (strlen(argv[2]) > strlen(argv[1])) {
        x = strlen(argv[2]) + 1;
    }

    char finalNumber[x];

    for (int i = length1 - 1; i >= 0; i--) { // Stores the values from argv1 into char array number1 and reverses the order
        number1[i] = argv[1][i]; 
    }

    for (int i = length2 - 1; i >= 0; i--) // Stores the values from argv2 into char array number2 and reverses the order
        number2[i] = argv[2][i];
    
    for (int i=x-1; i>=0; i--)
        finalNumber[i] = 48;
    
    int i = 1;
    int carry = 0;

    for (i; i <= length1 && i <= length2; i++) { // Finding the carry value
        finalNumber[x-i] = (((number1[length1 - i] - 48) + (number2[length2 - i] - 48) + carry) % 10) + '0';

        if (((number1[length1 - i] - 48) + (number2[length2 - i] - 48) + carry) > 9)
            carry = 1;
        else
            carry = 0;
    }
    
    for (i; i <= length1; i++) {
        finalNumber[x-i] = (((number1[length1 - i] - 48) + carry) % 10) + '0';

        if (((number1[length1 - i] - 48) + carry) > 9)
            carry = 1;
        else
            carry = 0;
    }

    for (i; i <= length2; i++) {
        finalNumber[x-i] = (((number2[length2 - i] - 48) + carry) % 10) + '0';

        if (((number2[length2 - i] - 48) + carry) > 9)
            carry = 1;
        else
            carry = 0;
    }

    finalNumber[0] = carry + 48;

    int k = 1;

    if (finalNumber[0] == 48)
        k = 0;
    
    for (k = 0 ? 1 : 0; k < x; k++)
        cout << finalNumber[k];
}