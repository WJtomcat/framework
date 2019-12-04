//
//  io.cpp
//  framework
//
//  Created by 王炬 on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "io.hpp"


namespace framework {


int IOReader::fileno()
{
    // do nothing by default;
    return 0;
}


int IOWriter::fileno()
{
    // do nothing by default;
    return 0;
}


size_t VectorIOWriter::operator()(
            const void *ptr, size_t size, size_t nitems)
{
    size_t bytes = size * nitems;
    if(bytes > 0){
        size_t o = data.size();
        data.resize(o + bytes);
        memcpy(&data[o], ptr, size * nitems);
    }
    return nitems;
}


size_t VectorIOReader::operator()(
                  void *ptr, size_t size, size_t nitems)
{
    if (rp >= data.size()) return 0;
    size_t nremain = (data.size() - rp) / size;
    if (nremain < nitems) nitems = nremain;
    if (size * nitems > 0) {
        memcpy (ptr, &data[rp], size * nitems);
        rp += size * nitems;
    }
    return nitems;
}


FileIOReader::FileIOReader(FILE *rf): f(rf) {}


FileIOReader::FileIOReader(const char * fname)
{
    name = fname;
    f = fopen(fname, "rb");
    
    need_close = true;
}


FileIOReader::~FileIOReader() {
    if (need_close)
    {
        int ret = fclose(f);
        if (ret != 0)
        {
            // TODO: output error information
        }
    }
}


size_t FileIOReader::operator()(void *ptr, size_t size, size_t nitems) {
    return fread(ptr, size, nitems, f);
}

int FileIOReader::fileno()  {
    return ::fileno (f);
}


FileIOWriter::FileIOWriter(FILE *wf): f(wf) {}


FileIOWriter::FileIOWriter(const char * fname)
{
    name = fname;
    f = fopen(fname, "wb");
    
    // TODO: output error information
    need_close = true;
}


FileIOWriter::~FileIOWriter()  {
    if (need_close) {
        int ret = fclose(f);
        if (ret != 0) {
            // TODO: output error information
        }
    }
}


size_t FileIOWriter::operator()(const void *ptr, size_t size, size_t nitems) {
    return fwrite(ptr, size, nitems, f);
}

int FileIOWriter::fileno()  {
    return ::fileno (f);
}


uint32_t fourcc (const char sx[4]) {
    assert(4 == strlen(sx));
    const unsigned char *x = (unsigned char*)sx;
    return x[0] | x[1] << 8 | x[2] << 16 | x[3] << 24;
}


} // namespace framework
