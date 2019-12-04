//
//  io.hpp
//  framework
//
//  Created by 王炬 on 2019/12/4.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef io_hpp
#define io_hpp

#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "network.hpp"

namespace framework {

struct IOReader {
    // name that can be used in error messages
    std::string name;

    // fread
    virtual size_t operator()(
         void *ptr, size_t size, size_t nitems) = 0;

    // return a file number that can be memory-mapped
    virtual int fileno ();

    virtual ~IOReader() {}
};

struct IOWriter {
    // name that can be used in error messages
    std::string name;

    // fwrite
    virtual size_t operator()(
         const void *ptr, size_t size, size_t nitems) = 0;

    // return a file number that can be memory-mapped
    virtual int fileno ();

    virtual ~IOWriter() {}
};


struct VectorIOReader:IOReader {
    std::vector<uint8_t> data;
    size_t rp = 0;
    size_t operator()(void *ptr, size_t size, size_t nitems) override;
};

struct VectorIOWriter:IOWriter {
    std::vector<uint8_t> data;
    size_t operator()(const void *ptr, size_t size, size_t nitems) override;
};

struct FileIOReader: IOReader {
    FILE *f = nullptr;
    bool need_close = false;

    FileIOReader(FILE *rf);

    FileIOReader(const char * fname);

    ~FileIOReader() override;

    size_t operator()(void *ptr, size_t size, size_t nitems) override;

    int fileno() override;
};

struct FileIOWriter: IOWriter {
    FILE *f = nullptr;
    bool need_close = false;

    FileIOWriter(FILE *wf);

    FileIOWriter(const char * fname);

    ~FileIOWriter() override;

    size_t operator()(const void *ptr, size_t size, size_t nitems) override;

    int fileno() override;
};

/// cast a 4-character string to a uint32_t that can be written and read easily
uint32_t fourcc (const char sx[4]);



} // namespace framework

#endif /* io_hpp */
