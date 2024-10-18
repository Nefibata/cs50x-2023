#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            double temp=0;
            temp+=image[i][j].rgbtBlue;
            temp+=image[i][j].rgbtGreen;
            temp+=image[i][j].rgbtRed;
            temp=round(temp/3.0);
            image[i][j].rgbtRed=temp;
            image[i][j].rgbtGreen=temp;
            image[i][j].rgbtBlue=temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            BYTE originalBlue=image[i][j].rgbtBlue;
            BYTE originalGreen=image[i][j].rgbtGreen;
            BYTE originalRed=image[i][j].rgbtRed;
            image[i][j].rgbtRed=round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue)>255 ? 255:round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            image[i][j].rgbtGreen=round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue) >255 ? 255:round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue) ;
            image[i][j].rgbtBlue=round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue)>255 ? 255:round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0;i<height;i++){
        for(int j=0;j<width/2;j++){
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-1-j];
            image[i][width-1-j]=temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0&&j>0&&j<width-1){
                long bluetemp=
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+
                              image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue;
                long greentemp=
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+
                            image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen;

                long redtemp=
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+
                            image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed;

            temp[i][j].rgbtRed=round(redtemp/6.0);
            temp[i][j].rgbtGreen=round(greentemp/6.0);
            temp[i][j].rgbtBlue=round(bluetemp/6.0);
            continue;
            }
            if(i==height-1&&j>0&&j<width-1){
                long bluetemp= image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue;
                long greentemp=
                            image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen;

                long redtemp=
                           image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed;
            temp[i][j].rgbtRed=round(redtemp/6.0);
            temp[i][j].rgbtGreen=round(greentemp/6.0);
            temp[i][j].rgbtBlue=round(bluetemp/6.0);
            continue;
            }
            if(j==width-1&&i>0&&i<height-1){
            long bluetemp=  image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+
                            image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue;

            long greentemp=  image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+
                            image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen;

            long redtemp=  image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed+
                            image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed;
            temp[i][j].rgbtRed=round(redtemp/6.0);
            temp[i][j].rgbtGreen=round(greentemp/6.0);
            temp[i][j].rgbtBlue=round(bluetemp/6.0);
            continue;
            }
            if(j==0&&i>0&&i<height-1){
            long bluetemp=  image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+
                            image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+
                            image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue;

            long greentemp=  image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+
                            image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+
                           image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen;

            long redtemp=  image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+
                            image[i][j].rgbtRed+image[i][j+1].rgbtRed+
                            image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed;
            temp[i][j].rgbtRed=round(redtemp/6.0);
            temp[i][j].rgbtGreen=round(greentemp/6.0);
            temp[i][j].rgbtBlue=round(bluetemp/6.0);
            continue;
            }
            if(j==0&&i==0){
            long bluetemp=
                            image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+
                            image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue;

            long greentemp=
                           image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+
                           image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen;

            long redtemp=
                           image[i][j].rgbtRed+image[i][j+1].rgbtRed+
                            image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed;
            temp[i][j].rgbtRed=round(redtemp/4.0);
            temp[i][j].rgbtGreen=round(greentemp/4.0);
            temp[i][j].rgbtBlue=round(bluetemp/4.0);
            continue;
            }
            if(j==0&&i==height-1){
            long bluetemp=  image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+
                            image[i][j].rgbtBlue+image[i][j+1].rgbtBlue;


            long greentemp=  image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+
                           image[i][j].rgbtGreen+image[i][j+1].rgbtGreen;


            long redtemp= image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+
                          image[i][j].rgbtRed+image[i][j+1].rgbtRed;

            temp[i][j].rgbtRed=round(redtemp/4.0);
            temp[i][j].rgbtGreen=round(greentemp/4.0);
            temp[i][j].rgbtBlue=round(bluetemp/4.0);
            continue;
            }
            if(j==width-1&&i==height-1){
            long bluetemp=  image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue;


            long greentemp=  image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen;

            long redtemp=  image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed;

            temp[i][j].rgbtRed=round(redtemp/4.0);
            temp[i][j].rgbtGreen=round(greentemp/4.0);
            temp[i][j].rgbtBlue=round(bluetemp/4.0);
            continue;
            }
            if(j==width-1&&i==0){
              long bluetemp=
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+
                            image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue;

            long greentemp=
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+
                            image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen;

            long redtemp=
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed+
                            image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed;

            temp[i][j].rgbtRed=round(redtemp/4.0);
            temp[i][j].rgbtGreen=round(greentemp/4.0);
            temp[i][j].rgbtBlue=round(bluetemp/4.0);
            continue;
            }
            long bluetemp=  image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+
                            image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+
                            image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue;

            long greentemp=  image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+
                            image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+
                            image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen;

            long redtemp=  image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+
                            image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+
                            image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed;

            temp[i][j].rgbtRed=round(redtemp/9.0);
            temp[i][j].rgbtGreen=round(greentemp/9.0);
            temp[i][j].rgbtBlue=round(bluetemp/9.0);

        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j]=temp[i][j];
        }
    }
    return;
}
