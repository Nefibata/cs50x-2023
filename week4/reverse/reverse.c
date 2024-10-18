#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc!=3){
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *file=fopen(argv[1],"r");
    if(file==NULL){
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER openware;
    fread(&openware.chunkID,4,1,file);
    fread(&openware.chunkSize,4,1,file);
    fread(&openware.format,4,1,file);
    fread(&openware.subchunk1ID,4,1,file);
    fread(&openware.subchunk1Size,4,1,file);
    fread(&openware.audioFormat,2,1,file);
    fread(&openware.numChannels,2,1,file);
    fread(&openware.sampleRate,4,1,file);
    fread(&openware.byteRate,4,1,file);
    fread(&openware.blockAlign,2,1,file);
    fread(&openware.bitsPerSample,2,1,file);
    fread(&openware.subchunk2ID,4,1,file);
    fread(&openware.subchunk2Size,4,1,file);
    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(openware)==1){
        printf("Input is not a WAV file.\n");
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE *outfile=fopen(argv[2],"w+");
    // Write header to file
    // TODO #6
    fwrite(&openware.chunkID,4,1,outfile);
    fwrite(&openware.chunkSize,4,1,outfile);
    fwrite(&openware.format,4,1,outfile);
    fwrite(&openware.subchunk1ID,4,1,outfile);
    fwrite(&openware.subchunk1Size,4,1,outfile);
    fwrite(&openware.audioFormat,2,1,outfile);
    fwrite(&openware.numChannels,2,1,outfile);
    fwrite(&openware.sampleRate,4,1,outfile);
    fwrite(&openware.byteRate,4,1,outfile);
    fwrite(&openware.blockAlign,2,1,outfile);
    fwrite(&openware.bitsPerSample,2,1,outfile);
    fwrite(&openware.subchunk2ID,4,1,outfile);
    fwrite(&openware.subchunk2Size,4,1,outfile);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size=get_block_size(openware);
    // Write reversed audio to file
    // TODO #8
    long nowlabel=ftell(file);
    unsigned char * temp=malloc(sizeof(unsigned char * )*block_size);
    int count=1;
    while(1){
        fseek(file,-block_size*count,SEEK_END);
        fread(temp,1,block_size,file);
        if(nowlabel==ftell(file))break;
        fwrite(temp,1,block_size,outfile);
        count++;
    }
    fclose(outfile);
    fclose(file);
    free(temp);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if(header.format[0]!='W')return 1;
    if(header.format[1]!='A')return 1;
    if(header.format[2]!='V')return 1;
    if(header.format[3]!='E')return 1;
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.bitsPerSample*header.numChannels/8;//最后原来一直错在这里了，需要除8才行，之前一直没有除8，这是字节数，因此需要换算成字符
}
