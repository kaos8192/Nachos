/* open.c */

#include "../userprog/syscall.h"

int main() {
    // open a file called name
    char* name = "testfile";
    
    Create(name);
    int value = Open(name);
    Write("test", 4, value);
    Close(value);
}
