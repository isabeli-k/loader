#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "loader.h"

#define MALLOC_ERROR 1

void *my_malloc (size_t size)
{
	void *mem = malloc (size);
	if (mem == NULL) {
		printf ("Memory not allocated\n");
		exit (EXIT_FAILURE);
	}
	printf ("allocated %ld\n", size);
	return mem;
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf ("Too few arguments\n");
		exit (EXIT_FAILURE);
	}
	
	char *filename = argv[1];
	
	Image my_image;
	printf("getting image %s\n", filename);
	get_image(&my_image, filename);
	puts("got image");
	int mem_needed = my_image.size * sizeof(Pixel);
	my_image.pixels = my_malloc (mem_needed);
	
	load_image(&my_image, filename);
	
	for (int i = 0; i < my_image.size; i++) {
		my_image.pixels[i].r ^= 255;
		my_image.pixels[i].g ^= 255;
		my_image.pixels[i].b ^= 255;
	}
	
	char *filename_output = argv[2];
	save_image (&my_image, filename, filename_output);
	
	return 0;
}
