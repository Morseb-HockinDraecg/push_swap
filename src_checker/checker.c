#include "checker.h"

int	main(int argc, char **argv)
{
	int		**stacks;
	t_list	*lst_cmd;

	lst_cmd = NULL;
	stacks = (int **)malloc(sizeof(int *) * 2);
	stacks[A] = cm_error_check(argc, argv);
	stacks[B] = (int *)malloc(sizeof(int) * argc);
	stacks[B][0] = 0;
	if (!stacks[A])
		return (clean_exit(stacks, &lst_cmd, 2));
	take_stdin(&lst_cmd);
	exec_instruc(lst_cmd, stacks);
	if (check_order(stacks))
		return (clean_exit(stacks, &lst_cmd, 1));
	return (clean_exit(stacks, &lst_cmd, 0));
}
