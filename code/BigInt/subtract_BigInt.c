#include"BigInt.h"
#include<string.h>
#include<stdlib.h>

BigInt subtract(BigInt int1, BigInt int2)
{
    BigInt retval; // creating a variable to return
    int BIcmp = compare(int1, int2);
    if(int1.sign == int2.sign)
    {
        // if signs are equal
        // maximum size of addition of two numbers = length of largest number + 1
        // for checking if any one of the numbers is zero
        int iszero1 = isAllZero(int1.bigInt);
        int iszero2 = isAllZero(int2.bigInt);
        if(iszero1 && iszero2)
        {
            retval.len = 1;
            retval.bigInt = (char *) malloc(2 * sizeof(char));
            *(retval.bigInt) = '0';
            *(retval.bigInt + 1) = '\0';
            retval.sign = '+';

        }
        else if(iszero1)
        {
            // if int1 is zero then int2 is retval
            retval.len = int2.len;
            retval.bigInt = (char *)malloc((int2.len + 1) * (sizeof(char)));
            strcpy(retval.bigInt, int2.bigInt);
            *(retval.bigInt + int2.len) = '\0';
            (int2.sign == '+')? (retval.sign = '-') : (retval.sign = '+');
        }
        else if(iszero2)
        {
            // is int2 is zero then int1 is retval
            retval.len = int1.len;
            retval.bigInt = (char *)malloc((int1.len + 1) * (sizeof(char)));
            strcpy(retval.bigInt, int1.bigInt);
            *(retval.bigInt + int1.len) = '\0';
            retval.sign = int1.sign;
        }
        else if(BIcmp >= 0)
        {
            
            // allocating memory one for '\0'
            retval.sign = int1.sign;
            retval.len = int1.len;
            retval.bigInt = (char *)malloc((int1.len + 1)*(sizeof(char)));
            strcpy(retval.bigInt, int1.bigInt);
            *(retval.bigInt + int1.len) = '\0';
            int part1, part2, i, subtraction,borrow = 0;
            for(i = 0; i < int2.len; i++)
            {
                // taking two char from the end and converting to int
                part1 = *(int1.bigInt + int1.len - 1 - i) - 48;
                part2 = *(int2.bigInt + int2.len - 1 - i) - 48;
                // performing subtraction
                subtraction = part1 - part2 - borrow;
                // if subtraction < 0 then borrow = 1
                if(subtraction < 0)
                {
                    borrow = 1;
                    subtraction = subtraction + 10;
                    *(retval.bigInt + int1.len - 1 - i) = subtraction + 48;
                }
                else
                {
                    borrow = 0;
                    *(retval.bigInt + int1.len - 1 - i) = subtraction + 48;
                }
            }
            // if carry is still 1 then add to next position
            for(;i < int1.len && borrow; i++)
            {
                part1 = *(int1.bigInt + int1.len - 1 - i) - 48;
                subtraction = part1 - borrow;
                if(subtraction < 0)
                {
                    borrow = 1;
                    subtraction = subtraction + 10;
                    *(retval.bigInt + int1.len - 1 - i) = subtraction + 48;
                }
                else
                {
                    borrow = 0;
                    *(retval.bigInt + int1.len - 1 - i) = subtraction + 48;
                }
            }
        }
        else
        {
            // as above algorithm is used only when int1 >= int2
            // inputs are swapped while passing
            char final_sign;
            (int2.sign == '+') ? (final_sign = '-') : (final_sign = '+');
            int1.sign = '+';
            int2.sign = '+';
            retval = subtract(int2, int1);
            retval.sign = final_sign;
        }
    }
    else
    {
        // When sign's are different it can be simplified as addition
        // Comparing BigInt
        int final_sign = int1.sign;
        int1.sign = '+';
        int2.sign = '+';
        retval = add(int1, int2);
        retval.sign = final_sign;
    }
    // converting to binary
    converting2binary(&retval);
    // checking overflow
    if(retval.count > 1024)
    {
        free(retval.bigInt);
    }
    return retval;
}