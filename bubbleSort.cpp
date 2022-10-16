#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

int main() 
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt", "xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient

    // PART 1: Select a primary sorting category from user input

    const int N = 5;
    char userInput[N];
    int varAfterInput;
    
    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";
    
    char input = cin.get();
    int i = 0;
    
    while (input != '\n' && i < N-1) {
        userInput[i] = input;
        i++;
        input = cin.get();
    }

    userInput[i] = 0;
    varAfterInput = 1;
    
    const int inputLength = strlen(userInput);
    int userInputValue;

    cout << inputLength << endl;

    for (int i = 0; i <= inputLength - 1; i++) {
        if (userInput[i] >= 97 && userInput[i] <= 122)
            userInputValue = userInput[i];
            int temp = userInputValue - 32;
            userInput[i] = temp;
    }

    for ()
    


    cout << "You inputed: " << userInput << endl;
    
    /*
    if (strcmp(userInput, idCode) == 0)
        cout << "hello";
    */





    // PART 3/4: Sorting patient records





    // PART 2: Outputting patient records to terminal in tabular form




    return 0;
}