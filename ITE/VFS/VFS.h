#ifndef VFS_H
#define VFS_H

struct NodesFiles_ {




} NodesFiles;


typedef struct super_block_
{
    int s_ninodes;
    int s_nzones;
    struct NodesFiles *s_firstdatazone;
    int s_zone_size;
    int s_max_size;
    int s_zone;
    int s_state;

} super_block;


#endif // VFS_H
