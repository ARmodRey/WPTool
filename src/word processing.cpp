#include "word processing.h"

WPTool::string_vect WPTool::split_string(std::string source){
    WPTool::string_vect result;
#ifdef WIN32 
    char* token, * next_token = NULL, p[1024];
	strcpy_s(p, source);
	token = strtok_s(p, " \t", &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, " \t", &next_token), i++)
		result.push_back(token);
	delete token, next_token;
#else
    char* token, p[source.length()];
	strcpy(p, source.c_str());
	token = strtok(p," \t");
	for (int i = 0; token != NULL; token = strtok(NULL, " \t"), i++){
        result.push_back(token);
    }
	delete token;
#endif
    return result; 
}

WPTool::string_vect WPTool::split_string(std::string source, std::string delim){
    WPTool::string_vect result;
#ifdef WIN32 
    char* token, * next_token = NULL, p[1024];
	strcpy_s(p, source);
	token = strtok_s(p, delim.c_str(), &next_token);
	for (int i = 0; token != NULL; token = strtok_s(NULL, delim.c_str(), &next_token), i++)
		result.push_back(token);
	delete token, next_token;
#else
    char* token, p[source.length()];
	strcpy(p, source.c_str());
	token = strtok(p, delim.c_str());
	for (int i = 0; token != NULL; token = strtok(NULL, delim.c_str()), i++){
        result.push_back(token);
    }
	delete token;
#endif
    return result;
}

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
    this->components = split_string(*this->object, *this->delim);
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

void WPTool::string_content::set(std::string & param, std::string str){
    if(!components.empty()){
        components.clear(); // free vect
    }
    param = str;
    components = split_string(*this->object, *this->delim);
}

// function set_string 
// param 1: source string to retrieve content
void WPTool::string_content::set_string(std::string source){
    set(*this->object,source);
}

// function set_delim 
// param 1: characters to separate the string
void WPTool::string_content::set_delimetr(std::string delim){
    set(*this->delim,delim);
}

// operator -> []
// param 1: index of component
std::string WPTool::string_content::operator[](int index){
    return components.at(index);
}

// function have 
// param 1: search string
bool WPTool::string_content::have(std::string str){
    if(this->object->find(str) != std::string::npos){
        return true;
    }
    return false;
}

// function qual_components_with
// param 1: search string
int WPTool::string_content::qual_components_with(std::string str){
    int result = 0;
    for(int i = 0; i < this->components.size(); i++){
        if(this->components[i].find(str) != std::string::npos){
            result++;
        }
    }
    return result;
}

//function component_number_with
//param 1: search string
int WPTool::string_content::component_number_with(std::string str){
    static int result;
    static std::string object;
    if(object != str){
        object = str; 
        result = 0;
    }
    for(int i = result; i < this->components.size(); i++){
        if(this->components[i].find(str) != std::string::npos){
            result = i + 1;
            return i;
        }
    }
    return -1;
}

//function erase 
//param 1: index of component
void WPTool::string_content::erace(int index){
    int * component_size;
    component_size = new int(components[index].length());
    int * component_pos = new int;
    int * delim_pos = new int;
    *component_pos = object->find(components[index]);
    *delim_pos = object->find_first_of(*this->delim,*component_pos); 
    while ((*delim_pos - *component_pos) != *component_size){ 
        *component_pos = object->find(components[index],*component_pos+1);
        *delim_pos = object->find_first_of(*this->delim,*component_pos);
    }
    object->erase(*component_pos,*component_size);
    components.erase(components.begin() + index - 1);
    delete component_size;
    delete component_pos;
    delete delim_pos;
} 