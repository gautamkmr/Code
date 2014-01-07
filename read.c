#include <unistd.h>
 
int main()
{
    char data[128];
 
    if(read(0, data, 128) < 0)
        write(2, "An error occurred in the read.\n", 31);
    else
        write(1,data,128);     
 
    exit(0);
}

