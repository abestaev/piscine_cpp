#include <iostream>
#include <string>
#include <cctype>

void megaphone(char *str)
{
    for (int i = 0; str[i]; i++)
        std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
        {
            megaphone(argv[i]);
            // if (i < argc - 1)
            //     std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
