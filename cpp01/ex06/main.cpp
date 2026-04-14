#include "Harl.hpp"

int main(int argc, char** argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}

	harl.filter(argv[1]);

	return (0);
}
