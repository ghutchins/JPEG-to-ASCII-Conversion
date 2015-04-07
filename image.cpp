/**  
*  @file    image.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/04/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 6, JPEG to ASCII Conversion
*
*  @section DESCRIPTION
*
*  Image.cpp is the source file that contains the function
*  defintions that can be utitlized in a program that deals
*  with converting digital images from JPEG to ASCII.
*
*  @bug No known bugs
*
*/



#include "image.h"
using namespace std;



/**
*  @brief shrinkImage is a function that reduces an image 
*  to fit within a 100x100 2-Dimensional array
*
*  @param image is a 2-D array containing pixel values
*  of a digital image
*  @param nRow is the number of rows in image
*  @param nCol is the number of columns in image
*
*  @return void
*/
void shrinkImage(unsigned char image[][MAX_COL], int& nRow, int& nCol)
{

	unsigned char temp[100][100];	///< Temporary array to shrink image array
	int nR = (nRow / 100);		///< Reduced number of rows--dimension for pixel groups
	int nC = (nCol / 100);		///< Reduced number of columns--dimension for pixel groups
	int r = 0;			///< Counter for rows in temp
	int c = 0;			///< Counter for columns in temp
	int n = 0;			///< Number values in each pixel group (to find average)
	int sum = 0;			///< Variable for sum of each pixel group

	for(int i = 0; i < nRow; i += nR)
	{
		c = 0; 	
		for(int j = 0; j < nCol; j += nC)
		{
			sum = 0;
			n = 0;
			for(int k = i; k < (i + nR) && k < MAX_ROW; k++)
			{
				for(int l = j; l < (j + nC) && l < MAX_COL; l++)
				{
					sum += image[k][l];
					n++;
				}
			}

			temp[r][c] = (sum / n);	  
			c++;      
		}

		r++;
	
	}
	
	nRow = r;
	nCol = c;
	

	for(int i = 0; i < nRow; i++)
		for(int j = 0; j < nCol; j++)
			image[i][j] = temp[i][j];


}



/**
*  @brief convertImage generates the ASCII version of a digital image
*
*  @param image is a 2-D array of a digital image
*  @param nRow is the number of rows in the image
*  @param nCol is the number of columns in the image
*  @param ascii is a 2-D array of an ASCII image
*
*  @return void
*/
void convertImage(unsigned char image[][MAX_COL],int nRow, int nCol, char ascii[][100])
{
	int max = image[0][0];	///< Variable for max value in image
	int min = image[0][0];	///< Variable for min value in image
	int width = 0;		///< Width of each range of values
	int range1 = 0;		///< Upper bound of range 1
	int range2 = 0;		///< Upper bound of range 2
	int range3 = 0;		///< Upper bound of range 3
	int range4 = 0;		///< Upper bound of range 4
	

	for(int i = 0; i < nRow; i++)
	{	
		for(int j = 0; j < nCol; j++)
		{
			if(image[i][j] > max)
			max = image[i][j];
			else if (image[i][j] < min)
			min = image[i][j];
		}
	}

	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			ascii[i][j] = ' ';
	

	width = ((max - min) / 5);
	range1 = (min + width);
	range2 = ((range1 + 1) + width);
	range3 = ((range2 + 1) + width);
	range4 = ((range3 + 1) + width);

	
	for(int i = 0; i < nRow; i++)
	{
		for(int j = 0; j < nCol; j++)
		{
			if(image[i][j] <= range1)
			{
				ascii[i][j] = '#';
			}
			else if(image[i][j] <= range2)
			{
				ascii[i][j] = 'o';
			}
			else if(image[i][j] <= range3)
			{
				ascii[i][j] = ':';
			}
			else if ( image[i][j] <= range4)
			{
				ascii[i][j] = '.';
			}
			else
			{
				ascii[i][j] = ' ';
			}
		}
	}
}



/**
*  @brief writeImage writesd the ASCII version of image to a text file 
*  specified in the command line arguments
* 
*  @param textFileName is the file name input from command line
*  @param ascii is a 2-D array of an ASCII image
*  @param nRow is the number of rows in the array
*  @param nCol is the number of columns in the array
*/
void writeImage(string& textFileName, char ascii[][100], int nRow, int nCol)
{
	fstream dataFile(textFileName.c_str(), ios :: out);

	for(int i = 0; i < nRow; i++)
	{
		for(int j = 0; j < nCol; j++)
		{	
			dataFile << ascii[i][j];
		}

		dataFile << endl;
	}
	
	dataFile.close();
	
}






