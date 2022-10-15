#include <iostream>
#include <cstring>

using namespace std;

int main (const int argc, const char* const argv[]) { // Main function with command line arguments
    
    // Initiallizing two constant int variables to the length of first and second string argument respectively
    const int length1 = strlen(argv[1]); 
    const int length2 = strlen(argv[2]); 

    // Declaring two char arrays that have the same length as string argument 1 and 2 respectively
    char firstNumber[length1]; 
    char secondNumber[length2];

    int x = length1 + 1; // Initiallizing a variable as the length of argv[1] + 1
    
    if (length2 > length1) { // If statement that re-initializes x if argv[2] is greater than argv[1]
        x = length2 + 1;
    }

    char finalNumber[x]; // Declaring a char array with length x, to be used later

    for (int i = 0; i <= length1 - 1; i++) { // Stores the values from argv1 into char array firstNumber
        firstNumber[i] = argv[1][i]; 
    }

    for (int i = 0; i <= length2 - 1; i++) // Stores the values from argv2 into char array secondNumber
        secondNumber[i] = argv[2][i];
        
    int i = 1; // Initialized outside of for loops as it will be used through multiple for loops wihtout resetting
    int carry = 0; // Initializing carry to 0, will be used later during addition

    for (i; i <= length1 && i <= length2; i++) { // For loop that runs as long as i is less than or equal to the length of the shortest string argument
        
        // Converts digits of both char arrays into an int and adds them together
        // The two digits added together are divided by 10 and its remainder is converted back into a char using ASCII mapping table 
        finalNumber[x-i] = (((firstNumber[length1 - i] - '0') + (secondNumber[length2 - i] - '0') + carry) % 10) + '0';

        // If loop that re-initializes carry to 1 if the sum of the digits in the ones column of each number are greater than 10
        // Carry is then added to the tens column of each number in this for loop if required or will be added later
        if (((firstNumber[length1 - i] - 48) + (secondNumber[length2 - i] - 48) + carry) > 9) 
            carry = 1;
        else
            carry = 0;
    }
    
    for (i; i <= length1; i++) { // For loop that runs if there are more digits in the first string argument then second string argument

        // If carry is 1, it is added to the next column of numbers
        finalNumber[x-i] = (((firstNumber[length1 - i] - '0') + carry) % 10) + '0';

        // If digit is 9 and carry from previous digits was 1, then carry is recalculated in this if statement to equal 1
        if (((firstNumber[length1 - i] - '0') + carry) > 9)
            carry = 1;
        else
            carry = 0;
    }

    // Same for loop as the one above except it runs if there are more digits in the second string argument then first string argument
    for (i; i <= length2; i++) { 
        finalNumber[x-i] = (((secondNumber[length2 - i] - '0') + carry) % 10) + '0';

        if (((secondNumber[length2 - i] - '0') + carry) > 9)
            carry = 1;
        else
            carry = 0;
    }

    finalNumber[0] = carry + '0'; // First number in the finalNumber array is the value of carry converted into a char value using ASCII mapping table 

    bool finalNumberLength = false; // Bool variable set to false

    if (finalNumber[0] == '0') // If statement that runs when first digit in the sum is equal to 48 (value of 0 based on ASCII table)
        finalNumberLength = true; // If statement is true then bool variable is changed to false
    
    // For statement that will print out the sum
    // If bool variable is false, it will print out 0 to x values and if bool variable is true, it will print out 1 to x values
    for (i = finalNumberLength ? 1 : 0; i < x; i++) 
        cout << finalNumber[i];
}