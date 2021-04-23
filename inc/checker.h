#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

enum	e_cmd
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

void	take_stdin(t_list **lst_cmd);
void	exec_instruc(t_list *lst_cmd, int **stacks);
int		clean_exit(int **stacks, t_list **lst_cmd, int ret);
int		check_order(int **stacks);

#endif