//
//  read.hpp
//  framework
//
//  Created by 王炬 on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef read_hpp
#define read_hpp

#include <stdio.h>
#include "network.hpp"
#include "connectedlayer.hpp"
#include "softmax_layer.hpp"
#include "io.hpp"



namespace framework {

Network *read_network_cfg(IOReader *f);

Layer *read_layer_cfg(IOReader *f);










} // namespace framework









#endif /* read_hpp */
