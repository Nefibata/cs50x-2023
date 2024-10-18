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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp2[height+2][width+2];
    for(int i=0;i<height+2;i++){
        for(int j=0;j<width+2;j++){
            if(i==0||j==0||i==height+1||j==width+1){
                continue;
            }
            temp2[i][j]=image[i-1][j-1];
        }
    }
    for(int i=1;i<height+1;i++){
        for(int j=1;j<width+1;j++){

            long bluetempgy=  -temp2[i-1][j-1].rgbtBlue-2*temp2[i-1][j].rgbtBlue-temp2[i-1][j+1].rgbtBlue+

                            temp2[i+1][j-1].rgbtBlue+2*temp2[i+1][j].rgbtBlue+temp2[i+1][j+1].rgbtBlue;

            long greentempgy=  -temp2[i-1][j-1].rgbtGreen-2*temp2[i-1][j].rgbtGreen-temp2[i-1][j+1].rgbtGreen+

                            temp2[i+1][j-1].rgbtGreen+2*temp2[i+1][j].rgbtGreen+temp2[i+1][j+1].rgbtGreen;

            long redtempgy=  -temp2[i-1][j-1].rgbtRed-2*temp2[i-1][j].rgbtRed-temp2[i-1][j+1].rgbtRed+

                            temp2[i+1][j-1].rgbtRed+2*temp2[i+1][j].rgbtRed+temp2[i+1][j+1].rgbtRed;


            long bluetempgx= -temp2[i-1][j-1].rgbtBlue+0+temp2[i-1][j+1].rgbtBlue
                            -2*temp2[i][j-1].rgbtBlue+0+2*temp2[i][j+1].rgbtBlue+
                            -temp2[i+1][j-1].rgbtBlue+0+temp2[i+1][j+1].rgbtBlue;

            long greentempgx=-temp2[i-1][j-1].rgbtGreen+0+temp2[i-1][j+1].rgbtGreen
                            -2*temp2[i][j-1].rgbtGreen+0+2*temp2[i][j+1].rgbtGreen+
                            -temp2[i+1][j-1].rgbtGreen+0+temp2[i+1][j+1].rgbtGreen;

            long redtempgx=-temp2[i-1][j-1].rgbtRed+0+temp2[i-1][j+1].rgbtRed
                            -2*temp2[i][j-1].rgbtRed+0+2*temp2[i][j+1].rgbtRed+
                            -temp2[i+1][j-1].rgbtRed+0+temp2[i+1][j+1].rgbtRed;
            image[i-1][j-1].rgbtRed=round(sqrt(pow(redtempgx,2)+pow(redtempgy,2))) >255? 255:round(sqrt(pow(redtempgx,2)+pow(redtempgy,2))) ;
            image[i-1][j-1].rgbtGreen=round(sqrt(pow(greentempgx,2)+pow(greentempgy,2))) >255? 255:round(sqrt(pow(greentempgx,2)+pow(greentempgy,2))) ;
            image[i-1][j-1].rgbtBlue=round(sqrt(pow(bluetempgx,2)+pow(bluetempgy,2))) >255? 255:round(sqrt(pow(bluetempgx,2)+pow(bluetempgy,2))) ;



        }
    }
    return;
}
