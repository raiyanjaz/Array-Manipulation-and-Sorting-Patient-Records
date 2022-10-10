#include <iostream>

using namespace std;

int main () {
    int diamondSize;

    cout << "How large do you want the diamond to be: ";
    cin >> diamondSize;

    for (int i = 1; i <= (diamondSize-1); i++) 
        cout << " ";  
    cout << "/\\" << endl;

    for (int i = 2; i <= (diamondSize-1); i++)
        cout << " ";
    cout << "/" << endl;

    for (int i = (diamondSize-1); i <= (diamondSize-1); i++)
        cout << " ";
    cout << "/" << endl;   
}