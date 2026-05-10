# include <unistd.h>

void ft_display_ft(char *file);
void print_error(char *s);

int main(int ac, char **av)
{
    if(ac == 1)
    {
        print_error("File name missing.");
        return 0;
    }
    if(ac > 2)
    {
        print_error("Too many arguments");
        return 0;
    }
    else
    {
        ft_display_ft(av[1]);
        write(1, "\n", 1);
    }
}