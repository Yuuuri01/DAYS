# ifdef     TAIL_H
# define    TAIL_H


# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

void handle_option(char *file, char *program);
void ft_tail_fd(char *file, char *program);
void print_banner(char *file);
void ft_putstr(char *s);
int ft_atoi(char *s);
void error();

# endif