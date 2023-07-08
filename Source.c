#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include "source.h"

void print_image(char image[30][30], int size,int size1)
{
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size1; j++) {
			printf("%c",image[i][j]);
		}
		printf("\n");
	}
}

//To find the size of the file
long int findSize(char file_name[])
{
	
	FILE* fp = fopen(file_name, "r");

	
	if (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);

	// calculating the size of the file 
	long int res = ftell(fp);

	// closing the file 
	fclose(fp);

	return res;

}


void open_RLE_picture(unsigned char ima[30][30],char path[256])
{
	unsigned char byte;
	int color = 0, amount;
	int count = 0;
	int i, j,k;
	FILE* file;
	file = fopen(path, "r");
	
	//if file doesn't open
	if (file == NULL)
	{
		printf("File %s doesn't open\n", path);
		return;
	}
	
	do
		{
		//reading from the file
			fread(&byte,sizeof(unsigned char),1,file);

			amount = byte;

			// amount during the first color
			if (amount > (2*2*2*2*2*2*2)-1)
			{
				color = 1;
				amount -= (2 * 2 * 2 * 2 * 2 * 2 * 2);
			}
			else //if the amount got to other color
				if (amount < 0)
				{
					amount += (2 * 2 * 2 * 2 * 2 * 2 * 2*2);
				}
			//getting the colors inside the array 
			for (k = 0; k < amount; k++)
			{
				if (!color)
				{ 
					ima[count / 30][(count % 30)] = '*';
				}
				else
				{
					ima[count / 30][(count % 30)] = ' ';
				}
				count++;
			}
			color = 0;

	} while (!feof(file));

	for ( i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			printf("%c", ima[i][j]);
		}
		printf("\n");
	}
	fclose(file);//closing file
}

void open_TXT_picture(char image[30][30], char path[256]) {

    char byte;
	FILE* file;

	file = fopen(path, "rb+");

		fread(&byte, 1, 1, file);
	
		
		while (!feof(file))
		{
			fread(&byte, 1, 1, file);
			printf("%c", byte);
		}

	fclose(file);
}

void save_RLE_picture(char image[30][30], char path[256])
{

	FILE* file,*file1;
	unsigned char byte;
	unsigned char color;
	int i, j,count=0;
	char path1[256];

	printf("Enter the path to the second file\n");
	scanf("%s", path1);

	file = fopen(path, "r");
	file1 = fopen(path1, "w");
	

	color = image[0][0];
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			if (color == image[i][j] && count < 127) // to check if we got new color 
				                                       //and how much there is 
				                                      //from the same color and to count it 
			{
				count++;
			}
			else //if he color change and which color it become
			{
				if (color == ' ') {
					count += 128;
				}
				fprintf(file1, "%c", (char)count);
				color = image[i][j];
				count = 0;
			}
		}
	}
	fclose(file);
	fclose(file1);
}

void save_TXT_picture(char image[30][30], char path[256])
{
	FILE* file1, * file2;
	 char path1[256];
	 char byte;
	 int i, j;

	 printf("enter the to go to file\n");
	 scanf("%s", path1);
	 file1 = fopen(path, "r");
	 file2 = fopen(path1, "w");

	 if (!file1)
	 {
		 printf("File is not opening\n");
		 return;
	 }

	 for (i = 0; i < 30; i++) {
		 for (j = 0; j < 30; j++) {

			 fread(&byte, sizeof(char), 1, file1);
			 //to check with symbol to enter the space or star
			 if (byte == ' ') {
				 fprintf(file2, "%c", ' ');
			 }
			 else
				 fprintf(file2, "%c", '*');

		 }
		 fprintf(file2, "\n");
	 }

	 fclose(file1);
	 fclose(file2);
}

void create_square(char image[30][30], char kind[256], int size)
{
	char blake = BLACK;
	char white = WHITE;
	int i, j, res1, res2, res3, res4;

	res1 = size/3;
	res2 = res1 / 2;
	res3 = (size - res2) / 2;

	if (strcmp(kind, "regular") == 0)
	{
		for (i = 0; i <size; i++) {
			for (j = 0; j <size; j++) {//condition to enter for space  if place on the middle or on the side
				if ((i>res1 && j > res1 )||( i>(size-3) && j > res1 )||( j > (size - 3) && i > res1 )||(j>(size-3)&& i > (size - 3))) {
					image[i][j] = BLACK;
				}
				else {
					image[i][j] = WHITE;
				}
			}
		}
		
	}
	else {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if ((i > res1 && j > res1) || (i > (size - 3) && j > res1) || (j > (size - 3) && i > res1) || (j > (size - 3) && i > (size - 3))) {
					image[i][j] = WHITE;
				}
				else {
					image[i][j] = BLACK;
				}
			}
		}


	}
	print_image(image,size,size);
}
		

