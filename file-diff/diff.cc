#include "diff.h"

int diff::cat(const diff& d){
    //操作タイプが一致しているか
    if(type != d.type){
        //一致していない
        return -1;
    }

    //被っているか判定
    if((offset > (d.offset + d.size)) || ((offset + size) < d.offset)){
        //被っていない
        return -1;
    }

    //被っているので結合
    if(offset > d.offset){
        offset = d.offset; 
    }
    if((offset + size) < (d.offset + d.size)){
        size = (d.offset + d.size) - offset; 
    }

    return 0;
}

diff_list::diff_list(std::string path){
    file_path = path;
    diff_path = path;
    diff_path.append(".diff");
    list = std::make_shared<fili::file_list>(diff_path, DIFF_BLOCK_SIZE); 
}

void diff_list::append_diff(diff& d){
    //既存の差分をチェック
    auto back_block = list->new_back_block();
    back_block->write_buffer(d);
}

shared_ptr<diff> diff_list::pop_diff(){
    auto fblock = list->first_block();
    if(fblock != nullptr){
        shared_ptr<diff> d(new diff);  
        try{
            fblock->read_buffer<diff>(*d);
        }catch(std::exception& e){
            return shared_ptr<diff>(nullptr);
        }
        list->delete_block(fblock);
        return d;
    }
    return shared_ptr<diff>(nullptr);
}

void diff_list::sync(){
    list->sync();
}

void diff_list::reset(){
    list->reset();
}












