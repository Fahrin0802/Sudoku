#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


int main(){
    // Used as seed for random number generator
    srand(time(NULL));

    int no_of_digits = -1;

    // Get a valid input from user
    while (no_of_digits < 0 || no_of_digits > 15){
        printf("Please input the number of digits (0-15) with which the puzzle would be initiated\n");
        scanf("%d", &no_of_digits);
        getchar();
    }

    // Generate i.e. allocate space for a random 9 x 9 sudoku matrix
    int** puzzle = generate_puzzle(no_of_digits);

    // Printing the random sudoku matrix
    printf("The puzzle is given as follows\n");
    print_puzzle(puzzle);

    // Ask user whether to solve the puzzle or not
    printf("Please enter 's' to get solved puzzle\n");
    printf("Please enter 'e' to exit program\n");

    char input;
    scanf("%c", &input);
    getchar();

    // Solve the puzzle and print solution
    if(input == 's'){
        bool final = solve_puzzle(puzzle);
        printf("The solved puzzle is given below:\n");
        print_puzzle(puzzle);
    }

    return 0;
}