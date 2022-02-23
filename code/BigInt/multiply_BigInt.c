#include"BigInt.h"
#include<string.h>
#include<stdlib.h>

BigInt multiply(BigInt int1, BigInt int2)
{
    BigInt retval; // creating a variable to return
    char final_sign; // sign assigned after all the computation is done
    (int1.sign == int2.sign) ? (final_sign = '+') : (final_sign = '-');
    int1.sign = '+';
    int2.sign = '+';
    // maximum size of addition of two numbers = length of largest number + 1
    // checking if any one of the inputs is empty
    int iszero1 = isAllZero(int1.bigInt);
    int iszero2 = isAllZero(int2.bigInt);
    if(iszero1 || iszero2)
    {
        final_sign = '+';
        retval.len = 1;
        retval.bigInt = (char *)malloc(2 * (sizeof(char)));
        *(retval.bigInt) = '0';
        *(retval.bigInt + 1) = '\0';
    }
    else if(int1.len >= int2.len)
    {
        // retval stores the final value
        retval.bigInt = (char *)calloc(2,(sizeof(char)));
        // used to free the previously allocated memory for retval
        char * retvalFree;
        retval.len = 1;
        *(retval.bigInt) = '0';
        *(retval.bigInt + 1) = '\0';
        retval.sign = '+';
        // helper to calculate the multiplication
        BigInt  temp;
        temp.sign = '+';
        temp.len = 1;
        temp.bigInt = (char *)calloc(2,(sizeof(char)));
        *(temp.bigInt) = '0';
        *(temp.bigInt + 1) = '\0';
        // helper to calculate the multiplication
        BigInt temp2;
        temp2.sign = '+';
        temp2.len = 1;
        temp2.bigInt = (char *)calloc(2,(sizeof(char)));
        *(temp2.bigInt) = '0';
        *(temp2.bigInt + 1) = '\0';
        int part1, part2, i, addition,carry = 0;
        int j;
        // used to free the previously allocated memory for temp2
        char * tempFree;
        // algorithm
        // abcd * xyz = 0 + add z times abcd + add y times abcd0 + add x times abcd00
        //adcd0 = abcd * 10
        //adbcd00 = adcd * 100
        for(i = 0; i < int2.len; i++)
        {
            // for every element in int2 add corresponding number to retval
            // allocating space for abcd, abcd0 and abcd00 .....
            // amount of space needed increases by 1 for each iteration
            temp.bigInt = (char *) realloc(temp.bigInt, int1.len + 1 + i);
            temp.len = int1.len + i;
            strcpy(temp.bigInt, int1.bigInt);
            *(temp.bigInt + int1.len + i) = '\0';
            // creating abcd, abcd0 and abcd00 .....
            for(j = 0; j < i; j++)
            {
                *(temp.bigInt + int1.len + i - 1 - j) = '0';
            }
            // number of times the corresponding number should be added
            part2 = *(int2.bigInt + int2.len - 1 - i) - 48;
            temp2.len = 1;
            free(temp2.bigInt);
            temp2.bigInt = (char *)calloc(2,(sizeof(char)));
            *(temp2.bigInt) = '0';
            *(temp2.bigInt + 1) = '\0';
            // storing result of addition to temp2
            for(j = 0; j < part2; j++)
            {
                // add creating new memory and assigns to temp2.bigInt
                //hence prev memory address is stored in a variable to free it up later
                tempFree = temp2.bigInt;
                temp2 = add(temp2,temp);
                // freeing up unwanted memory
                free(tempFree);
            }
            retvalFree = retval.bigInt;
            // adding to retval as this is the result
            retval = add(retval,temp2);
            // freeing up unwanted space
            free(retvalFree);
        }
        // freeing up memory allotes to temp
        free(temp.bigInt);
    }
    else
    {
        // passing BigInt with larger magnitude first
        retval = multiply(int2,int1);
    }
    // as performing addition many times in the algorithm
    // this may result in many unsignificant zeros in the beginning
    // for example 00000000237233
    // reduction coverts it to 237233
    reduction(&retval);
    // applying final sign
    retval.sign = final_sign;
    converting2binary(&retval);
    return retval;
}
