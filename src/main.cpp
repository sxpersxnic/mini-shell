#include <iostream>
#include <string>
#include <cstdlib>

// std::string readInput(std::string &prompt) {
// 	std::cout << *prompt; // Shell prompt
// 	std::string input;
// 	std::getline(std::cin, input);
// 	return input;
// }

std::string readInput() {
	std::cout << "> "; // Shell prompt
	std::string input;
	std::getline(std::cin, input);
	return input;
}

int main() {
	std::string input;

	while (true) {
		input = readInput();

		if (input == "exit") {
			std::cout << "Exiting shell...\n";
			break;
		}

		std::cout << "Input received: " << input << std::endl;
	}

	return 0;
}