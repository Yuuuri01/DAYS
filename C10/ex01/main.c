# include <unistd.h>

void ft_cat(char *file, char *program);
void error(void);

int main(int ac, char **av)
{
    if(ac == 1)
    {
        error();
        return 0;
    }
    int i = 1;
    while(av[i])
    {
        ft_cat(av[i], av[0]);
        write(1, "\n", 1);
        i++;
    }
}
