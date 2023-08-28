#include <iostream>
#include <string>
#include <cstdlib>

#include "../libkisafesystemcall.hpp"

using namespace libkisafesystemcall;
using std::string;

string gen_rnd_str(const unsigned long long &len, const string &alphabet){
	string ret = "";

	for (unsigned long long i = 0; i < len; i++)
		ret += alphabet[std::rand() / double(RAND_MAX) * alphabet.size()];

	return ret;
}

int main(){
	std::srand(time(nullptr));

	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,.-/"; // Backslash doesn't work, ofc

	for (unsigned i = 0; i < 100; i++){
		string rndStr = gen_rnd_str(20, alphabet);

		system(("./check " + rndStr + " " + sh::sanitize_argument(rndStr)).c_str());
	}
}
