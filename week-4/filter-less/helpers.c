#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE media = (BYTE) round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);    
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtRed = media;
        }     
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // BYTE media = (BYTE) round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);    
            // image[i][j].rgbtBlue = media;
            // image[i][j].rgbtGreen = media;
            // image[i][j].rgbtRed = media;
            BYTE sepiaRed = (BYTE)  round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            BYTE sepiaGreen = (BYTE) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            BYTE sepiaBlue = (BYTE) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }     
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0,n = width - j - 1; j < n; j++,n--)
        {
            RGBTRIPLE temp = image[i][n];
            image[i][n] = image[i][j];
            image[i][j] = temp;
        }     
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    return;
}

RGBTRIPLE average(int height, int width, RGBTRIPLE copy[height][width])
{
    BYTE denominator = 0;
    RGBTRIPLE average;
    for (int i = height - 1; i <= height + 1; i++)
    {
        for (int j = width - 1; j <= width + 1; j++)
        {
            average.rgbtBlue = 0;
            average.rgbtGreen = 0;
            average.rgbtRed = 0;
        }
    }
    for (int i = height - 1; i <= height + 1; i++)
    {
        for (int j = width - 1; j <= width + 1; j++)
        {
            average.rgbtBlue += copy[i][j].rgbtBlue;
            average.rgbtGreen += copy[i][j].rgbtGreen;
            average.rgbtRed += copy[i][j].rgbtRed;
            denominator++;
        }
    }
    average.rgbtBlue /= denominator;
    average.rgbtGreen /= denominator;
    average.rgbtRed /= denominator;
    return average;
}