//
//  loader.hpp
//  framework
//
//  Created by Admin on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef loader_hpp
#define loader_hpp

#include <stdio.h>

#include "network.hpp"

namespace framework {


struct Node{
    void *val;
    struct Node *next;
    struct Node *prev;
};


struct List{
    int size;
    Node *front;
    Node *back;
};

List *read_cfg(std::string filename);


} // namespace framework

#endif /* loader_hpp */
