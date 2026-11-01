#include <stdio.h>
#include <string.h>


#include "mygit.h"

int cmd_init(void)
{
    const char *head = "ref: refs/heads/main\n";



    if (make_dir(GIT_DIR) == -1)
        return 1;
    if (make_dir(OBJECTS_DIR) == -1)
        return 1;
    if (make_dir(REFS_DIR) == -1)
        return 1;
    if (make_dir(HEADS_DIR) == -1)
        return 1;
    if (write_file(HEAD_FILE, head, strlen(head)) == -1)
        return 1;
    printf("initialized emptyrepository in %s/\n", GIT_DIR);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)


    {
        fprintf(stderr, "usage: %s <command> [args]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "init") == 0)
        return cmd_init();


    fprintf(stderr, "%s: unknown command '%s'\n", argv[0], argv[1]);
    return 1;
}
