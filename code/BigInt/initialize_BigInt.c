#include"BigInt.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int scanBI(BigInt *integer)
{
    int success;
    // used array to scan and the excess memory is given back
    char digits[309];
    scanf("%c",&(integer->sign)); // scanning sign
    gets(digits);
    integer->len = strlen(digits); // total number of digits
    // bigint must point to char array of size len + 1
    // + 1 for storing '\0'
    integer->bigInt = (char *) calloc((integer->len)+1, sizeof(char));
    strcpy(integer->bigInt,digits);
    converting2binary(integer);
    (integer->count < 1025) ? (success = 1) : (success = 0);
    return success;

}

BigInt assign(char sign, char digits[])
{
    BigInt retval;
    int success;
    retval.sign = sign;
    retval.len = strlen(digits); // total number of digits
    // bigint must point to char array of size len + 1
    // + 1 for storing '\0'
    retval.bigInt = (char *) calloc((retval.len)+1, sizeof(char));
    strcpy(retval.bigInt,digits);
    converting2binary(&retval);
    (retval.count < 1025) ? (success = 1) : (free(retval.bigInt));
    return retval;
}
