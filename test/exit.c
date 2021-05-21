#include "../userprog/syscall.h"

int main() {
    // exec parent
    //      parent exec's child
    //      child will print something (in a file) and exit
    // parent joins child 
    Exec("../test/ej_parent");

    return 0;
}
