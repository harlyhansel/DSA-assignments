BEGIN
//Input two numbers
PRINT"Enter first number (A):"
READ A
PRINT"Enter second number (B):"
READ B

//Swapping logic using a temporary variable
TEMP = A
A = B
B = TEMP

//Output the swapped numbers
PRINT"After swapping:"
PRINT"A = ",A
PRINT"B = ",B
END