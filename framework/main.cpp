//
//  main.cpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#include <iostream>
#include "connectedlayer.hpp"
#include "loader.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::string filename("test");
    framework::read_cfg(filename);
    
    
    
    return 0;
}
