#include "sentence.h"

void sentence::get_quan_components(const char* source, const char* delim) {
	char* token, * next_token = NULL, p[1024];
	word_count = new int;
	*word_count = 0;
	strcpy_s(p, source);//clone
	token = strtok_s(p, delim, &next_token);//delim
	for (; token != NULL; token = strtok_s(NULL, delim, &next_token), (*word_count)++);
	delete token, next_token;
	components = new std::string[*word_count];//init
}

void sentence::split_string(const char* source, std::string* parts_of_string, const char* delim) {
	char* token, * next_token = NULL, p[1024];
	strcpy_s(p, source);
	token = strtok_s(p, delim, &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, delim, &next_token), i++)
		parts_of_string[i] = token;
	delete token, next_token;
}

sentence::sentence(const char* source, const char* delim) {
	object = source;
	get_quan_components(this->object.c_str(), this->delim);//set size
	split_string(this->object.c_str(), components, this->delim);//delim
}

sentence::sentence(char* source, const char* delim) {
	object = source;
	get_quan_components(this->object.c_str(), this->delim);//set size
	split_string(this->object.c_str(), components, this->delim);//delim
}

int sentence::get_count_of_word() {
	return *word_count;
}

int sentence::get_size() {
	return object.length();
}

void sentence::operator=(sentence sent) {
	delim = sent.get_delim().c_str();
	*this=sent.get_full_str().c_str();
}

void sentence::operator=(const char* source){
	object = source;
	get_quan_components(this->object.c_str(), this->delim);//set size
	split_string(this->object.c_str(), components, this->delim);//delim
}

void sentence::operator=(char* source) {
	object = source;
	get_quan_components(this->object.c_str(), this->delim);//set size
	split_string(this->object.c_str(), components, this->delim);//delim
}

std::string sentence::operator[](int index) {
	return components[index];
}

bool sentence::have(char sim) {
	for (size_t i = 0; i <object.length(); i++)
		if (object[i] == sim)
			return true;
	return false;
}

bool sentence::have(std::string word) {
	for (int i = 0; i < get_count_of_word(); i++)
		if (word == components[i])
			return true;
	return false;
}

bool sentence::have(std::string arr[]) {
	for (int j = 0; j < *this->word_count; j++)
		for (int i = 0; i < sizeof(arr); i++)
			if (arr[i] == components[j])
				return true;
	return false;
}

bool sentence::have(sentence str) {
	int* pecent = new int;
	*pecent = 0;
	for (size_t i = 0; i != str.get_count_of_word(); i++)
		if (have(str[i]))
			(*pecent)++;
	if (*pecent == str.get_count_of_word())
		return true;
	else
		return false;
}

int sentence::qual_components_with(char sim) {
	int qual = 0;
	if (have(sim))
		for (int i = 0; i < this->get_count_of_word(); i++) {
			if (qual_in_str(components[i], sim) != 0) {
				qual++;
			}
		}
	return qual;
}

int sentence::component_number_with(char sim) {
	if (have(sim)) {
		for (int i = 0; i < this->get_count_of_word(); i++) 
			if (qual_in_str(components[i], sim) != 0)
				return i;
	}
	else
		return -1;
}

void sentence::add(std::string data, int index) {
	int st = get_start_index(get_full_str(),components[index]);
	object.erase(st,components[index].length());
	object.insert(st,data);
	components[index] = data;
}