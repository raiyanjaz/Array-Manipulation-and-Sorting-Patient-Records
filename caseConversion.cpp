#include <iostream> // Include I/O library

using namespace std; // The standard namespace was declared to define the I/O object "cout"

int main () { // Main function
    char characterInput; // Declaring the char variable characterInput
    
    cout << "Please input a character: "; //Asking the user to input a character
    cin >> characterInput; // Allows user to input a character to initialize characterInput
    
    // The characterInput is converted into an integer based on the ASCII Table
    int characterInputNumber = characterInput;

    if (characterInputNumber >= 97 && characterInputNumber <= 122) { // If statement that will run following code when character input number is between 97 and 122 (checks if characterInput is lowercase)
        int uppercaseNumber = characterInputNumber - 32; // Subtracts 32 from character input number to change the lowercase character into its uppercase
        char uppercase = uppercaseNumber; // Converts the uppercase number into its corresponding uppercase value based on the ASCII Table
        cout << "The uppercase of " << characterInput << " is " << uppercase << endl; // Tells the user the uppercase character of the lowercase character they had input
    } else if (characterInputNumber >= 65  && characterInputNumber <= 90) { // Else If statement that will run following code when character input number is between 65 and 90 (checks if characterInput is uppercase)
        int lowercaseNumber = characterInputNumber + 32; // Adds 32 to the characterInputNumber to change the uppercase character into its lowercase
        char lowercase = lowercaseNumber; // Converts the lowercase number into its corresponding lowercase value based on the ASCII Table
        cout << "The lowercase of " << characterInput << " is " << lowercase << endl; // Tells the user the lowercase character of the uppercase character they had input
    } else if (characterInputNumber > 122 || characterInputNumber < 65 || characterInputNumber >=91 && characterInputNumber <= 96) { 
        // Else If statement that will run following code (checks if the character they input is not an uppercase or lowercase character)
        cout << "The input character is " << characterInput << endl; // Repeats to the user the character they had input    
    }
}