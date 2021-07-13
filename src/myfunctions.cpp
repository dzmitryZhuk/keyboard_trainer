#include "myfunctions.h"

long long power_(long long number, long long pow)
{
    if (!pow)
        return 1;
    else
        return pow > 1 ? number * power_(number, pow - 1) : number;
}

const char* MyItoa(long long number)
{
    long long size = 0, temp = number;
    do
    {
        size++;
        temp /= 10;
    } while (temp > 0);
    char* str = (char*)malloc(sizeof(char) * size + 1);
    temp = size;
    for (int i = 0; i < size; i++)
    {
        long long asd = (number / power_(10, temp - 1));
        str[i] = '0' + asd;
        number = number - (asd * power_(10, temp - 1));
        temp--;
    }
    *(str + size) = '\0';
    return str;
}


const char* MyItoa(int number)
{
    MyItoa((long long )number);
}
