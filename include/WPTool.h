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

    // function checks a string for a number
    bool is_digit(std::string source);

    // function to flip string
    void reverse(std::string &source);       // revers the given string
    std::string reverse(std::string source); // return reversed string               

    // function to replase chars
    std::string replase(std::string source, std::string oldChar, std::string newChar);  

    // class for storing content from string
    class string_content{
    private:
        std::string *object;                           // memory area for writing raw data
        std::string *delim;                            // memory area for delimiter
        string_vect components;                        // vector with elements of string
        void set(std::string &param, std::string str); // set str to parametr
    public:
        string_content(); // constructors
        string_content(std::string source);
        string_content(std::string source, std::string delim);
        ~string_content();                          // destructor
        void set_string(std::string source);        // set string to class
        void set_delimetr(std::string delim);       // set delimiter to class
        std::string delimeter();                    // return delimiter
        std::string string();                       // return string
        void replase(std::string oldChar, std::string newChar);
        int size();                             // return count of elements
        std::string operator[](int index);      // return component from index
        std::string get(int index);             // return component from index      
        bool have(std::string str);             // if sentence have element return true
        int count(std::string str);             // return number of components with string
        void erace(int index);                  // delete component
        void edit(int index, std::string repl); // replase component in string
        int find(std::string str, int start = 0, int end = 0); // return component with string
    };
    
};

#endif 