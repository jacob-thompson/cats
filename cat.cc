#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main(void)
{
    std::string s;
    std::ifstream file("art.txt");

    while (getline(file, s))
        std::cout << s << "\n";

    file.close();
}
