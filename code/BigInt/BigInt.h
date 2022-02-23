typedef struct
{
    // 1 byte = 8 bits => 128 byte = 1024 bits
    char binary[128]; // stores bit patter of number entered
    char *bigInt; // points to dynamically allocated memory where array of digits is stored
    int count; // count of binary numbers
    char sign; // stores sign
    int len; // included because for many functions strlen was being called
}BigInt;

// function to scan input
int scanBI(BigInt *integer);
// function assign a BigInt
BigInt assign(char sign, char digits[]);
// finds binary of the number stored in charater array
void converting2binary(BigInt *integer);
// checks if the string contains all zeros('0')
int isAllZero(const char *ptr);

// initializes array binary inside BigInt to all zeros
void initializeBinary(BigInt *integer);
// prints the binary stored as bits in char in precise amount(not all 1024 bits)
void printBinary(BigInt integer);

// compares two BigInts
int compare(BigInt int1, BigInt int2);
// reduces initial zeros
void reduction(BigInt *integer);

// adds two BigInts
BigInt add(BigInt int1, BigInt int2);
// subtracts two BigInts
BigInt subtract(BigInt int1, BigInt int2);
// multiply two BigInts
BigInt multiply(BigInt int1, BigInt int2);
