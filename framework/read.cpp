//
//  read.cpp
//  framework
//
//  Created by 王炬 on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "read.hpp"


namespace framework {


#define READANDCHECK(ptr, n) {                                  \
        size_t ret = (*f)(ptr, sizeof(*(ptr)), n);              \
    }

#define READ1(x)  READANDCHECK(&(x), 1)

// will fail if we write 256G of data at once...
#define READVECTOR(vec) {                       \
        long size;                            \
        READANDCHECK (&size, 1);                \
        FAISS_THROW_IF_NOT (size >= 0 && size < (1L << 40));  \
        (vec).resize (size);                    \
        READANDCHECK ((vec).data (), size);     \
    }




Network *read_network_cfg(IOReader *f)
{
    Network *net = new Network;
    
    return net;
}







} // namespace framework
