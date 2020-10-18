#ifndef __STRING__CONTENT__H__
#define __STRING__CONTENT__H__

#include <string>
#include <vector>
#include <algorithm> 
#include "string.h"

namespace WPTool{

    // contraction for std::vector<std::string> string_vect ---> string vector
    typedef std::vector<std::string> string_vect; 

    // function to split a string 
    string_vect split_string(std::string source); // separates with a space
    string_vect split_string(std::string source, std::string delim); // separates with a delim

    // function to flip string
    void string_reverse(std::string &source);       // revers the given string
    std::string string_reverse(std::string source); // return reversed string

    // class for storing content from string
    class string_content{
    private:
        std::string *object;                           // memory area for writing raw data
        std::string *delim;                            // memory area for delimiter
        string_vect components;                        // vector with elements of string
        void set(std::string &param, std::string str); // set str to parametr
    public:
        string_content(); // constructors
        string_content(std::string source, std::string delim);
        ~string_content();                          // destructor
        void set_string(std::string source);        // set string to class
        void set_delimetr(std::string delim);       // set delimiter to class
        std::string get_delim();                    // return delimiter
        std::string get_string();                   // return string
        int get_size();                             // return count of elements
        std::string operator[](int index);          // return component from index
        bool have(std::string str);                 // if sentence have element return true
        int qual_components_with(std::string str);  // return number of components with string
        int component_number_with(std::string str); // return component with string
        void erace(int index);                      // delete component
        void edit(int index, std::string repl);     // replase component in string      
    };
    
};

#endif 