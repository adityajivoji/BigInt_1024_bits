// BigInt Implementation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include".\utilities\utililies.h"
#include".\BigInt\BigInt.h"

int main(void)
{
    // declaring and initializing int1
    BigInt int1 = assign('+',"472934246");
    BigInt int2;
    //scanning int2
    printf("Enter a Number: ");
    scanBI(&int2);
    // using add function
    BigInt added = add(int1, int2);
    printf("Addition = %c",added.sign);
    puts(added.bigInt);
    //using subtract function
    BigInt subtracted = subtract(int1, int2);
    printf("subtraction = %c",subtracted.sign);
    puts(subtracted.bigInt);
    // using multiply function
    BigInt multiplied = multiply(int1, int2);
    printf("multiplication = %c",multiplied.sign);
    puts(multiplied.bigInt);
}
