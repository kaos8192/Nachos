/* exec.c */

#include "../userprog/syscall.h"

int main() {
    // call exec
    Exec("../test/create");

    return 0;
}
