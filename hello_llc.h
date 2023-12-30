#ifndef HELLO_LLC_H
#define HELLO_LLC_H

#include <fuse/fuse_lowlevel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/stat.h>

// static void fuse_lookup(fuse_req_t req, fuse_ino_t parent, const char *name);
// static void fuse_getattr(fuse_req_t req, fuse_ino_t ino, struct fuse_file_info *fi);
// static void fuse_readdir(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off, struct fuse_file_info *fi);
// static void fuse_open(fuse_req_t req, fuse_ino_t ino, struct fuse_file_info *fi);
// static void fuse_read(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off, struct fuse_file_info *fi);

static struct fuse_lowlevel_ops ll_oper __attribute__((unused)) = {
    // .lookup     = fuse_lookup,
    // .getattr    = fuse_getattr,
    // .readdir    = fuse_readdir,
    // .open       = fuse_open,
    // .read       = fuse_read,
};

#endif /* HELLO_LLC_H */