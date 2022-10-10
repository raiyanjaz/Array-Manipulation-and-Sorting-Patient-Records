#include <iostream>
#include <string>

using namespace std;

int main () {
    char arr[100];
    char characterInput;
    
    cout << "Please input a character: ";
    cin >> characterInput;
    
    int number = characterInput - 32;
    char uppercase = number;
    cout << "The characterInput changes to " << uppercase << endl;
}