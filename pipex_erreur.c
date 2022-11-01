#include "pipex.h"

void  erreur(void)
{
    write(2, "ERREUR\n", 7);
    exit(EXIT_FAILURE);
}

void    msg_erreur(char *r)
{
    perror(r);
    exit(EXIT_FAILURE);
}

void	free_s(char **av)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (av[size])
		size++;
	while (i < size)
		free(av[i++]);
	free(av);
}