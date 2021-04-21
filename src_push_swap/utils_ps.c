#include "push_swap.h"

int	is_sort(int **stacks)
{
	int	len;
	int	i;

	len = stacks[A][0];
	i = 0;
	if (stacks[B][0] > 0)
		return (0);
	while (++i < len)
		if (stacks[A][i] > stacks[A][i + 1])
			return (0);
printf("----------\n");
printf("It is sort !\n");
printf("----------\n");
	return (1);
}