#include"BigInt.h"
#include<string.h>
#include<stdlib.h>


BigInt add(BigInt int1, BigInt int2)
{
    BigInt retval; // creating a variable to return
    if(int1.sign == int2.sign)
    {
        // if signs are equal
        retval.sign = int1.sign;
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

        }
        else if(iszero1)
        {
            // if int1 is zero then int2 is retval
            retval.len = int2.len;
            retval.bigInt = (char *)malloc((int2.len + 1) * (sizeof(char)));
            strcpy(retval.bigInt, int2.bigInt);
            *(retval.bigInt + int2.len) = '\0';
        }
        else if(iszero2)
        {
            // is int2 is zero then int1 is retval
            retval.len = int1.len;
            retval.bigInt = (char *)malloc((int1.len + 1) * (sizeof(char)));
            strcpy(retval.bigInt, int1.bigInt);
            *(retval.bigInt + int1.len) = '\0';
        }
        else if(int1.len >= int2.len)
        {
            // allocating memory assuming 1 byte extra for carry and one for '\0'
            retval.bigInt = (char *)malloc((int1.len + 2)*(sizeof(char)));
            retval.len = int1.len + 1;
            // copying from 1st index as 0th will hold the carry
            strcpy((retval.bigInt + 1), int1.bigInt);
            *(retval.bigInt + int1.len + 1) = '\0';
            int part1, part2, i, addition,carry = 0;
            for(i = 0; i < int2.len; i++)
            {
                // taking two char from the end and converting to int
                part1 = *(int1.bigInt + int1.len - 1 - i) - 48;
                part2 = *(int2.bigInt + int2.len - 1 - i) - 48;
                // performing addition
                addition = part1 + part2 + carry;
                // if addition > 9 then carry = 1
                if(addition > 9)
                {
                    carry = 1;
                    addition = addition - 10;
                    *(retval.bigInt + int1.len - i) = addition + 48;
                }
                else
                {
                    carry = 0;
                    *(retval.bigInt + int1.len - i) = addition + 48;
                }
            }
            // if carry is still 1 then add to next position
            for(;i < int1.len && carry; i++)
            {
                part1 = *(int1.bigInt + int1.len - 1 - i) - 48;
                addition = part1 + carry;
                if(addition > 9)
                {
                    carry = 1;
                    addition = addition - 10;
                    *(retval.bigInt + int1.len - i) = addition + 48;
                }
                else
                {
                    carry = 0;
                    *(retval.bigInt + int1.len - i) = addition + 48;
                }
            }
            // if carry is still 1 then giving 1
            carry == 1 ? (*(retval.bigInt) = 49) : (*(retval.bigInt) = 48);
        }
        else
        {
            // as above algorithm is used only when int1 >= int2
            // inputs are swapped while passing
            retval = add(int2,int1);
        }
    }
    else
    {
        // When sign's are different it can be simplified as subtraction
        // Comparing BigInt
        int BIcmp = compare(int1, int2);
        char final_sign;
        if(BIcmp == 1)
        {
            // if int1 > int2
            final_sign = int1.sign;
            int1.sign = '+';
            int2.sign = '+';
            // bigger madnitude goes first
            retval = subtract(int1, int2);
            retval.sign = final_sign;
        }
        else
        {
            // if int2 > int1
            final_sign = int2.sign;
            int1.sign = '+';
            int2.sign = '+';
            // bigger magnitude goes first
            retval = subtract(int2, int1);
            retval.sign = final_sign;
        }
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