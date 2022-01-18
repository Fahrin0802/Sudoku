Sudoku Puzzle Solver
•	This was a project I made to self-learn the C programming language. 
•	The application can generate a 9 x 9 sudoku puzzle with a certain number of digits (based on user input). 
o	To accomplish this, I utilized double pointers and dynamic memory allocation to make the program better in terms of space complexity (Ensured that a copy of the matrix is not created each time the puzzle was called by other functions).
•	Afterwards, the program can solve the puzzle (if the user requests so) by using a backtracking algorithm
o	I implemented the backtracking algorithm using recursion

Challenges
•	The generate_puzzle() function can only generate the 9 x 9 matrix with 0-20 digits. 
o	The user cannot generate the puzzle with say 70 (out of 81) known digits
o	This is because, the generate_puzzle () generates a puzzle based on basic sudoku rules, but this does not ensure that the puzzle will be solvable. 
o	To get around this, I need to check if the puzzle is solvable after generating a puzzle each time. But this makes the program very slow (high time complexity).
o	I am still figuring out a more efficient way to do this
•	The scanf() sometimes did not prompt the user for input and I am still trying to figure out the reason

Future directions
•	Modify the program so that it can generate N x N sudoku puzzles (based on users’ choice of N)
•	Modify the program so that a puzzle generated with any number of digits (between 0 to N) is solvable
•	Look for the reason why scanf() sometimes bugs out
•	Link the program to an external interface and possibly create a game application

Other information
•	I kept the helper functions in a separate c file
•	The function prototypes are kept in a user created header file

