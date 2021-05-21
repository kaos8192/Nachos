/* ej_child.c */

#include "../userprog/syscall.h"

int main() {
    // open a file called name
    int status = 3;
    char* name = "ej_child_output";
    
    Create(name);
    int value = Open(name);
    Write("This is some output from the child!", 35, value);
    Close(value);
    Exit(status);
    return 7;
}
