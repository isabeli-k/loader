# BMP Image Loader

This project is a low-level BMP image loader written in C.  
It demonstrates how binary file formats can be parsed manually using structs, file I/O, and pointer-based memory handling.

The goal is to understand how image files (specifically BMP) are structured and how raw pixel data can be loaded and saved without external libraries.

## 📖 What this project does

This program:

- Reads BMP file headers directly from disk
- Extracts image metadata (width, height, etc.)
- Loads raw pixel data into memory
- Saves modified images back to disk

It operates directly on binary data using `fopen`, `fread`, `fwrite`, and `fseek`.

## 🚀 Future Improvements

- Add BMP format validation (magic number check)
- Add dynamic memory allocation for pixel buffer
- Support for different bit depths (24-bit / 32-bit BMP)
- Replace exit() with proper error handling system

### Disclaimer:
I passed the code to ChatGPT to help me write this README.md and explained it about my future goals. If it sounds too AI, it's because it is AI generated.
