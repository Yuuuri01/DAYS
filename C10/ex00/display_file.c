# include <unistd.h>
# include <fcntl.h>

void ft_display_ft(char *file)
{
    int fd;
    char buff[256];

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        write(1, "Cannot read file.", 17);
        return;
    }
    while(read(fd, &buff, 1) > 0)
    {
        write(1, &buff, 1);
    }
}