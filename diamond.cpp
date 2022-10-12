#include <iostream>

using namespace std;

int main () {
    int diamondSize; // Declared a variable called diamondSize

    cout << "How large do you want the diamond to be: ";
    cin >> diamondSize; // Allows user to input size of the diamond

    // Top half of diamond

    for (int i = 1; i <= (diamondSize-1); i++) // For loop to create the first line in the diamond shape
        cout << " ";  
    cout << "/\\" << endl;

    for (int x = 2; x <= (diamondSize-1); x++) {  // Nested for loop to create the shape from line 2 to line diamondSize-1
  
        for (int i = 1; i <= (diamondSize-x); i++) // For loop that creates the regular slashes on left side of top part of the diamond
            cout << " ";
        cout << "/"; 

        for (int i = diamondSize-x+2; i <= (diamondSize+x-1); i++) // For loop that creates backward slashes on other side of the top part of the diamond and moves on to the next line
            cout << " ";
        cout << "\\" << endl;
    }

    if (diamondSize > 1) // If the diamondSize is bigger than 1, the computer will print out line = diamondSize
        cout << "/";

    for (int i = 2; i <= (2*diamondSize-1); i++) // For loop to create the backward slash of the diamond on the other side at line = diamonSize
        cout << " ";
    cout << "\\";

    if (diamondSize > 1) // If diamondSize is greater than 1, the line will end and will move onto the bottom half
        cout << "" << endl; 

    // Bottom half of diamond

    if (diamondSize > 1) // If diamondSize is greater than 1, the system will print out the first backward slash in the bottom half
        cout << "\\";

    for (int i = 2; i <= (2*diamondSize-1); i++) // For loop that creates the first line on the bottom half or line = diamondSize + 1
        cout << " ";
    cout << "/" << endl;

    for ( int x = (diamondSize-1); x >= 1; x--) { // Nested for loop to create lines diamondSize + 2 to second last line of diamond shape

        for (int i = 1; i <= (diamondSize-x); i++) // For loop to create the backward slashes that goes inwards on the bottom half
            cout << " ";
        cout << "\\";

        for (int i = diamondSize-x+2; i <= (diamondSize+x-1); i++) // For loop to create regular slashes on the other side of the bottom triangle and move on to next line
            cout << " ";
        cout << "/" << endl;
    } // The nested for loop will also create the very last line of the diamond
}