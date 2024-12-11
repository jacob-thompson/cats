#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 30

int main(void)
{
    char* s = malloc(sizeof(char) * BUFFER_SIZE);
    FILE* file = fopen("art.txt", "r");
    while (fgets(s, BUFFER_SIZE, file) != NULL)
        printf("%s", s);

    fclose(file);

    return 0;
}
