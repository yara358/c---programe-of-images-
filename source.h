#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define BLACK  ' '
#define WHITE  '*'


void print_image(char image[30][30]);
void open_RLE_picture(char image[30][30], char path[256]);
void open_TXT_picture(char image[30][30],char path[256]);
void save_RLE_picture(char image[30][30], char path[256]);
void save_TXT_picture(char image[30][30], char path[256]);
long int findSize(char file_name[]);
void create_square(char image[30][30], char kind[256],int size);
void create_tringle(char image[30][30], char kind[256], int size);
void create_romb(char image[30][30], char kind[256], int size);
#pragma once
