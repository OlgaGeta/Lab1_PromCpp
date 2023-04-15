//
//  main.cpp
//  raii
//
//

#include <iostream>

#include "RAII/File.hpp"

int main() {
	try {
		bool isContinue = true;

		do
		{
			std::string filename, mode;

			std::cout << "Enter filename:\n";
			std::getline(std::cin, filename);

			std::cout << "Enter mode (w / r):\n";
			std::getline(std::cin, mode);

			File file(filename.data(), mode.data());

			if (!file.is_open())
				std::cout << "File is NOT open.\n";

			if (mode == "w")
			{
				std::string user_input;
				std::cout << "Enter text:\n";
				std::getline(std::cin, user_input);
				file << user_input;
				std::cout << "\nSuccessfully wrote to file.\n";
			}
			else
			{
				std::string s;

				while (file >> s)
					std::cout << s << " ";

				std::cout << "\nSuccessfully read from file.\n";
			}

			std::cout << "\nDo you want to continue?\n";
			std::string choice;
			std::cout << "Enter 'y' or 'Y' to continue or other for exit:\n";
			std::getline(std::cin, choice);

			if (choice != "y" && choice != "Y")
				isContinue = false;

		} while (isContinue);
	}
	catch (const std::runtime_error& e) {
		std::cerr << "EXCEPTION: " << e.what() << '\n';
	}
	return 0;
}
