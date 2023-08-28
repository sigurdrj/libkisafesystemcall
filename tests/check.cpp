#include <iostream>
#include <cstring>

int main(int argc, char *argv[]){
	if (argc != 3){
		std::cout << "Not enough arguments\n";
		return 1;
	}

	if (strcmp(argv[1], argv[2]) != 0){
		std::cout << "Failed between \"" << argv[1] << "\" and \"" << argv[2] << "\"\n";
	}
}
