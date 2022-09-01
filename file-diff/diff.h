#pragma once
#include <memory>
#include <string>

#include "file-list/block.h"

using std::shared_ptr;

#define DIFF_BLOCK_SIZE 32

class diff{
    public:
        int type{0};
        int offset{0};
        int size{0};
        double time{0};
        
        int cat(const diff& d);
};

class diff_list{
    private:
        shared_ptr<fili::file_list> list;
        std::string file_path;
        std::string diff_path;
    public:
        diff_list(std::string path);
        void append_diff(diff& d);
        shared_ptr<diff> pop_diff();
        void sync();
        void reset();
};
