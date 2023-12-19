#include "./main.h"

int main()
{
    const char inputFile[] = "./tosfs.h";
    int* fileToOpen = malloc(sizeof(int));
    char** dataToMap = malloc(sizeof(char*));
    struct stat* fileStats = malloc(sizeof(struct stat));

    int returnValueFromMapping = mapFileInData(inputFile, dataToMap, fileToOpen, fileStats);
    if (EXIT_FAILURE == returnValueFromMapping)
    {
        return EXIT_FAILURE;
    }

    ///struct tosfs_superblock myStructure {TOSFS_MAGIC, };
    
    int returnValueFromUnmapping = unmapData(*dataToMap, fileToOpen, fileStats);
    if (EXIT_FAILURE == returnValueFromUnmapping)
    {
        return EXIT_FAILURE;
    }

    printf("Everything worked!\n");
    return EXIT_SUCCESS;
}
