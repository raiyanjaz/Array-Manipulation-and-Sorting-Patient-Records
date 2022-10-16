#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

int main() {
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

    char category[5][6] = {"Age", "ID", "First", "Last", "Sex"};
    
    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";

    int i = 0;
    char userInput[i]; 
    char input = cin.get(); // Stores the first character that user inputs
    
    while (input != '\n') { // While statement that stores the first character into the first element of char array userInput and does the same for sequential characters
        userInput[i] = input;
        i++;
        input = cin.get();
    }   
    i--;

    

    int userInputValue;

    if (userInput[0] >= 97 && userInput[0] <= 122) { // If statement that changes the first element in userInput into a capital letter
        userInputValue = userInput[0];
        userInputValue -= 32;
        userInput[0] = userInputValue;
    }

    for (int k = 1; k <= i; k++) { // For loop that changes every element in userInput after the first element into a lowercase value
        if (userInput[k] >= 65 && userInput[k] <= 90) {
            userInputValue = userInput[k];
            userInputValue += 32;
            userInput[k] = userInputValue;
        }
    }

    if (userInput[0] == 73) { // If statement that ensures any input of ID is shown as ID
            userInputValue = userInput[1];
            userInputValue -= 32;
            userInput[1] = userInputValue;
    }

    int caseNumber;
    
    switch (i) {
        case 1: // If user inputs ID
            caseNumber = 2;
            break;
        case 2: // If user inputs Age or Sex
            if (userInput[0] = 65)
                caseNumber = 1;
            break;
            if (userInput[0] = 83)
                caseNumber = 3;
            break;
        case 3: // If user inputs Last
            caseNumber = 4;
            break;
        case 4: // If user inputs First
            caseNumber = 5;
            break;
    }

    cout << "Case " << caseNumber << ", sorting by ";
    for (int k = 0; k <= i; k++)
        cout << userInput[k];
        if (caseNumber == 4 || caseNumber == 5)
            cout << " Name";
    cout << ".";

    // PART 3/4: Sorting patient records





    // PART 2: Outputting patient records to terminal in tabular form




    return 0;
}