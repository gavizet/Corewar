#include "asm.h"

int	error(char *erroor)
{
	ft_putendl_fd(error, 2);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2 )
		return (error("usage : ./asm [champion.s]"));
}
