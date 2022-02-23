#include"BigInt.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"..\utilities\utililies.h"


void converting2binary(BigInt *integer)
{
    initializeBinary(integer);
    integer->count = 0;
    int carry = 0, division = 0, start = 0, current;
    int position = 0, binary_index = 0;
    // index len will have '\0' so stop at len
    char *ptr = (char *) malloc((integer->len + 1 )*sizeof(char));
    strcpy(ptr,integer->bigInt);
    *(ptr + integer->len) = '\0';
    // checking if input is zero
    if(!(isAllZero(ptr)))
    {
        while(!(isAllZero(ptr)) && integer->count < 1025)
        {
            carry = 0;
            // this loop divides the whole number
            for(int i = start; i < integer->len; i++)
            {
                current = *(ptr + i) + carry * 10 - 48; 
                carry =  current % 2;
                division = current / 2;
                *(ptr + i) = division + 48;
                if(division == 0 && i == start)
                {
                    start++;
                }
            }
            integer->count++; // increaing count;
            if(integer->count < 1025)
            {
                // changes 1 - 8 th bit of char in char array
                if(position < 8)
                {
                    integer->binary[binary_index] = modifyBit((integer->binary[binary_index]),position, carry);
                    position++;
                }
                else
                {
                    // if all position are changed then move to next char
                    position = 0;
                    binary_index++;
                    integer->binary[binary_index] = modifyBit((integer->binary[binary_index]), position, carry);
                    position++;
                }
            }
            else
            {
                // as this is a 1024 bit implementation
                printf("Error: Overflow detected\n");
            }
        }
    }
    else
    {
        integer->binary[0] = modifyBit((integer->binary[0]),position, carry);
        integer->count++;
    }
    //freeing ptr as its memory is no longer needed
    free(ptr);
}