# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

void ft_putstr(char *str);
void ft_cat(char *file, char *program)
{
    int fd;
    int bytes;
    char buff[3000];
    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program);
        write(2, ": ", 2);
        ft_putstr(basename(file));
        write(2, ": ", 2);
        ft_putstr(strerror(errno));
        write(2, "\n", 1);
        return;
    }
    while((bytes = read(fd, buff, 3000)) > 0)
    {
        write(1, buff, bytes);
    }
}