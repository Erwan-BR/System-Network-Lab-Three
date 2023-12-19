#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

void printMyText();

int mapFileInData(const char inputFile[], char** dataToMap, int* fileToOpen, struct stat* statsOfFile);
int unmapData(char* mappedData, int* fileToClose, struct stat* statsOfFile);

#endif /* functions_h */
