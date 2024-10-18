// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    void *buffer=malloc(HEADER_SIZE);
    // TODO: Copy header from input file to output file
    fread(buffer, 1, HEADER_SIZE, input);
    fwrite(buffer, 1, HEADER_SIZE, output);
    free(buffer);
    // TODO: Read samples from input file and write updated data to output file
    void *temp=malloc(2);
    while (fread(temp, 2, 1, input) == 1){
        short *temp2=(short *)temp;
        temp2[0]=temp2[0]*factor;
        fwrite(temp2, 2, 1, output);
    }
    free(temp);
    // Close files
    fclose(input);
    fclose(output);
}
