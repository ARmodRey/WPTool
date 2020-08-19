#include "vocabulary.h"

vocabulary::vocabulary(std::string rec) {
	sentence* temp = new sentence(rec.c_str()," ");
	this->rec = new std::string(rec);
	associations.push_back(*temp);
	delete temp;
}

vocabulary::vocabulary(std::string rec, sentence sent) {
	this->rec = new std::string(rec);
	sentence* temp = new sentence(rec.c_str(), " ");
	associations.push_back(*temp);
	associations.push_back(sent);
	delete temp;
}

void vocabulary::add(sentence sent) {
	associations.push_back(sent);
}

void vocabulary::add(std::string str) {
	sentence* temp = new sentence(str.c_str(), " ");
	associations.push_back(*temp);
	delete temp;
}

bool vocabulary::have(std::string str) {
	for (auto itr = associations.begin(); itr != associations.end(); itr++)
		if (str == itr->get_full_str())
			return true;
	return false;
}

bool vocabulary::have(sentence sent) {
	for (auto itr = associations.begin(); itr != associations.end(); itr++)
		if (sent.get_full_str() == itr->get_full_str())
			return true;
	return false;
}