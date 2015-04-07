/**  
*  @file    main.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/04/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 6, JPEG to ASCII Conversion
*
*  @section DESCRIPTION
*
*  This program accepts a JPEG image and text file from
*  user input and then reads the JPEG file, saves an ASCII
*  equivalent in the text file, and also prints the size
*  of the original image (number of pixels).
*
*  @bug No known bugs
*
*/

#include <iostream>
#include <fstream>
#include "image.h"
#include "jpeg.h"
#define MAX_ROW 1000
#define MAX_COL 1000
using namespace std;



int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Error, must specify JPEG and text file names \n";
		return 1;
	}

	string jpegFileName = argv[1];	///< JPEG filename
	string textFileName = argv[2];	///< text filename
	unsigned char image[MAX_ROW][MAX_COL];	///< the pixel image

	int nRow = 0;			///< number of rows in image
	int nCol = 0;			///< number of columns in image
	char ascii[100][100];		///< the ASCII image

	if(readJPEGfile(jpegFileName, image, nRow, nCol))
	{
		cout << "image size is " << nRow << 'x' << nCol << " pixels \n";
		if(nRow > 100 || nCol > 100)
		{
			shrinkImage(image, nRow, nCol); 
			cout << "image reduced to " << nRow << 'x' << nCol << " pixels \n";
		}

	convertImage(image, nRow, nCol, ascii);

	writeImage(textFileName, ascii, nRow, nCol);

	}

	else
	{
		cout << "Error, problem reading file \n";
		return 1;
	}


	return 0;


}



