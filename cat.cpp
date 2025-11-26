#include <iostream>
#include <fstream>
#include <cstdio>

int
main(int argc, char **argv)
{
    if (argc > 2) {
        std::fprintf(stderr, "Usage: cat [file]\n");
        return 1;
    }

    std::istream* in = &std::cin;
    std::ifstream file;

    if (argc == 2) {
        file.open(argv[1], std::ios::in | std::ios::binary);
        if (!file) {
            std::perror(argv[1]);
            return 1;
        }
        in = &file;
    }

    std::cout << in->rdbuf();
    if (!std::cout) return 1;

    return 0;
}
