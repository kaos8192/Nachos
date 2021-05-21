/* argtest_child.c */

#include "../userprog/syscall.h"

int main() {
    // open a file called name
    char* name = "argtest.output";
    
    char arg_1[256];
    /* char arg_2[256]; */
    /* char arg_3[256]; */
    /* char arg_4[256]; */
    
    FetchArgument(arg_1);
    /* FetchArgument(arg_2); */
    /* FetchArgument(arg_3); */
    /* FetchArgument(arg_4); */

    // XXX concatenate the arg_x's so we can write to the file
    // 

    Create(name);
    int value = Open(name);
    Write(arg_1, sizeof(arg_1), value);
    /* Write(arg_2, sizeof(arg_2), value); */
    /* Write(arg_3, sizeof(arg_3), value); */
    /* Write(arg_4, sizeof(arg_4), value); */
    Close(value);
}
