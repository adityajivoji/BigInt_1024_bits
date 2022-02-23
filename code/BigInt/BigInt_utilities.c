#include"BigInt.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"..\utilities\utililies.h"

void reduction(BigInt *integer)
{
    if(integer->len > 2)
    {
        int i = 0;
        while(*(integer->bigInt + i) == '0')
        {
            i++;
        }
        // creating a shorter array
        char *temp = (char *) malloc((integer->len - i) * sizeof(char));
        strcpy(temp, (integer->bigInt + i));
        free(integer->bigInt);
        integer->bigInt = temp;
    }
}

int isAllZero(const char *ptr)
{
    int flag = 1;
    int len = strlen(ptr);
    for(int i = 0; i < len; i++)
    {
        if(*(ptr + i) != '0')
        {
            flag = 0; // if some char is not 0 then flag = 0 => isAllZero is False
        }
    }
    return flag;
}

void initializeBinary(BigInt *integer)
{
    // initializes every char to '\0'
    for(int i = 0; i < 128; i++)
    {
        integer->binary[i] = 0;
    }
}

void printBinary(BigInt integer)
{
    // this gives the starting point to print
    // as the binary is stored in reverse order we have to calculate location of last modified bit
    int binary_index = (integer.count - 1) / 8;
    int position = (integer.count - 1) % 8;
    int i = 0;
    while(i < integer.count)
    {
        printf("%d",getBit(integer.binary[binary_index],position));
        position--;
        if(position < 0)
        {
            binary_index--;
            position = 7;
        }
        i++;
    }
    printf("\n");
}



int compare(BigInt int1, BigInt int2)
{
    // if int1 > int2 return 1
    // if int1 == int2 return 0
    // if int2 < int2 return -1
    int retval;
    int stcmp;
    if(int1.len > int2.len)
    {
        retval = 1;
    }
    else if(int1.len < int2.len)
    {
        retval = -1;
    }
    else
    {
        stcmp = strcmp(int1.bigInt, int2.bigInt);
        if(stcmp > 0)
        {
            retval = 1;
        }
        else if(stcmp < 0)
        {
            retval = -1;
        }
        else
        {
            retval = 0;
        }

    }
    return retval;
}
