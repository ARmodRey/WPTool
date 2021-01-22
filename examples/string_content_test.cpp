#include "src/WPTool.h"
#include <iostream>

using namespace WPTool;

int main(){
    string_content str("Lenin destroed USSR");
    if ( str.have("Lenin") ){
        std::cout << "yes comrade!!!!" << std::endl;
    }
    str.edit(str.find("destroed"), "make");
    std::cout << str.string() << std::endl;
}