void create_tringle(char image[30][30], char kind[256], int size)
{
	char blake = BLACK;
	char white = WHITE;
	int i, j, k = 0;
	int c = 0, r = 0;
	int res, res1, res2, re3;
	res1 = (30 - size) / 2;
	res2 = (30 - size + 1) / 2;
	res = (30-(size+1))/2;

	if (strcmp(kind, "regular") == 0)
	{

		for (r=0; r < res; r++)
		{
			for (int j = 0; j < 30; j++)
				image[r][j] = BLACK;
		}
		//checking if size odd number or not 
		if (size / 2)
		{
			for (i = 2; i <= size; i += 2)
			{
				c = res1;
				for (k = 0; k < res1; k++)
					image[r][k] = blake;
				for ( j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = blake;
					c++;
				}
				for (j = 0; j < i; j++)
				{
					image[r][c] = white;
					c++;
				}
				for ( j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = blake;
					c++;
				}
				for ( k = 0; k < res2; k++)
					image[r][k + c] = blake;
				r++;
			}
		}


		else
			for ( i = 1; i <= size; i += 2)
			{
				c = res1;
				for ( k = 0; k < res1; k++)
					image[r][k] = blake;
				for (int j = 0; j < (size - i) / 2; j++)
				{
					
					image[r][c] = blake;
					c++;
				}
				for ( j = 0; j < i; j++)
				{
					
					image[r][c] = white;
					c++;
				}
				for ( j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = blake;
					c++;
					
				}
				for (k = 0; k < res2; k++)
					image[r][k + c] = blake;
				r++;
			}

	}
	else {
		for (r=0; r < res; r++)
		{
			for (int j = 0; j < size; j++)
				image[r][j] = BLACK;
		}
		if (size / 2)
		{
			for (i = 2; i <= size; i += 2)
			{
				c = res1;
				for (k = 0; k < res1; k++)
					image[r][k] = blake;
				for (j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = blake;
					c++;
				}
				for (j = 0; j < i; j++)
				{
					image[r][c] = white;
					c++;
				}
				for (j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = blake;
					c++;
				}
				for (k = 0; k < res2; k++)
					image[r][k + c] = blake;
				r++;
			}
		}


		else
			for (i = 1; i <= size; i += 2)
			{
				c = res1;
				for (k = 0; k < res1; k++)
					image[r][k] = white;
				for (int j = 0; j < (size - i) / 2; j++)
				{

					image[r][c] = white;
					c++;
				}
				for (j = 0; j < i; j++)
				{

					image[r][c] = blake;
					c++;
				}
				for (j = 0; j < (size - i) / 2; j++)
				{
					image[r][c] = white;
					c++;

				}
				for (k = 0; k < res2; k++)
					image[r][k + c] = white;
				r++;
				
			}

	}
	
	
	print_image(image, size, size);
}

void create_romb(char image[30][30], char kind[256], int size)
{
	char blake = BLACK;
	char white = WHITE;
	int i, j, k = 0;
	int c = 0, r = 0;


	if (strcmp(kind, "regular") == 0)
	{

		r = size - 1;

		for (k = 1; k <= size; k++)
		{
			for (c = 1; c <= r; c++)
				printf(" ");

			r--;

			for (c = 1; c <= 2 * k - 1; c++)
				printf("*");

			printf("\n");
		}

		r = 1;

		for (k = 1; k <= size - 1; k++)
		{
			for (c = 1; c <= r; c++)
				printf(" ");

			r++;

			for (c = 1; c <= 2 * (size - k) - 1; c++)
				printf("*");

			printf("\n");
		}
	}
	else
	{

		// Loop to print upper half of the pattern
		for (i = 1; i <= size; i++)
		{
			for (j = i; j <= size; j++)
			{
				printf("*");
			}

			for (j = 1; j <= (2 * i - 2); j++)
			{
				printf(" ");
			}

			for (j = i; j <= size; j++)
			{
				printf("*");
			}

			printf("\n");
		}

		// Loop to print lower half of the pattern
		for (i = 1; i <= size; i++)
		{
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}

			for (j = (2 * i - 2); j < (2 * size - 2); j++)
			{
				printf(" ");
			}

			for (j = 1; j <= i; j++)
			{
				printf("*");
			}

			printf("\n");
		}
	}

}