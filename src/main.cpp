#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

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

void exec_cmd(const std::vector<std::string>& tkns) {
	if (tkns.empty()) return;

	pid_t pid = fork();

	if (pid == -1) {
		std::cerr << "Error: Fork failed.\n";
		return;
	}

	if (pid == 0) {
		char* args[tkns.size() + 1];
		for (size_t i = 0; i < tkns.size(); ++i) {
			args[i] = const_cast<char*>(tkns[i].c_str());
		}
		args[tkns.size()] = nullptr; // Null-terminate the array

		if (execvp(args[0], args) == -1) {
			std::cerr << "Error: Command not found: " << tkns[0] << std::endl;
		}
		exit(1);
	} else {
		waitpid(pid, nullptr, 0);
	}
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

		exec_cmd(tkns);
	}

	return 0;
}