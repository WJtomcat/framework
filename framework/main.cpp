//
//  main.cpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#include <iostream>
#include "network.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    using namespace framework;
    ConnectedLayer layer(1,3,4,RELU);
    layer.init();
    return 0;
}
