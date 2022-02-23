# BigInt Implementation

The project focuses on implementing a 1024 bit (128 byte) integer

to understand make changes to main.c

- run "make compile" in the terminal to compile
- run "make run" to run
- run "make cnr" to compile and run
  
> Note: make sure that make is installed

## The structure of a BigInt contain 
-	a char pointer pointing to the inserted digits in decimal system
-	a char to store the sign of the number
-	an array of char of 128 elements
    - each char has 8 bytes 
    - => 128 bytes can store 1024 bits
    - Each bit has position in range [0-7]
    - A modifyBit function is used to change bit value at a specific position
    - Whenever all 8 bits of one char a used the next bits are stored in the next char index
    - This allows efficient use of memory to store bit values
    - Note: The BigInt created is suitable for both negative and positive values but does not use 2’s complement method to represent it. Instead it uses the sign char to store the sign
-	int count stores the number of bits required to store the number in binary
-	int len stores the number of decimal digits required to represent the number. This was used to avoid usage of strlen function many times.

## Functions Used
1.	scanBI function – This function is used to scan a BigInt from the user. syntax for using scanBI is scanBI(&bigint1);
This scan the digits and sign, also generated binary for this number if the number has more than 1024 bits the  “Error: Overflow Detected” message is printed;
2.	assign function – This function is used to assign value to BigInt while programming. trying to make it similar to fundamental types (int x = 3;)
The syntax for using it is “BigInt  y = assign(‘+’, “38103”);”
3.	add function – must pass two parameters, the two BigInt’s that are to be added. returns a BigInt. Addition happens on decimal representation. After addition binary of the result is calculated and overflow is checked. If overflow is detected then integer.bigInt is freed.
Depending on the sign and magnitude of the numbers passed, they are passed through other function to calculate the result. For ex. if sign are opposite then subtract function is used inside add.
4.	subtract function – must pass two parameters the two BigInt’s that are to be subtracted. Returns a BigInt. Subtraction happens on decimal representation. After subtraction number is converted to binary and overflow is checked. if overflow is detected the integer.bigInt is freed. 
Depending on the sign and magnitude of the numbers passed, they are passed through other functions to calculate the result. For ex. if sign are opposite then resulting is sign is calculated and numbers are passed through add function.
5.	Multiplication – must pass two parameters, the two BigInt’s that are to be added. Returns a BigInt. Multiplication happens on decimal representation. After Multiplication binary of the result is calculated and overflow is checked. If overflow is detected then integer.bigInt is freed. 

## Helper functions used
1.	converting2binary – takes input of BigInt pointer converts the decimal of a number stored in char type into its binary representation. Detects Overflows. Assigns BigInt.count.
2.	isAllZero – this function takes a char pointer. checks if all the values stored in the pointed memory is zero. if all are zero then it returns 1 else 0.
3.	modifyBit – this function takes input of char whose bits are to be modified, a position input and the value of the bit to which it will be changed. Returns the modified char.
4.	initializeBinary – initializes all the array elements of BigInt.binary to zero.
5.	printBinary – prints BigInt.binary with the help of count precise number of bits are printed instead of the whole 1024 bits.
6.	getBit – gets the bit value at a particular position of the char data type.
7.	compare – compares two BigInts returns 1 if first > second, 0 if equal, -1 otherwise
8.	reduction – this function reduces the number of extra zeros that were assumed while adding, subtracting and multiplying.

## Few points to mention
1.	Some basic cases such as 0 as a input(s) are handled first.
2.	Many modification to the input of add, subtract and multiply function are made and passed through required function to avoid writing of same code many times. 
3.	For addition the common form is x + y where x and y are positive. –x + -y is re-written as –(x + y) and x + y is now calculated and ‘-‘ sign is allotted to the result. Similarly x + -y and –x + y is the input then x and y are passed through subtract function after changing their signs.
4.	Same is the case with subtraction different cases call for different function.
5.	In multiply function sign of result is calculated from the input.

## Limitations of this Implementation;
1.	Cannot assign values directly to BigInt data type variables as it is possible for fundamental data types. Can assign values directly only with the help of assign function.
2.	User has to provide sign of number every time it is scanned. 
Input example +4289293 or -429427

## Contributers
- Aditya Jivoji