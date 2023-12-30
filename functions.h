#ifndef functions_h
#define functions_h

#define FUSE_USE_VERSION 26

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "./hello_llc.h"

typedef struct tosfs_superblock superBlock;

void printMyText();

int mapFileInData(const char inputFile[], void** dataToMap, int* fileToOpen, struct stat* statsOfFile);
int unmapData(char* mappedData, int* fileToClose, struct stat* statsOfFile);

#endif /* functions_h */
