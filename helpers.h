/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

bool is_valid(int **puzzle, int row, int column, int digit);
void print_puzzle(int **puzzle);
bool solve_puzzle(int**puzzle);


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


// Generates a random number
int generate_random_number(){
    int random_number;
    random_number = (rand() % 8) + 1;
    return random_number;
}


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


// Generate a random sudoku puzzle // Puzzle size is 9 x 9

int** generate_puzzle(int no_of_digits){
    // Allocating space for a 9 x 9 matrix
    // From geeksforgeeks.com
    int** puzzle = (int**)malloc(9*sizeof(int*));
    int** checker = (int**)malloc(9*sizeof(int*));

    for (int i = 0; i < 9; i++){
        puzzle[i] = (int*)malloc(9*sizeof(int));
        checker[i] = (int*)malloc(9*sizeof(int));
    }

    for (int j = 0; j < 9; j++){
        for (int k = 0; k < 9; k++){
            puzzle[j][k] = 0;
            checker[j][k] = 0;
        }
    }


    int counter = 0;
    int row = generate_random_number();
    int column = generate_random_number();

    while (counter < no_of_digits){
        if (puzzle[row][column] != 0){
            row = generate_random_number();
            column = generate_random_number();
            continue;
        }

        int digit = generate_random_number();

        if (is_valid(puzzle, row, column, digit) == true){
            puzzle[row][column] = digit;
            counter++;
        }
    }
    return puzzle;
}


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


bool is_valid(int **puzzle, int row, int column, int digit){
    bool output = true;

    for (int i = 0; i < 9; i++){
        if (puzzle[row][i] == digit || puzzle[i][column] == digit){
            output = false;
        }
    }

    // (0, 3, 6)
    // (1, 4, 7)
    // (2, 5, 8)

    if (row == 0 || row == 3 || row == 6){
        for (int i = row; i < row + 3; i++){
            if (column == 0 || column == 3 || column == 6){
                for (int j = column; j < column + 3; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 1 || column == 4 || column == 7){
                for (int j = column - 1; j < column + 2; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 2 || column == 5 || column == 8){
                for (int j = column - 2; j < column + 1; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
        }
    }
    else if (row == 1 || row == 4 || row == 7){
        for (int i = row - 1; i < row + 2; i++){
            if (column == 0 || column == 3 || column == 6){
                for (int j = column; j < column + 3; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 1 || column == 4 || column == 7){
                for (int j = column - 1; j < column + 2; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 2 || column == 5 || column == 8){
                for (int j = column - 2; j < column + 1; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
        }
    }
    else if (row == 2 || row == 5 || row == 8){
        for (int i = row - 2; i < row + 1; i++){
            if (column == 0 || column == 3 || column == 6){
                for (int j = column; j < column + 3; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 1 || column == 4 || column == 7){
                for (int j = column - 1; j < column + 2; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
            else if (column == 2 || column == 5 || column == 8){
                for (int j = column - 2; j < column + 1; j++){
                    if (puzzle[i][j] == digit){
                        output = false;
                    }
                }
            }
        }
    }

    return output;
}


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


void print_puzzle(int **puzzle){

    printf("-------------------------------\n");

    for (int i = 0; i < 9; i++){
        printf("|");

        for (int j = 0; j < 9; j++){
            printf(" %d ", puzzle[i][j]);

            if ((j + 1) % 3 == 0){
                printf("|");
            }
        }
        printf("\n");

        if ((i + 1) % 3 == 0){
          printf("-------------------------------\n");
        }
    }
}


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


bool solve_puzzle(int**puzzle){
    for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++){

            if(puzzle[row][column] == 0){
                for(int pos = 1; pos <= 9; pos++){

                    if(is_valid(puzzle, row, column, pos) == true){
                        puzzle[row][column] = pos;
                        if(solve_puzzle(puzzle) != true){
                            puzzle[row][column] = 0;
                        }
                        else{
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
    // End of recursion as all boxes should now be assigned
    return true;
}