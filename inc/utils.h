#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

enum	e_stack
{
	A,
	B,
};

int		*cm_error_check(int argc, char **argv);
int		cm_strlen(char *s);
int		check_nbr(const char *nptr, int *nb);
void	ft_putnbr(int nb);

void	sa(int **stacks);
void	sb(int **stacks);
void	ss(int **stacks);
void	pa(int **stacks);
void	pb(int **stacks);
void	ra(int **stacks);
void	rb(int **stacks);
void	rr(int **stacks);
void	rra(int **stacks);
void	rrb(int **stacks);
void	rrr(int **stacks);

#endif