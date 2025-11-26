#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
    int fd = argc == 2 ? open(argv[1], O_RDONLY, 0) : 0;
    if (argc > 2 || fd == -1) return 1;

    int n;
    char buf[BUFSIZ];

    while ((n = read(fd, buf, BUFSIZ)) > 0)
        write(fd, buf, n);

    return close(fd) == -1 ? 1 : 0;
}
