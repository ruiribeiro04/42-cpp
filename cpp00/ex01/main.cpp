#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(){
    std::string input;

    while (std::cout << "> " && std::getline(std::cin, input)){

        if (input == "ADD")
            std::cout << "[PLACEHOLDER ADD MODAL HERE]" << std::endl;
        else if (input == "SEARCH")
            std::cout << "[PLACEHOLDER SEARCH MODAL HERE]" << std::endl;
        else if (input == "EXIT")
            return (0);
        else {
        }
    }
}