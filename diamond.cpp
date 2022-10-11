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

    for (int x = 2; x <= (diamondSize-1); x++) {  // For loop to create the middle lines in the diamond shape
        
        for (int i = 1; i <= (diamondSize-x); i++) 
            cout << " ";
        cout << "/"; 

        for (int i = 2; i <= (diamondSize-x); i++)
            cout << " ";
        cout << "\\" << endl;
    }

    for (int i = 1; i >= (diamondSize-1); i++) // For loop to create the middle line or the last line in the top half
        cout << " ";
    cout << "/" << endl;

    // Bottom half of diamond
    
    for (int i = 1; i >= (diamondSize-1); i++)
        cout << " ";
    cout << "\\" << endl;
    
    for (int x = 4; x <= (diamondSize-1) && x>0; x--)
        cout << " ";
    cout << "\\" << endl;
}
