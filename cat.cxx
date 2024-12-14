#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>


int get_file_line_count()
{
    std::string s;
    std::ifstream file("support.txt");
    int count = 0;

    while (getline(file, s))
        count++;

    file.close();

    return count;
}

std::string get_message_from_line(int random_line)
{
    std::string s;
    std::ifstream file("support.txt");
    int line = 0;

    while (getline(file, s))
    {
        if (line == random_line)
        {
            file.close();
            s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
            return s;
        }
        line++;
    }

    file.close();

    return NULL;
}

void print_bubble(std::string message)
{
    int message_length = message.length();
    int bubble_width = message_length + 4;

    // top of bubble
    std::cout << std::string(3, ' ');
    std::cout << std::string(bubble_width - 1, '_') << std::endl;

    // middle of bubble
    std::cout << "  / " << std::string(bubble_width - 2, ' ') << " \\" << std::endl;

    // message
    std::cout << " |   " << message << "   |" << std::endl;

    // bottom of bubble
    std::cout << "  \\ " << std::string(bubble_width - 2, '_') << " /" << std::endl;
}

void print_cat()
{
    std::string s;
    std::ifstream file("cat.txt");
    while (getline(file, s))
        std::cout << s << std::endl;
    file.close();
}

int main(void)
{
    srand(time(NULL)); // seed the random number generator

    int line_count = get_file_line_count();
    int random_line = rand() % line_count;
    std::cout << random_line << std::endl;
    std::string message = get_message_from_line(random_line);

    print_bubble(message);
    print_cat();

    return 0;
}
