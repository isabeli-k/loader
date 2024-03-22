#ifndef LOADER_H
#define LOADER_H
#define BMP_MAGIC 0x4d42

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} Pixel;

typedef struct
{
  uint16_t type;               // Magic identifier
  uint32_t file_size;          // File size in bytes
  uint16_t reserved1;          // Not used
  uint16_t reserved2;          // Not used
  uint32_t offset;             // 
  uint32_t header_size;        // Header size in bytes
  uint32_t width;              // Width of the image
  uint32_t height;             // Height of image
  uint16_t planes;             // Number of color planes
  uint16_t bits;               // Bits per pixel
  uint32_t compression;        // Compression type
  uint32_t image_size;         // Image size in bytes
  uint32_t x_resolution;       // Pixels per meter
  uint32_t y_resolution;       // Pixels per meter
  uint32_t n_colours;          // Number of colors  
  uint32_t imp_colours;  	   // Important colors

} __attribute__((packed)) BMP_ImageHeader; // to get correct alignment 
										   // avoiding the use of #pragma

typedef struct {
	int width;
	int height;
	int size;
	Pixel *pixels;
} Image;

int get_header (BMP_ImageHeader *my_header, const char *filename);
int get_image  (Image *my_image, const char *filename);
int load_image (Image *my_image, const char *filename);
int save_image (Image *my_image, const char *filename, const char *outfilename);

#endif
