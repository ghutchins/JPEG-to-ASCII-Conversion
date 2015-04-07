/**  
*  @file    image.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/04/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 6, JPEG to ASCII Conversion
*
*  @section DESCRIPTION
*
*  The image.h header file contains the function declarations
*  or prototypes that can be utilized in a program that deals
*  with converting digital images from JPEG to ASCII.
*
*  @bug No known bugs
*
*/


#ifndef IMAGE_H
#define IMAGE_H
#define MAX_ROW 1000
#define MAX_COL 1000
#include <iostream>
#include <fstream>
#include "jpeg.h"
using namespace std;


void shrinkImage(unsigned char image[][MAX_COL], int& nRow, int& nCol);


void convertImage(unsigned char image[][MAX_COL],int nRow, int nCol, char ascii[][100]); 


void writeImage(string& textFileName, char ascii[][100], int nRow, int nCol); 


#endif


