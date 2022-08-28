#include "helpers.h"
#include <cs50.h>
#include <stdio.h>

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0 ; i< height; i++)
    {

        for(int e = 0; e < width; e++)
        {
            int medium = 0;

            medium += image[i][e].rgbtBlue;
            medium += image[i][e].rgbtGreen;
            medium += image[i][e].rgbtRed;


            medium = medium/3;


            image[i][e].rgbtBlue = medium;
            image[i][e].rgbtGreen = medium;
            image[i][e].rgbtRed = medium;


        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int RGB[3];
    int width2 = width;
    int e = 0;
    for(int i = 0 ; i< height; i++)
    {

        while(width2 > width/2 && e < width)
        {
            
            RGB[0] = image[i][e].rgbtBlue;
            RGB[1] = image[i][e].rgbtGreen;
            RGB[2] = image[i][e].rgbtRed;
            
            image[i][e].rgbtBlue =  image[i][width2].rgbtBlue;
            image[i][e].rgbtGreen = image[i][width2].rgbtGreen;
            image[i][e].rgbtRed =  image[i][width2].rgbtRed;
            
            
            image[i][width2].rgbtBlue =  RGB[0];
            image[i][width2].rgbtGreen = RGB[1];
            image[i][width2].rgbtRed =  RGB[2];

 
            
            width2--;
            e++;
        }


        
        e = 0;
        width2 = width; 

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0 ; i< height; i++)
    {

        for(int j = 0; j < width; j++)
        {
            int RedNew = 0, GreenNew = 0, BlueNew = 0;
            
            for(int k = -1; k < 2; k++)
            {
                
                for(int r = -1 ; r < 2;r++)
                {
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }

                    if (j + r < 0 || j + r > width - 1)
                    {
                        continue;
                    }

                    
                    RedNew += image[i+k][j+r].rgbtRed;;
                    GreenNew += image[i+k][j+r].rgbtGreen;
                    BlueNew += image[i+k][j+r].rgbtBlue;
                }
                
            }
            
            
            GreenNew = GreenNew/9;
            RedNew = RedNew/9;
            BlueNew = BlueNew/9;
            
            image[i][j].rgbtBlue = BlueNew;
            image[i][j].rgbtGreen = GreenNew;
            image[i][j].rgbtRed = RedNew;
            

        }

    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
