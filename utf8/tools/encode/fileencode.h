#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char g_headflag[] = {
  0x84, 0xCC, 0xFA, 0x75, 0x9A, 0x9D, 0x3B, 0x6D, 0x5A, 0xE1,
  0xE8, 0x3A, 0xC6, 0x0E, 0x6C, 0x7B, 0x46, 0x5C, 0x10, 0x36
};

const char g_keytable[] = {
  0xA4, 0xE9, 0x49, 0x00, 0xD7, 0x89, 0xAA, 0x36, 0xD3, 0xDC, 
  0x77, 0x32, 0x1C, 0xA8, 0xA4, 0x7F, 0x99, 0x46, 0x28, 0x7B, 
  0x47, 0x5C, 0x10, 0x36, 0x60, 0x9E, 0xC7, 0x96, 0x9E, 0x66, 
  0x6E, 0x80, 0xC4, 0x6B, 0x36, 0x1B, 0xD7, 0xCD, 0x47, 0x76, 
  0x57, 0x63, 0x08, 0x84, 0x45, 0x4D, 0xD1, 0xBE, 0x53, 0xD0, 
  0x77, 0x72, 0x14, 0x9A, 0x21, 0xF2, 0xE6, 0xB5, 0xDB, 0xC0, 
  0x9E, 0xFC, 0xEA, 0xDB, 0x86, 0xCD, 0x34, 0xDC, 0xC6, 0x30, 
  0xD7, 0xF6, 0x54, 0xD6, 0x43, 0x82, 0x66, 0x96, 0xE3, 0xCE, 
  0x1C, 0xB3, 0xB6, 0x31, 0xCF, 0xC0, 0xD7, 0x27, 0x4F, 0xD0, 
  0xE5, 0x83, 0x58, 0x41, 0xC4, 0xF1, 0x26, 0xE5, 0x1A, 0xCE, 
  0x76, 0x50, 0x98, 0x9A, 0x3D, 0x82, 0xE7, 0x8F, 0x76, 0xC2, 
  0xC2, 0x18, 0x54, 0x67, 0x1D, 0xAE, 0xB2, 0xC8, 0x64, 0x61, 
  0x0E, 0xB4, 0xB6, 0x8F, 0xE4, 0x0A, 0x93, 0x17, 0xC8, 0x67, 
  0x6F, 0x72, 0x1C, 0x7C, 0xA2, 0xB0, 0xCA, 0xA5, 0xEE, 0x3A, 
  0xFD, 0xB1, 0x01, 0xE1, 0x7A, 0xDC, 0xD6, 0xCD, 0x11, 0x08, 
  0xF2, 0xC4, 0x59, 0x7C, 0xAA, 0xFA, 0xD0, 0x3A, 0xBE, 0x29, 
  0x98, 0x2B, 0x55, 0xEA, 0x82, 0x35, 0x5A, 0x61, 0xA3, 0x6A, 
  0xFB, 0xA4, 0x9E, 0x62, 0x27, 0x8C, 0x56, 0x01, 0xC7, 0xBE, 
  0x4A, 0xAD, 0x40, 0x2B, 0xBA, 0xB4, 0xB8, 0xD1, 0x62, 0xEC, 
  0xD9, 0xFE, 0x60, 0x4E, 0x8A, 0x50, 0x19, 0x8C, 0xB1, 0x44, 
  0xBA, 0xF5, 0x32, 0x1A, 0x1A, 0x14, 0x8B, 0x35, 0x97, 0xDB, 
  0xDD, 0xEC, 0xCC, 0x70, 0x3E, 0x5B, 0x21, 0x2F, 0x8E, 0x22, 
  0x96, 0x9B, 0xD4, 0xB8, 0x69, 0xE3, 0xBD, 0xB7, 0xBC, 0x07, 
  0xBD, 0xB7, 0x16, 0x53, 0x12, 0xB0, 0x49, 0xDF, 0x05, 0xF4, 
  0x90, 0x9B, 0x2C, 0x3C, 0x0A, 0x1F, 0x26, 0x4E, 0x45, 0xDE, 
  0x72, 0x3A, 0x98, 0xE7, 0xEA, 0xCA, 0x76, 0xC6, 0x04, 0xFE, 
  0xC5, 0x64, 0x4E, 0xC7, 0x4C, 0x7A, 0xDA, 0xD6, 0x24, 0xF1, 
  0x49, 0x28, 0xA8, 0x9C, 0xAE, 0x89, 0x04, 0x8E, 0xE9, 0x5C, 
  0x47, 0x17, 0x36, 0xB5, 0xB4, 0x3E, 0xC9, 0x44, 0x89, 0x3D, 
  0x7B, 0x38, 0xD0, 0xBE, 0x18, 0x0D, 0x31, 0x5C, 0xEA, 0x48, 
  0x27, 0x36, 0x9D, 0xA6, 0x17, 0x0B, 0x69, 0xCF, 0xC1, 0x2B, 
  0x56, 0x77, 0x74, 0xC6, 0xEA, 0x0F, 0x7A, 0xCA, 0x95, 0x6D, 
  0x40, 0xEA, 0xA8, 0x91, 0x99, 0x03, 0x3F, 0x5A, 0x19, 0xE9, 
  0x5B, 0xEE, 0x87, 0xE9, 0x0D, 0x1C, 0x3F, 0xE4, 0x09, 0xE6, 
  0x16, 0x76, 0xE2, 0xA1, 0x9D, 0x85, 0xE5, 0x3E, 0x4B, 0x8D, 
  0xB7, 0x2D, 0xE7, 0xB2, 0xC1, 0xF8, 0xC8, 0x50, 0x0C, 0x7A, 
  0xC0, 0x8F, 0x87, 0x58, 0x3B, 0x4E, 0xEF, 0x23, 0x77, 0x4D, 
  0x49, 0xB8, 0xDD, 0x7A, 0x19, 0xE0, 0x51, 0xC9, 0x62, 0x2C, 
  0x8E, 0xF1, 0x8A, 0x96, 0xE5, 0x01, 0x22, 0x75 };

void encrypt(const char* source, char* buffer, int size);
int encode(const char* src_file, const char* dst_file);
int decode(const char* src_file, const char* dst_file);
char get_base64char(int index);
void get_randomstr(char* buffer, int size);
int is_fileencode(const char* filename);

#define ENCRYPT_POSITION 0x60
#define ENCRYPT_OFFSET 0x80
#define ENCRYPT_STEP 4
#define ENCRYPT_HEADFLAG_LEN (int)sizeof(g_headflag)
#define SAFE_FREE(x) if ((x) != NULL) { free(x); (x) = NULL; }