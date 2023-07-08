#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include "source.h"


void main()
{
	unsigned char image[30][30];
	int i, j;
	char path[256];
	char choice[256], kind[256];
	int size;
	char color[256];

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			image[i][j] = ' ';
		}
	}


	printf("open_RLE_picture\n");
	printf("open_TXT_picture\n");
	printf("save_RLE_picture\n");
	printf("save_TXT_picture\n");
	printf("create_square\n");
	printf("regular\n");
	printf("invent\n");
	printf("create_trangle\n");
	printf("regular\n");
	printf("invent\n");
	printf("create_romb\n");
	printf("regular\n");
	printf("invent\n");
	printf("stop\n");
	printf("Enter one of these choice's\n");
	scanf("%s", &choice);


	if (strcmp(choice, "open_RLE_picture") == 0) {
		printf("Enter the path\n");
		scanf("%s", &path);
		while (findSize(path) > 100) {
			printf("yout entered the wrong size,reenter it please\n");
			scanf("%s", &path);
		}
		open_RLE_picture(image, path);
	}
	if (strcmp(choice, "open_TXT_picture") == 0) {
		printf("Enter the path\n");
		scanf("%s", &path);
		while (findSize(path) > 1000 || findSize(path)<900) {
			printf("yout entered the wrong size,reenter it please\n");
			scanf("%s", &path);
		}

		open_TXT_picture(image, path);

	}
	if (strcmp(choice, "save_RLE_picture") == 0) {
		printf("Enter the path\n");
		scanf("%s", &path);
		while (findSize(path) > 100) {
			printf("yout entered the wrong size,reenter it please\n");
			scanf("%s", &path);
		}
		save_RLE_picture(image, path);
	}
	if (strcmp(choice, "save_TXT_picture") == 0) {
		printf("Enter the path\n");
		while (findSize(path) > 1000 || findSize(path) < 900) {
			printf("yout entered the wrong size,reenter it please\n");
			scanf("%s", &path);
		}
		scanf("%s", &path);
		save_TXT_picture(image, path);
	}
	

	if (strcmp(choice, "create_square") == 0) {
			printf("Enter the color the size for width and hieght\n");
			scanf("%s%d", &kind,&size);
			create_square(image,kind,size);
	}
	

	if (strcmp(choice, "create_trangle") == 0) {
		printf("Enter the color the size for width and hieght\n");
		scanf("%s%d", &kind, &size);
		create_tringle(image, kind, size);
		}
		

		
    if (strcmp(choice, "create_romb") == 0) {
		printf("Enter the color the size for width and hieght\n");
		scanf("%s%d", &kind, &size);
		create_romb(image, kind, size);
		}


	if (strcmp(choice, "stop") == 0) {
			return;
		}

	}
	
