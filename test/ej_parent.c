/* ej_parent.c */

#include "../userprog/syscall.h"

int main() {
    // call exec
    int pid = Exec("../test/ej_child");
    // join child
    int value = Join(pid);

    // create, open, and write to a file
    char* name = "ej_parent_value";
    Create(name);
    int openvalue = Open(name);

    int i;
    for (i = 0; i < value; ++i){
        Write("test\n", 5, openvalue);

    }
    Close(openvalue);

    return 0;
}
