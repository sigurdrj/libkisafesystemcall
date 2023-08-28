#include <iostream>
#include <cstdlib>

#include "libkisafesystemcall.hpp"

using namespace libkisafesystemcall;

int main(){
	std::cout << "Your system() shell: \x1b[0;36m" << std::flush;
	system("ps -p $$ -o comm=");
	std::cout << "\x1b[0m\n";

	std::cout << "No sanitization: \x1b[0;32mecho $SHELL\x1b[0m\n";
	system("echo $SHELL");
	std::cout << '\n';

	std::cout << "sh sanitization: \x1b[0;32mecho " + sh::sanitize_argument("$SHELL") << "\x1b[0m\n";
	system(("echo " + sh::sanitize_argument("$SHELL")).c_str());
	std::cout << '\n';

	std::cout << "bash sanitization: \x1b[0;32mecho " + bash::sanitize_argument("$SHELL") << "\x1b[0m\n";
	system(("echo " + bash::sanitize_argument("$SHELL")).c_str());
}
