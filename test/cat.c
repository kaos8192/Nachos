#include "syscall.h"

int main()
{
    //FIXME TODO Doesn't work, incomplete
    /*OpenFileId input = ConsoleInput;
    OpenFileId output = ConsoleOutput;
    OpenFileId file;
    char prompt[2], ch, buffer[60];
    int i, j;

    prompt[0] = '-';
    prompt[1] = '-';

    while( 1 )
    {
        Write(prompt, 2, output);

        i = 0;

        do {

            Read(&buffer[i], 1, input); 

        } while( buffer[i++] != '\n' );

        buffer[--i] = '\0';

        if( i > 0 ){

            for(j = 1; j < loop through the files; ++j)
            {
                file = Open(open the file);
                Read(&ch_buff, size, file);//Loop somehow (console maybe?)
                Write(&ch_buff, size, ConsoleOutput);//use console maybe?
                Close(file);
            }


        }
    }*/
    return 0;
}
