# include <unistd.h>


void print_error(char *s)
{
    while(*s != '\0')
        write(1, s++, 1);
}