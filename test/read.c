#include "../userprog/syscall.h"

int main()  {
    // open file
    int fd = Open("readtest");
    // read from file
    char readstring[256];
    int bytes = Read(readstring, 256, fd);
    Close(fd);

    readstring[bytes-1] = 0;
    // create a file
    Create(readstring);
    // profit ??

    return 0;
}
