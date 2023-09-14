#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            int avrg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtBlue + .189 * image[i][j].rgbtGreen;
            int sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtBlue + .168 * image[i][j].rgbtGreen;
            int sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtBlue + .131 * image[i][j].rgbtGreen;

            if (sepiaRed > 255){
                sepiaRed = 255;
            }

            if (sepiaBlue > 255){
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255){
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pic2[height][width];
            pic2[i][j] = image[i][j];
        }
    }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int theRed;
                int theBlue;
                int theGreen;
                theRed = theBlue = theGreen = 0;
                int counter = 0;

            for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        int theX = i + x;
                        int theY = j + y;

                        if (theX < 0 || theX >= height || theY < 0 || theY >= width)
                        {
                            continue;
                        }

                        theRed += image[theX][theY].rgbtRed;
                        theBlue += image[theX][theY].rgbtBlue;
                        theGreen += image[theX][theY].rgbt.Green;

                        counter++;
                    }
                }
                pic2[i][j].rgbtRed = round((float)theRed / counter);
                pic2[i][j].rgbtBlue = round((float)theblue / counter);
                pic2[i][j].rgbtGreen = round((float)theGreen / counter);
            }
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; width; j++)
            {
                pic2[i][j] = image[i][j];
            }
        }
        return;
}