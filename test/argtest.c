/* argtest.c */

#include "../userprog/syscall.h"

int main() {
    // call exec
    // ... but with args!
    // how does one use args, you ask? 
    // I don't know, either!

    AddArgument("This ");
    /* AddArgument("is "); */
    /* AddArgument("a "); */
    /* AddArgument("test!\n"); */
        
    int pid = Exec("../test/argtest_child");

    int value = Join(pid);
    return 0;
}
