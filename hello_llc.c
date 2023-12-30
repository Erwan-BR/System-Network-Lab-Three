#include "./hello_llc.h"

/*static void fuse_lookup(fuse_req_t req, fuse_ino_t parent, const char *name)
{
    ;
}

extern void** dataToMap;

static void fuse_getattr(fuse_req_t req, fuse_ino_t ino, struct fuse_file_info *fi)
{
    struct tosfs_superblock* myStructure = *dataToMap;

    struct tosfs_inode* inode = &myStructure + 1;
    inode += ino;

    struct stat statsOfFile;
    memset(&statsOfFile, 0, sizeof(statsOfFile));

    // __nlink_t st_nlink;
    // __mode_t st_mode;

    statsOfFile.st_nlink = inode->nlink;

    /*int value = 0;
    fuse_ino_t inode = statsOfFile.st_ino;
    switch (inode)
    {
        case 1:
            statsOfFile.st_mode = S_IFDIR | 0755;
            statsOfFile.st_nlink = 2;
            break;

        case 2:
            statsOfFile.st_mode = S_IFREG | 0444;
            statsOfFile.st_nlink = 1;
            statsOfFile.st_size = strlen(hello_str);
            break;

        default:
            value = -1;
	}*/
}


	struct stat stbuf;

	(void) fi;

	memset(&stbuf, 0, sizeof(stbuf));
	if (hello_stat(ino, &stbuf) == -1)
		fuse_reply_err(req, ENOENT);
	else
		fuse_reply_attr(req, &stbuf, 1.0);



    stbuf->st_ino = ino;
	switch (ino) {
	case 1:
		stbuf->st_mode = S_IFDIR | 0755;
		stbuf->st_nlink = 2;
		break;

	case 2:
		stbuf->st_mode = S_IFREG | 0444;
		stbuf->st_nlink = 1;
		stbuf->st_size = strlen(hello_str);
		break;

	default:
		return -1;
	}
	return 0;


static void fuse_readdir(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off, struct fuse_file_info *fi)
{
    ;
}

static void fuse_open(fuse_req_t req, fuse_ino_t ino, struct fuse_file_info *fi)
{
    ;
}

static void fuse_read(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off, struct fuse_file_info *fi)
{
    ;
}*/
