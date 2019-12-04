//
//  loader.cpp
//  framework
//
//  Created by Admin on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "loader.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

namespace framework {

List *read_cfg(std::string filename)
{
    List *cfg_list = new List;
    std::ifstream cfg_file;
    cfg_file.open(filename);
    std::string output;
//    char sentence[200];
//    cfg_file >> sentence;
//    std::cout << sentence << std::endl;
    std::getline(cfg_file, output);
    std::cout << output << std::endl;
    cfg_file.close();
    return cfg_list;
}



} // namespace framework
