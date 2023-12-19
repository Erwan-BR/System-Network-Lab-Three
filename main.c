#include "./main.h"

int main()
{
    const char inputFile[] = "test_tosfs_files";
   /* int* fileToOpen = malloc(sizeof(int));
    char** dataToMap = malloc(sizeof(char*));
    struct stat* fileStats = malloc(sizeof(struct stat));

    int returnValueFromMapping = mapFileInData(inputFile, dataToMap, fileToOpen, fileStats);
    if (EXIT_FAILURE == returnValueFromMapping)
    {
        return EXIT_FAILURE;
    }*/



    //struct tosfs_superblock* myStructure = malloc(sizeof(struct tosfs_superblock));
    struct tosfs_superblock* myStructure;

    int fileToOpen = open(inputFile, O_RDWR);
    if (-1 == fileToOpen)
    {
        perror("ERROR on open");
        return EXIT_FAILURE;
    }

    myStructure = (struct tosfs_superblock*) mmap(NULL, sizeof(struct tosfs_superblock), PROT_READ, MAP_SHARED, fileToOpen, 0);

    //memcpy(myStructure, *dataToMap, sizeof(struct tosfs_superblock));
    

    printf("magic number: %x\n", myStructure->magic);
    printf("block bitmap: " PRINTF_BINARY_PATTERN_INT32"\n", PRINTF_BYTE_TO_BINARY_INT32(myStructure->block_bitmap));
    printf("inode bitmap: " PRINTF_BINARY_PATTERN_INT32"\n", PRINTF_BYTE_TO_BINARY_INT32(myStructure->inode_bitmap));
    printf("block size:   %x\n", myStructure->block_size);
    printf("blocks:       %x\n", myStructure->blocks);
    printf("inodes:       %x\n", myStructure->inodes);
    printf("root inode:   %x\n", myStructure->root_inode);
    
    /*int returnValueFromUnmapping = unmapData(*dataToMap, fileToOpen, fileStats);
    if (EXIT_FAILURE == returnValueFromUnmapping)
    {
        return EXIT_FAILURE;
    }*/

    printf("No EXIT_FAILURE!\n");
    return EXIT_SUCCESS;
}
