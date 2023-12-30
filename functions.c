#include "./functions.h"

void printMyText()
{
    printf("Hello World! Work is not done yet...\n");
}

/// @brief Map a file into memory.
/// @param inputFile Path of the input file.
/// @param dataToMap pointer to the data to map.
/// @param fileToOpen Pointer to an int, used to retrieve the value (the file has to be close later)
/// @return EXIT_SUCESS if everything work fine, EXIT_FAILURE either.
int mapFileInData(const char inputFile[], void** dataToMap, int* fileToOpen, struct stat* statsOfFile)
{
    // 1. Open the file
    *fileToOpen = open(inputFile, O_RDWR);
    if (-1 == *fileToOpen)
    {
        perror("ERROR on open");
        return EXIT_FAILURE;
    }

    // 2. Get the size of the file
    int fileStats = fstat(*fileToOpen, statsOfFile);
    if (-1 == fileStats)
    {
        perror("ERROR on fstat");
        return EXIT_FAILURE;
    }

    // 3. Mapping the file into memory
    *dataToMap = mmap(NULL, (*statsOfFile).st_size, PROT_READ | PROT_WRITE, MAP_SHARED, *fileToOpen, 0);

    return EXIT_SUCCESS;
}

/// @brief End the mapping and propagate the info.
/// @param mappedData Pointer to the mapped data.
/// @param fileToClose File that needs to be close.
/// @param statsOfFile Statistics of the file that needs to be closed. Used to know the size of the file to close.
/// @return EXIT_SUCESS if everything work fine, EXIT_FAILURE either.
int unmapData(char* mappedData, int* fileToClose, struct stat* statsOfFile)
{
    int unmappedData = munmap(mappedData, (*statsOfFile).st_size);

    int returnValue = EXIT_SUCCESS;
    if (-1 == unmappedData)
    {
        perror("ERROR on munmap");
        returnValue = EXIT_FAILURE;
    }
    int fsyncData = fsync(*fileToClose);
    if (-1 == fsyncData)
    {
        perror("ERROR on fsync");
        returnValue = EXIT_FAILURE;
    }
    int closedFile = close(*fileToClose);
    if (-1 == closedFile)
    {
        perror("ERROR on close");
        returnValue = EXIT_FAILURE;
    }

    return returnValue;
}

/// @brief Function used to mount the file system.
/// @return 1 if an error occured, either 0.
int mountFileSystem(int argc, char* argv[])
{
    struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
    struct fuse_chan *ch;
    char *mountpoint;
    int err = -1;

    if (-1 != fuse_parse_cmdline(&args, &mountpoint, NULL, NULL) && NULL != (ch = fuse_mount(mountpoint, &args)))
    {
        struct fuse_session *se;

        se = fuse_lowlevel_new(&args, &ll_oper, sizeof(ll_oper), NULL);
        if (se != NULL)
        {
            if (fuse_set_signal_handlers(se) != -1)
            {
                fuse_session_add_chan(se, ch);
                err = fuse_session_loop(se);
                fuse_remove_signal_handlers(se);
                fuse_session_remove_chan(ch);
            }
            fuse_session_destroy(se);
        }
        fuse_unmount(mountpoint, ch);
    }
    fuse_opt_free_args(&args);

    return err ? 1 : 0;
}

// int getTableOfInode(void** mappedData, struct tosfs_inode* tableOfInode)
// {
//     struct tosfs_superblock* myStructure = *mappedData;
//     tableOfInode = (struct tosfs_inode*) (&myStructure + 1);

//     return EXIT_SUCCESS;
// }