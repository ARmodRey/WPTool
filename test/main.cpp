#include "string_content.h"

#include <iostream>

using namespace WPTool;

int main(){

    string_content a("1+2-+1", "+-");

    std::cout << a[0]<<std::endl;
    std::cout << a[1]<<std::endl;
    std::cout << a[2]<<std::endl;

    std::cout << a.get_size() << std::endl;

    return 0;
}