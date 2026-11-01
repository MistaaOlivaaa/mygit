


#ifndef MYGIT_H
#define MYGIT_H

#include <stddef.h>

#define GIT_DIR      ".git"
#define OBJECTS_DIR  ".git/objects"
#define REFS_DIR     ".git/refs"
#define HEADS_DIR    ".git/refs/heads"
#define REMOTES_DIR  ".git/refs/remotes"
#define HEAD_FILE    ".git/HEAD"
#define INDEX_FILE   ".git/index"
#define STASH_FILE   ".git/refs/stash"
#define MERGE_HEAD   ".git/MERGE_HEAD"
#define CONFIG_FILE  ".git/config"

#define SHA1_RAW_LEN 20
#define SHA1_HEX_LEN 40
#define PATH_LEN     4096

int make_dir(const char *path);
unsigned char *read_file(const char *path, size_t *size);
int write_file(const char *path, const void *data, size_t len);
void sha1_to_hex(const unsigned char raw[SHA1_RAW_LEN],char hex[SHA1_HEX_LEN + 1]);

void sha1_compute(const void *data, size_t len,unsigned char out[SHA1_RAW_LEN]);

int write_object(const char *type, const void *data, size_t len,char hex_out[SHA1_HEX_LEN + 1]);
unsigned char *read_object(const char *hex, char *type, size_t *size);

int cmd_init(void);
int cmd_hash_object(int argc, char **argv);
int cmd_cat_file(int argc, char **argv);
int cmd_add(int argc, char **argv);
int cmd_write_tree(void);
int cmd_commit(int argc, char **argv);
int cmd_log(int argc, char **argv);
int cmd_status(void);
int cmd_diff(int argc, char **argv);
int cmd_branch(int argc, char **argv);
int cmd_checkout(int argc, char **argv);
int cmd_merge(int argc, char **argv);
int cmd_pull(int argc, char **argv);
int cmd_push(int argc, char **argv);
int cmd_stash(int argc, char **argv);

#endif



