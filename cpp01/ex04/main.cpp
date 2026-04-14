#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << "Error: Cannot open file " << filename << std::endl;
		return (1);
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		std::cout << "Error: Cannot create output file" << std::endl;
		inputFile.close();
		return (1);
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string result;
		size_t pos = 0;
		size_t foundPos;

		while ((foundPos = line.find(s1, pos)) != std::string::npos)
		{
			result += line.substr(pos, foundPos - pos);
			result += s2;
			pos = foundPos + s1.length();
		}
		result += line.substr(pos);
		outputFile << result << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return (0);
}
