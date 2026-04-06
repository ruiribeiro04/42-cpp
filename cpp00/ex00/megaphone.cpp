#include <iostream>
#include <cctype>

int main(int ac, char** av) {
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else{
        for(int s = 1; av[s] != NULL; s++){
            for (int c = 0; av[s][c] != '\0'; c++) {
                std::cout << (char)std::toupper((unsigned char)av[s][c]);
            }
        }
        std::cout << std::endl;
    }
    return (0);
}
