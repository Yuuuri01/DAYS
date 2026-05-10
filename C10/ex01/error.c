# include <unistd.h>


void error(void)
{
    char c;
    while(read(0, &c, 1))
    {
        write(1, &c, 1);
        sleep(2);
    }
}