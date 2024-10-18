#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string s=get_string("heell");
    int temp[8];
    int count=0;
    int chars;
    while(s[count]){
        for(int j=7;j>=0;j--){
            temp[j]=0;
        }
        chars=(int) s[count];
        int i=0;
        while(chars){
            temp[i]=chars%2;
            chars=chars/2;
            i++;
        }
        for(int j=7;j>=0;j--){
            print_bulb(temp[j]);
        }
        printf("\n");
        count++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {

        printf("\U000026AB");
    }
    else if (bit == 1)
    {

        printf("\U0001F7E1");
    }
}
