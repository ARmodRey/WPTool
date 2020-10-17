#include "word processing.h"
#include <iostream>

using namespace WPTool;

int main(){
    string_content a("слово1_слово2=слово23", "_=");
    a.erace(1);
    std::cout << a.get_string() <<std::endl;
    return 0;
}