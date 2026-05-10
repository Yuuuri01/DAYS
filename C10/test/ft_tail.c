# include "lib.h"


void ft_tail_fd(char *file, char *program)
{
    int i;
    int start;
    int bytes;
    int count;
    int size_total;
    int size_buff;
    char *buff;
    int fd;


    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program);
        ft_putstr(": cannot open '");
        ft_putstr(basename(file));
        ft_putstr("' for reading: bo such file or directory");
        write(2, "\n", 1);
        return;
    }
    

    size_total = 0;
    size_buff = 30000;
    buff = malloc(size_buff);
    if(!buff)
        return;
    while((bytes = read(fd, buff + size_total, 1)) > 0)
    {
        size_total += bytes;
        if(size_total >= size_buff)
        {
            free(buff);
            size_buff *= 2;
            buff = malloc(size_buff);
            if(!buff)
                return;
        }
    }
    

    if(size_total > 0 && buff[total_size - 1] == '\n')
        size--;
    i = total_size - 1;
    count = 0;
    while(i >= 0)
    {
        if(buff[i] == '\n')
            count++;
        if(count == 10)
            break;
        i--;
    }

    if(i < 0)
        start = 0;
    else
        start = i + 1;
    write(1, buff + start, total - start);
    free(buff);
    close(fd);
}