#include "word processing.h"

int qual_in_str(std::string str, char sim) {
	return std::count(str.begin(), str.end(), sim);
}

char sim_in_str(std::string str, std::string simbs) {
	for (size_t i = 0; i < simbs.length(); i++)
		if (qual_in_str(str, simbs[i]) > 0)
			return simbs[i];
	return ' ';
}

bool is_digits(std::string str) {
	return str.find_first_not_of("-,.0123456789") == std::string::npos;
}

int get_start_index(std::string source, std::string object) {
	int find = 0, st = 0;
	for (int i = 0; i < source.length(); i++) {
		if (source[i] == object[find]) {	
			if (find == 0)
				st = i;
			if (find == object.length() - 1)
				return st;
			find++;	
		}
		else {
			find = 0;
		}
	}
	return -1;
}