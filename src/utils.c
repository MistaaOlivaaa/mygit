#include "mygit.h"



#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdio.h>

#include  <errno.h>
#include  <sys/stat.h>
#include  <sys/types.h>





int make_dir(const char *path)
{
    if (mkdir(path, 0755) == 0)
        return 0;
    if (errno == EEXIST)
        return 0;
    perror(path);
    return -1;
}



  int write_file(const char *path, const void *data, size_t len)
  {
    FILE *f = fopen(path, "wb");

    if(!f)
    {
      perror(path);
      return -1;

    }

    if (len > 0 && fwrite(data, 1, len, f) != len)
    {
        perror(path);
      fclose(f);
        return -1;
    }
    if (fclose(f) != 0)
    {
        perror(path);
        return -1;
    }
    return 0;


}


unsigned char *read_file(const char *path, size_t *size)
{
    FILE *f = fopen(path, "rb");
    unsigned char *buf;
    long n;
 
    if (!f)
    {
        perror(path);
        return NULL;
    }
    if (fseek(f, 0, SEEK_END) != 0 || (n = ftell(f)) < 0)
    {
        perror(path);
        fclose(f);
        return NULL;
    }
    rewind(f);
    buf = malloc((size_t)n + 1);
    if (!buf)
    {
        perror("malloc");
        fclose(f);
        return NULL;
    }
    if (fread(buf, 1, (size_t)n, f) != (size_t)n)
    {
        perror(path);
        free(buf);
        fclose(f);
        return NULL;
    }
    buf[n] = '\0';
    fclose(f);
    if (size)
        *size = (size_t)n;
    return buf;
}
 
void sha1_to_hex(const unsigned char raw[SHA1_RAW_LEN],char hex[SHA1_HEX_LEN + 1])
{
    static const char digits[] = "0123456789abcdef";
    int i;
 
    for (i = 0; i < SHA1_RAW_LEN; i++)
    {
        hex[2 * i] = digits[raw[i] >> 4];
        hex[2 * i + 1] = digits[raw[i] & 0x0F];
    }
    hex[SHA1_HEX_LEN] = '\0';
}









