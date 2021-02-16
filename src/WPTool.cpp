#include "WPTool.h"

// function split_string
// param 1: source string 
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

// function split_string
// param 1: source string 
// param 2: delimeter 
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

// function string_revers
// param 1: string for revers
void WPTool::reverse(std::string &source){
    int n = source.length() - 1;
    for(int i = 0; i < source.length() / 2; i++){
        std::swap(source[i],source[n-i]);
    }
}

// function string_revers
// param 1: source string
std::string WPTool::reverse(std::string source){
    std::string result(source);
    int temp;
    int len = result.length();
    for(int i = 0,j = len - 1; i != len/2; i++, j--){
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    return result;
}

// function replase
// param 1: source string 
// param 2: char to replase
// param 3: new char
std::string WPTool::replase(std::string source, std::string oldChar, std::string newChar){
    std::string result = source; 
    int * found = new int(result.find(oldChar)); // find in string oldChar
    int * len = new int(oldChar.size()); // cout of chars
    while (*found != std::string::npos){
        result.erase(*found, *len); //  remove old chars 
        result.insert(*found, newChar); // add new chars 
        *found = result.find(oldChar,*found); // update position
    }
    delete len;
    delete found;
    return result;
}

// function is_digit
// param 1: source string 
bool WPTool::is_digit(std::string source){
    int found = source.find_first_not_of("-,.1234567890");
    if(found != std::string::npos){
        return false;
    }
    return true;
}

// class constructor 
WPTool::string_content::string_content(){
    this->object = new std::string; // init object of string
    this->delim = new std::string; // init object of delimiter
}

// class constructor 
// param 1: source string to retrieve content
// param 2: characters to separate the string
WPTool::string_content::string_content(std::string source){
    this->object = new std::string(source); // init object of string
    this->delim = new std::string(" \t");   // init object of delimiter
    this->components = split_string(*this->object);
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

// method get_string
std::string WPTool::string_content::string(){
    return *object;
}

// method get_delim
std::string WPTool::string_content::delimeter(){
    return *delim;
}

// method get_size
int WPTool::string_content::size(){
    return components.size();
}

void WPTool::string_content::set(std::string & param, std::string str){
    if(!components.empty()){
        components.clear(); // free vect
    }
    param = str;
    components = split_string(*this->object, *this->delim);
}

// method set_string 
// param 1: source string to retrieve content
void WPTool::string_content::set_string(std::string source){
    set(*this->object,source);
}

// method set_delim 
// param 1: characters to separate the string
void WPTool::string_content::set_delimetr(std::string delim){
    set(*this->delim,delim);
}

// operator -> []
// param 1: index of component
std::string WPTool::string_content::operator[](int index){
    return components.at(index);
}

// method have 
// param 1: search string
bool WPTool::string_content::have(std::string str){
    if(this->object->find(str) != std::string::npos){
        return true;
    }
    return false;
}

// method qual_components_with
// param 1: search string
int WPTool::string_content::count(std::string str){
    int result = 0;
    for(int i = 0; i < this->components.size(); i++){
        if(this->components[i].find(str) != std::string::npos){
            result++;
        }
    }
    return result;
}

// method component_number_with
// param 1: search string
int WPTool::string_content::find(std::string str, int start, int end){
    static int result;
    static int _start;
    static int _end;
    static std::string object;
    if(object != str || start < _start || end < _end){
        object = str; 
        result = _start;
        _start = start;
        _end = end;
    }
    for(int count = result; count < this->components.size(); count++){
        if(this->components[count].find(str) != std::string::npos){
            result = count + 1;
            return count;
        }
    }
    return -1;
}

// method erase 
// param 1: index of component
void WPTool::string_content::erace(int index){
    size_t * component_size = new size_t;
    size_t * component_pos = new size_t;
    size_t * delim_pos = new size_t;
    *component_size = components[index].size();
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

// method edit
// param 1: index of element
// param 2: replaicement of component
void WPTool::string_content::edit(int index, std::string repl){
    size_t * component_size = new size_t;
    size_t * component_pos = new size_t;
    size_t * delim_pos = new size_t;
    *component_size = components[index].size();
    *component_pos = object->find(components[index]);
    *delim_pos = object->find_first_of(*this->delim,*component_pos); 
    while ((*delim_pos - *component_pos) == *component_size - 1 ){ 
        *component_pos = object->find(components[index],*component_pos+1);
        *delim_pos = object->find_first_of(*this->delim,*component_pos);
        if(*delim_pos == std::string::npos){
            *delim_pos = object->size() - 1;
        }
    }
    object->erase(*component_pos,*component_size);
    object->insert(*component_pos, repl);
    this->components[index] = repl;
    delete component_size;
    delete component_pos;
    delete delim_pos;
} 

// function get
// param 1: index of component
std::string WPTool::string_content::get(int index){
    return components[index];
}

// method replase
// param 1: old chars 
// parem 2: new chars  
void WPTool::string_content::replase(std::string oldChar, std::string newChar){
    *this->object = WPTool::replase(*this->object, oldChar, newChar); 
    set_string(*this->object); 
}