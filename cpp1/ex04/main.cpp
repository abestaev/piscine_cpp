#include <string>
#include <iostream>
#include <fstream>

void replace(std::ifstream &inputFile, std::ofstream &outputFile, std::string s1, std::string s2)
{
    std::string line;

    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            // line.replace(pos, s1.length(), s2);
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0') {
        std::cout << "Empty arguments are invalid" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cout << "Error: could not create file" << std::endl;
        inputFile.close();
        return 1;
    }

    replace(inputFile, outputFile, s1, s2);
    inputFile.close();
    outputFile.close();
    return 0;
}