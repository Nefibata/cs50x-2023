#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
        int start=0;
        do
        {
            start = get_int("Start size: ");
        }
        while (start < 9);


    // TODO: Prompt for end size

        int end=0;
        do
        {
            end = get_int("End size: ");
        }
        while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int size=start;
    int year=0;
    while(size<end){
        int re=size;
        size=size+re/3-re/4;
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);

}
