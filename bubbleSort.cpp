#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

// Provided arrays and constants

const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
const int ID_LENGTH = 8;
unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt", "xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient

int main() {

   // PART 1: Select a primary sorting category from user input 

    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";

    int count = 0;
    char userInput[count]; 

    char category[5][6] = {"age", "id", "sex", "last", "first"}; // Used this 

    bool validInputCheck = true;

    while (validInputCheck) {

        char input = cin.get(); // Stores the first character that user inputs
        count = 0; 
    
        while (input != '\n') { // While statement that stores the first character into the first element of char array userInput and does the same for sequential characters
            userInput[count] = input;
            count++;
            input = cin.get();
        }
        userInput[count] = 0;

        int userInputValue;

        if (userInput[0] >= 65 && userInput[0] <= 90) {
            userInputValue = userInput[0];
            userInputValue += 32;
            userInput[0] = userInputValue;
        }

        int compare;
        int check = 0;
        while (check < 5) {
            compare = strcmp(userInput, category[check]);
            if (compare > 0 || compare < 0) {
                check++; 
            } else if (compare == 0) {
                validInputCheck = false;
                break;
            }
        }
        if (check == 5) {
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
            cin.clear(); 
        }  
    }

    // PART 3/4: Sorting patient records

    bool tiebreaker;

    if (strcmp(userInput , category[0])) { // Checks if userInput is equal to age from the 2D category array
        cout << "Case 1, sorting by Age";

        for (int i = 0; i < NUM_PATIENTS - 1; i++) {
            for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {   
                for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Tiebreaker is turned on when the first character of first name is greater than the next one
                    if (firstName[i][i3] > firstName[i+1][i3]) {
                        tiebreaker = true;
                        break;
                    } else if (firstName[i][i3] < firstName[i+1][i3]) { // Tiebreaker is turned off when the first character of first name is less than the next one
                        tiebreaker = false;
                        break;
                    }
                } 
                if (age[i2] > age[i2+1] || (age[i2] == age[i2+1] && tiebreaker)) { 
                    int temp = age[i2]; // Orders Age in ascending order
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;

                    char temp2[NUM_PATIENTS];  // Orders Sex according to Age
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                    
                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to Age
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }  
                
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to Age
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }       
                }  
            }
        }  
    }

    if (strcmp(userInput , category[1])) { // Sorting for ID
        cout << "Case 2, sorting by ID";

        for (int i = 0; i < NUM_PATIENTS - 1; i++) {
            for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if ((id[i2][0] - '0') > (id[i2+1][0] - '0') || ((id[i2][0] - '0') == (id[i2+1][0] - '0') && tiebreaker)) { 
                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID in increasing order
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }       
                    
                    int temp = age[i2]; // Orders Age according to ID
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;
                
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to ID
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to ID
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }       
                                
                    char temp2[NUM_PATIENTS];  // Orders sex according to ID
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                }    
            }
        }
    }
    
    if (strcmp(userInput , category[2])) { // Sorting for Sex
        cout << "Case 3, sorting by Sex";

        for (int i = 0; i < NUM_PATIENTS - 1; i++) {
            for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if ((sex[i2] - '0') > (sex[i2+1] - '0') || ((sex[i2] - '0') == (sex[i2+1] - '0') && tiebreaker)) { 
                    char temp2[NUM_PATIENTS];  // Orders Sex in alphabetical order
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                    
                    int temp = age[i2]; // Orders Age according to Sex
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;

                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to Sex
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }  
                
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to Sex
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to Sex
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }                
                }    
            }
        }
    }
    
    if (strcmp(userInput , category[3])) { // Sorting for Last Name
        cout << "Case 4, sorting by Last Name";

        for (int i = 0; i < NUM_PATIENTS - 1; i++) {
            for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if ((lastName[i2][0] - '0') > (lastName[i2+1][0] - '0') || ((lastName[i2][0] - '0') == (lastName[i2+1][0] - '0') && tiebreaker)) { 
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name in alphabetical order
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }                    
            
                    char temp2[NUM_PATIENTS];  // Orders Sex according to Last Name
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                    
                    int temp = age[i2]; // Orders Age according to Last Name
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;

                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to Last Name
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }  
                
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name according to Last Name
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }               
                }    
            }
        }
    }

    if (strcmp(userInput , category[4])) { // Sorting for First Name
        cout << "Case 5, sorting by First Name";

        for (int i = 0; i < NUM_PATIENTS - 1; i++) {
            for (int i2 = 0; i2 < NUM_PATIENTS - 1; i2++) {
                if ((firstName[i2][0] - '0') > (firstName[i2+1][0] - '0')) { 
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders First Name in alphabetical order
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = firstName[i2][i3];
                        firstName[i2][i3] = firstName[i2+1][i3];
                        firstName[i2+1][i3] = temp2[i2][i3];
                    }                   
                    
                    for (int i3 = 0; i3 < MAX_NAME_LENGTH; i3++) { // Orders Last Name according to First Name
                        char temp2[NUM_PATIENTS][MAX_NAME_LENGTH];
                        temp2[i2][i3] = lastName[i2][i3];
                        lastName[i2][i3] = lastName[i2+1][i3];
                        lastName[i2+1][i3] = temp2[i2][i3];
                    }                    
            
                    char temp2[NUM_PATIENTS];  // Orders Sex according to First Name
                    temp2[i2] = sex[i2];
                    sex[i2] = sex[i2+1];
                    sex[i2+1] = temp2[i2];
                    
                    int temp = age[i2]; // Orders Age according to First Name
                    age[i2] = age[i2+1];
                    age[i2+1] = temp;

                    for (int i3 = 0; i3 < ID_LENGTH + 1; i3++) { // Orders ID according to First Name
                        char temp2[NUM_PATIENTS][ID_LENGTH+1];
                        temp2[i2][i3] = id[i2][i3];
                        id[i2][i3] = id[i2+1][i3];
                        id[i2+1][i3] = temp2[i2][i3];
                    }                 
                }    
            }
        }
    }
    
    // PART 2: Outputting patient records to terminal in tabular form

    cout << setw(12) << "Age: "; // Prints out the Age row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << age[i];
    cout << "" << endl;

    cout << setw(12) << "ID: "; // Prints out the ID row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << id[i];
    cout << "" << endl;

    cout << setw(10) << "First Name: "; // Prints out the First Name row and all its values with a fixed width of 10 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << firstName[i];
    cout << "" << endl;

    cout << setw(12) << "Last Name: "; // Prints out the Last Name row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << lastName[i];
    cout << "" << endl;

    cout << setw(12) << "Sex: "; // Prints out the Sex row and all its values with a fixed width of 12 using a for loop
    for (int i = 0; i < 10; i++)
        cout << setw(10) << sex[i];
    cout << "" << endl;

    return 0;
}