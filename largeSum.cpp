#include <iostream>
#include <cstring>

using namespace std;

int computation ();

int main (const int argc, const char* const argv[]) { // Main function with command line arguments

    int carry = 0;
    int x = strlen(argv[1]) + 1;
    const int length1 = strlen(argv[1]);
    const int length2 = strlen(argv[2]);

    bool greater = false;

    char number1[length1];
    char number2[length2];

    if (strlen(argv[2]) > strlen(argv[1])) {
        x = strlen(argv[2]) + 1;
        greater = true;
    }

    char finalNumber[x];

    for (int i = length1 - 1; i >= 0; i--) { // Stores the values from argv1 into char array number1 and reverses the order
        number1[(length1 - 1) - i] = argv[1][i]; 
    }

    for (int i = length2 - 1; i >= 0; i--) // Stores the values from argv2 into char array number2 and reverses the order
        number2[(length2 - 1) - i] = argv[2][i];

    char temp;

    for (int i = 0; i < length1; i++) {
        int sum = (number1[i] - '0') + (number2[i] - '0') + carry;
        temp = (sum + '0'); 

        temp 
    }

    cout << temp;
    
    for (int i = 0; i <= strlen(argv[1]) - 1; i++)
        cout << number1[i];
    
    cout << "" << endl;

    for (int i = 0; i <= strlen(argv[1]) - 1; i++)
        cout << number2[i];
}