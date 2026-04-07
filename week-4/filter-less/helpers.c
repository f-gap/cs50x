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

//Average prototype
RGBTRIPLE average(int row, int col, int height, int width, RGBTRIPLE copy[height][width]);
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

    //Aplicando a nova cor aos pixels (cor calculada através da função average)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = average(i,j,height,width, copy);
        }
    }
    return;
}

RGBTRIPLE average(int row, int col, int height, int width, RGBTRIPLE copy[height][width])
{
    // BYTE denominator = 0;
    // RGBTRIPLE average;
    int sumBlue = 0;
    int sumGreen = 0;
    int sumRed = 0;
    float denominator = 0;
    RGBTRIPLE avg;
    // for (int i = row - 1; i <= row + 1; i++)
    // {
    //     for (int j = col - 1; j <= col + 1; j++)
    //     {
    //         average.rgbtBlue = 0;
    //         average.rgbtGreen = 0;
    //         average.rgbtRed = 0;
    //     }
    // }
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && j >= 0 && i < height && j < width)
            {
                sumBlue += (int) copy[i][j].rgbtBlue;
                sumGreen += (int) copy[i][j].rgbtGreen;
                sumRed += (int) copy[i][j].rgbtRed;
                denominator++;
            }
        }
    }
    avg.rgbtBlue = (BYTE) round(sumBlue/denominator);
    avg.rgbtGreen = (BYTE) round(sumGreen/denominator);
    avg.rgbtRed = (BYTE) round(sumRed/denominator);
    return avg;
}
