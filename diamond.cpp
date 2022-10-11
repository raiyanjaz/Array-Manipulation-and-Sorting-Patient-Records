#include <iostream>

using namespace std;

int main () {
    int diamondSize;

    cout << "How large do you want the diamond to be: ";
    cin >> diamondSize;

    // Top half of diamond

    for (int i = 1; i <= (diamondSize-1); i++) // For loop to create the first line in the diamond shape
        cout << " ";  
    cout << "/\\" << endl;

    for (int x = 2; x <= (diamondSize-1); x++) {  // Nested for loop to create the shape from line 2 to line diamondSize-1
  
        for (int i = 1; i <= (diamondSize-x); i++) 
            cout << " ";
        cout << "/"; 

        for (int i = diamondSize-x+2; i <= (diamondSize+x-1); i++)
            cout << " ";
        cout << "\\" << endl;
    }

    if (diamondSize > 1)
        cout << "/";

    for (int i = 2; i <= (2*diamondSize-1); i++)
        cout << " ";
    cout << "\\";

    if (diamondSize > 1)
        cout << "" << endl;

    // Bottom half of diamond

    if (diamondSize > 1)
        cout << "\\";

    for (int i = 2; i <= (2*diamondSize-1); i++)
        cout << " ";
    cout << "/" << endl;

    for ( int x = (diamondSize-1); x >= 1; x--) { // Nested for loop to create lines diamondSize + 2 to second last line of diamond shape

        for (int i = 1; i <= (diamondSize-x); i++)
            cout << " ";
        cout << "\\";

        for (int i = diamondSize-x+2; i <= (diamondSize+x-1); i++)
            cout << " ";
        cout << "/" << endl;
    }
}