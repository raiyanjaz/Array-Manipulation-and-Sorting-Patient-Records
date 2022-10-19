# Array Manipulation and Sorting Patient Records

## caseConversion.cpp problem:
    Write a program that takes a character from terminal as input, and provide one of the following three outputs depending on the input character:
        1. Input is a lower-case letter from the English alphabet: The program should output the    corresponding upper-case letter.
        2. Input is an upper-case letter from the English alphabet: The program should output the corresponding lower-case letter.
        3. Input is anything other than an upper or lower-case letter from the English alphabet: The program should echo the input character, i.e., output exactly the character that was input

## diamond.cpp problem:
    1) Write a program that asks for a positive integer input to determine the size of the diamond and print out the diamond accordingly.
    2) The diamond is created using forward (/) and backward slashes (\); the height and width of the diamond are twize the input size, i.e., a diamond of size 5 would have a height of 10 lines and a width of 10 characters.

## largeSum.cpp problem:
    1) Write a program that takes two positive integer inputs as command-line arguments and outputs the sum of the two integers. For this program the inputs may be larger than can be stored in a native datatype.
    2) Test your completed program with various command line arguments. In particular, try these test cases:
    | Input 1                   |  Input 2                   |
    |:-------------------------:|:--------------------------:|
    | 1                         |  1                         |
    | 20                        |  95                        |
    | 2529382928                |  438283832                 |
    | 9999999999                |  1                         |
    | 9223372036854775808       |  9223372036854775808       |
    | 9223372036854775808       | 486127654835486515383218192|
    | 1486515347865138654821865 |  348621896435183186        |

    Note: Response file answering the inputs is called "largeSum response file".

## bubbleSort problem:
    You are required to sort patient records by a specified category. The patient records that will be sorted are given by the following table:
    | Age   | 50       | 22       | 22       | 89       | 15       | 16       | 22       | 32       | 15       | 66       |
    | ID    | 10854893 | 10983922 | 98333894 | 57290888 | 14899822 | 79278282 | 44293822 | 62911023 | 28399020 | 33212322 |
    | First | allison  | michael  | michael  | johnny   | sabrina  | helen    | ignacio  | melissa  | hassan   | melody   |
    | Last  | pratt    | xiao     | barkley  | wu       |sappal    | mcdonald | garza    | tran     | nahas    | baker    |
    | Sex   | f        | m        | m        | m        | f        | f        | m        | f        | m        | f        |

    1. The program must be capable of desensitizing the inpur character case. 
    2. The program must also be able to do any necessart error checks to account for invalid user input.
    3. The sorted patient records must be outputed to the terminal in a tabular form.
    4. When sorting by a category, it must account for values that are the same and implement a tie-breaking algorithm to accurately sort the data.