#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "loader.h"

int get_header (BMP_ImageHeader *my_header, const char *filename) {

	printf ("opening file: %s\n", filename);
	
	FILE *fp = fopen (filename, "rb");
	if (fp == NULL) {
		fprintf (stderr, "Error opening file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	int read = fread (my_header, sizeof(BMP_ImageHeader), 1, fp);
	if (read != 1) {
		fprintf (stderr, "Error reading file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	fclose (fp);
	
	return 0;
}

int get_image (Image *my_image, const char *filename) {
	
	BMP_ImageHeader my_header;
	
	puts("getting header");
	get_header(&my_header, filename);
	puts("got header");
	
	my_image -> width = my_header.width;
	my_image -> height = my_header.height;
	my_image -> size = my_image -> width * my_image -> height;
	
	return 0;
}

int load_image (Image *my_image, const char *filename)
{
	FILE *fp = fopen (filename, "rb");
	
	if (fp == NULL) {
		fprintf (stderr, "Error opening file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	int check = fseek (fp, sizeof(BMP_ImageHeader), SEEK_SET);
	if (check != 0) {
		fprintf (stderr, "Error seeking file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	int read = fread (my_image -> pixels, sizeof(Pixel), my_image -> size, fp);
	if (read != my_image -> size) {
		fprintf (stderr, "Error reading file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	fclose (fp);
	
	return 0;
}

int save_image (Image *image, const char *filename, const char *outfilename)
{
	BMP_ImageHeader my_header;
	get_header(&my_header, filename);
	
	FILE *fp = fopen (outfilename, "wb+");
	
	if (fp == NULL) {
		fprintf (stderr, "Error opening file: %s.\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	
	fwrite (&my_header, sizeof(BMP_ImageHeader), 1, fp);
	fwrite (image -> pixels, sizeof(Pixel), image -> size, fp);
	
	fclose (fp);
	
	return 0;
}
