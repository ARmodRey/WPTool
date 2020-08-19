#include "string_content.h"

// class constructor 
WPTool::string_content::string_content(){
    this->object = new std::string; // init object of string
    this->delim = new std::string; // init object of delimiter
}

// class constructor 
// param 1: source string to retrieve content
// param 2: characters to separate the string
WPTool::string_content::string_content(std::string source, std::string delim){
    this->object = new std::string(source); // init object of string
    this->delim = new std::string(delim); // init object of delimiter
#ifdef WIN32 
    char* token, * next_token = NULL, p[1024];
	strcpy_s(p, source);
	token = strtok_s(p, delim, &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, delim, &next_token), i++)
		parts_of_string[i] = token;
	delete token, next_token;
#else
    char* token, p[source.length()];
	strcpy(p, source.c_str());
	token = strtok(p, delim.c_str());
	for (int i = 0; token != NULL; token = strtok(NULL, delim.c_str()), i++){
        components.push_back(token);
    }
	delete token;
#endif
}

// class destructor
WPTool::string_content::~string_content(){
    if(!components.empty()){
        components.clear(); // free vect
    }
    delete object; // free memory
    delete delim; 
}

// function get_string
std::string WPTool::string_content::get_string(){
    return *object;
}

// function get_delim
std::string WPTool::string_content::get_delim(){
    return *delim;
}

// function get_size
int WPTool::string_content::get_size(){
    return components.size();
}

// function set_string 
// param 1: source string to retrieve content
void WPTool::string_content::set_string(std::string source){
    if(!components.empty()){
        components.clear(); // free vect
    }
    *object = source;
#ifdef WIN32 
    char* token, * next_token = NULL, p[1024];
	strcpy_s(p, source);
	token = strtok_s(p, delim->c_str(), &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, delim->c_str(), &next_token), i++)
		components.push_back(token);
	delete token, next_token;
#else
    char* token, p[source.length()];
	strcpy(p, source.c_str());
	token = strtok(p, delim->c_str());
	for (int i = 0; token != NULL; token = strtok(NULL, delim->c_str()), i++){
        components.push_back(token);
    }
	delete token;
#endif
}

// function set_delim 
// param 1: characters to separate the string
void WPTool::string_content::set_delimetr(std::string delim){
    if(!components.empty()){
        components.clear(); // free vect
    }
    *this->delim = delim;
#ifdef WIN32 
    char* token, * next_token = NULL, p[1024];
	strcpy_s(p, object->c_str());
	token = strtok_s(p, delim, &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, delim, &next_token), i++)
		components.push_back(token);
	delete token, next_token;
#else
    char* token, p[object->length()];
	strcpy(p, object->c_str());
	token = strtok(p, delim.c_str());
	for (int i = 0; token != NULL; token = strtok(NULL, delim.c_str()), i++){
        components.push_back(token);
    }
	delete token;
#endif
}

// operatorr -> []
// param 1: index of component
std::string WPTool::string_content::operator[](int index){
    return components.at(index);
}

// function have
// param 1: search char 
bool WPTool::string_content::have(char sim){
    if(this->object->find(sim) != std::string::npos){
        return true;
    }
    return false;
}

// function have 
// param 1: search string
bool WPTool::string_content::have(std::string str){
    if(this->object->find(str) != std::string::npos){
        return true;
    }
    return false;
}

