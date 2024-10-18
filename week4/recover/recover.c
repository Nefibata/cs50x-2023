#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if(argc==1){
        printf("Usage: ./recover IMAGE\n");
        return 1;

    }
    FILE *file = fopen(argv[1], "r");
    if(file==NULL){
        return 1;
    }
    size_t BLOCK_SIZE= 512;
    void *buffer=malloc(BLOCK_SIZE);
    bool flag=false;
    int id =0;
    int id2 = 0;
    int id3 =0;
    FILE *result;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE){
        unsigned char *temp1=(unsigned char *)buffer;
        unsigned char high4;
        high4 = (temp1[3] & 0xf0) >> 4;
        if(temp1[0]==0xFF&&temp1[1]==0xD8&&temp1[2]==0xFF&&high4==0b1110){
            if(flag){
                fclose(result);
            }
            char s[8];
            sprintf(s, "%i%i%i.jpg", id3,id2,id);
            result=fopen(s, "w+");
            flag=true;
                id++;
                id2+=id/10;
                id3+=id2/10;
                id=id%10;
                id2=id2%10;
        }
        if(flag){
            fwrite(buffer,1,BLOCK_SIZE ,result );

        }
    }
    fclose(result);
    fclose(file);
    free(buffer);
    return 0;


}
