#include "utils.h"

static int	*loop(int *argc, char **argv)
{
	int	i[2];
	int	nb;
	int	*nbrs;
	int	loop;

	nbrs = (int *)malloc(sizeof(int) * *argc);
	i[0] = *argc;
	loop = 1;
	nbrs[0] = *argc - 1;
	while (*argc && loop)
	{
		if (check_nbr(argv[--(*argc)], &nb))
			break ;
		i[1] = i[0];
		while (--i[1] > *argc)
		{
			if (nbrs[i[1]] == nb)
			{
				loop = 0;
				break ;
			}
		}
		nbrs[*argc] = nb;
	}
	return (nbrs);
}

int	*cm_error_check(int argc, char **argv)
{
	int	*nbrs;

	if (argc == 1)
		return (NULL);
	nbrs = loop(&argc, argv);
	if (argc)
	{
		write(2, "Error\n", cm_strlen("Error\n"));
		return (NULL);
	}
	return (nbrs);
}
