#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// std::string read_in(std::string &prompt) {
// 	std::cout << *prompt; // Shell prompt
// 	std::string in;
// 	std::getline(std::cin, in);
// 	return in;
// }

std::string read_in() {
	std::cout << "> "; // Shell prompt
	std::string in;
	std::getline(std::cin, in);
	return in;
}

std::vector<std::string> parse_in(const std::string& in) {
	std::istringstream stream(in);
	std::string tkn;
	std::vector<std::string> tkns;

	while (stream >> tkn) {
		tkns.push_back(tkn);
	}

	return tkns;
}



int main() {
	std::string in;

	while (true) {
		in = read_in();

		if (in == "exit") {
			std::cout << "Exiting shell...\n";
			break;
		}

		std::vector<std::string> tkns = parse_in(in);

		std::cout << "Inputs received:\n"; // Placeholder to watch parsing
		for (const auto& tkn : tkns) {
			std::cout << " " << tkn << std::endl;
		}
	}

	return 0;
}