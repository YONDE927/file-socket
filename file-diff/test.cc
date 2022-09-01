#include "diff.h"
#include "file-list/cmd-caller.h"
#include <memory>

using namespace std;

int main(){
    diff d1{1,0,8,0};
    diff d2{1,8,6,1};
    diff d3{1,18,8,2};
    diff d4{1,4,8,3};
  
    diff_list list("sample");
    //list.reset();

    list.append_diff(d1);
    list.sync();
    call_cmd("../showdiff.sh sample.diff");
    
    auto d = list.pop_diff();
    if(d != nullptr){
        cout << d->type << " " << d->offset << " " << d->size << " " << d->time << endl;
    }

    cout << endl;

    list.append_diff(d2);
    list.sync();
    call_cmd("../showdiff.sh sample.diff");

    d = list.pop_diff();
    if(d != nullptr){
        cout << d->type << " " << d->offset << " " << d->size << " " << d->time << endl;
    }
    return 0;
}
