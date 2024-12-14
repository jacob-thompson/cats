#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 64

int randomNumber(int minNumber, int maxNumber)
{

    if (minNumber == maxNumber)
        return minNumber;

    // swap the numbers if minNumber is greater than maxNumber
    if (minNumber > maxNumber) {
        minNumber ^= maxNumber;
        maxNumber ^= minNumber;
        minNumber ^= maxNumber;
    }

    int range = maxNumber - minNumber + 1;

    // chop off the high end of rand()
    // so that the entire range is evenly divided by range
    int x;
    while (1) {
        x = rand();
        if (x < RAND_MAX / range * range)
            break;
    }

    return x % range + minNumber;
}

int get_file_line_count()
{
    FILE* file = fopen("support.txt", "r");
    char* s = malloc(sizeof(char) * BUFFER_SIZE);
    int count = 0;

    while (fgets(s, BUFFER_SIZE, file) != NULL)
        count++;

    free(s);
    fclose(file);

    return count;
}

char* get_message_from_line(int random_line)
{
    FILE* file = fopen("support.txt", "r");
    char* s = malloc(sizeof(char) * BUFFER_SIZE);
    int line = 0;

    while (fgets(s, BUFFER_SIZE, file) != NULL)
    {
        if (line == random_line)
        {
            fclose(file);
            s[strcspn(s, "\n")] = 0;
            return s;
        }
        line++;
    }

    fclose(file);

    return NULL;
}

void print_bubble(char* message)
{
    int message_length = strlen(message);
    int bubble_width = message_length + 4;

    // top of bubble
    printf("%*c", 3, ' ');
    for (int i = 0; i < bubble_width; i++)
        printf("_");
    printf("\n");

    // middle of bubble
    printf("  / ");
    printf("%*c", bubble_width - 2, ' ');
    printf(" \\\n");

    // message
    printf(" |   %s   |\n", message);

    // bottom of bubble
    printf("  \\ ");
    for (int i = 0; i < bubble_width - 2; i++)
        printf("_");
    printf(" /\n");
}

void print_cat()
{
    char* s = malloc(sizeof(char) * BUFFER_SIZE);
    FILE* file = fopen("cat.txt", "r");
    while (fgets(s, BUFFER_SIZE, file) != NULL)
        printf("%s", s);
    fclose(file);
    free(s);
}

int main(void)
{
    srand(time(NULL)); // seed the random number generator

    int line_count = get_file_line_count();
    int random_line = randomNumber(0, line_count - 1);
    char* message = get_message_from_line(random_line);

    print_bubble(message);
    print_cat();

    free(message);
    return 0;
}
