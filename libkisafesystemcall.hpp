#ifndef LIBKISAFESYSTEMCALL
#define LIBKISAFESYSTEMCALL

#include <string>

using std::string;

namespace libkisafesystemcall{
	namespace bash{
		string sanitize_argument(const string &input){
			string ret = "";

			const string hexChars = "0123456789ABCDEF";
			for (char c : input){
				ret += "\\x";
				ret += hexChars[(c >> 4) & 0x0F];
				ret += hexChars[       c & 0x0F];
			}

			return "$'" + ret + "'"; // Could surround it with spaces, but probably shouldn't
		}
	}

	namespace sh{
		string sanitize_argument(const string &input){
			string ret = "";

			for (char c : input){
				ret += "\\0";
				ret.push_back('0' + (c >> 6 & 7));
				ret.push_back('0' + (c >> 3 & 7));
				ret.push_back('0' + (     c & 7));
			}

			return "$(printf '%b' '" + ret + "')"; // Could surround it with spaces, but probably shouldn't
		}
	}
}

#endif // LIBKISAFESYSTEMCALL
