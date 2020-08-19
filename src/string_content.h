#ifndef __STRING__CONTENT__H__
#define __STRING__CONTENT__H__

#include <string>
#include "string.h"
#include <vector>

namespace WPTool{

    // class for storing content from string
    class string_content{
    private:
        std::string *object;                 // memory area for writing raw data
        std::string *delim;                  // memory area for delimiter
        std::vector<std::string> components; // vector with elements of string
    public:
        string_content(); // constructors
        string_content(std::string source, std::string delim);
        ~string_content(); // destructor
        void set_string(std::string source);   // set string to class
        void set_delimetr(std::string delim); // set delimiter to class
        std::string get_delim();              // return delimiter
        std::string get_string();             // return string
        int get_size();                       // return count of elements
        std::string operator[](int index);    // return component from index
        bool have(char sim);                  // if sentence have char return true
        bool have(std::string str);           // if sentence have element return true
        int qual_components_with(char sim);   // return number of components with char
        int component_number_with(char sim);  // return component with char
    };


};

#endif 