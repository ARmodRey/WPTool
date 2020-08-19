#pragma once

#include "word processing.h"
#include <string>

class sentence{
private:
	std::string object; //memory area for writing raw data
	const char* delim = " ,;";
	int* word_count;
	std::string* components; //array with components of sentence
	void get_quan_components(const char *,const char*);//counts the number of words
	void split_string(const char*, std::string*, const char*);
public:
	sentence() {};
	sentence(const char*, const char*);// constructors
	sentence(char*, const char*);
	int get_count_of_word();
	int get_size();
	void add(std::string ,int);
	std::string get_delim() { return delim; }
	std::string get_full_str() { return object; }
	void operator=(const char*); //if init with first constructor
	void operator=(char*);
	void operator=(sentence);
	std::string operator[](int);
	bool have(char); // if sentence have element return true
	bool have(std::string);
	bool have(std::string[]);
	bool have(sentence);
	int qual_components_with(char sim);
	int component_number_with(char sim);
	void clear(int number) { components[number] = ""; }
};