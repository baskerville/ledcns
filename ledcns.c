#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/kd.h>

int main(int argc, char *argv[])
{
    int fd;
    unsigned char state;
    if (argc < 2 || sscanf(argv[1], "%hhu", &state) != 1 || (fd = open("/dev/console", O_WRONLY)) == -1)
        return EXIT_FAILURE;
    ioctl(fd, KDSETLED, state);
    close(fd);
    return EXIT_SUCCESS;
}
