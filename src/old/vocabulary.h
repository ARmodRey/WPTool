#pragma once

#include <vector>
#include "sentence.h"

class vocabulary{
private:
	std::string* rec;
	std::vector<sentence> associations;
public:
	vocabulary(std::string);
	vocabulary(std::string,sentence);
	void add(sentence);
	void add(std::string);
	bool have(std::string);
	bool have(sentence);
};

