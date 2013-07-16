#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/kd.h>

int main(int argc, char *argv[])
{
    int fd;
    unsigned char state;
    if (argc < 2 || sscanf(argv[1], "%hhu", &state) != 1) {
        printf("Usage: ledcns STATE\n");
        return EXIT_FAILURE;
    }
    if ((fd = open("/dev/console", O_WRONLY)) == -1) {
        perror("open");
        return EXIT_FAILURE;
    }
    if (ioctl(fd, KDSETLED, state) == -1) {
        perror("ioctl");
        return EXIT_FAILURE;
    }
    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
