#include "checker.h"

int	check_order(int **stacks)
{
	int	len;

	if (stacks[B][0])
		return (1);
	len = stacks[A][0];
	while (len > 1)
	{
		if (stacks[A][len] < stacks[A][len - 1])
			return (1);
		len--;
	}
	return (0);
}

static void	init_tab_funct(void (*arr[8])(int **stacks))
{
	arr[sa] = fsa;
	arr[sb] = fsb;
	arr[ss] = fss;
	arr[pa] = fpa;
	arr[pb] = fpb;
	arr[ra] = fra;
	arr[rb] = frb;
	arr[rr] = frr;
	arr[rra] = frra;
	arr[rrb] = frrb;
	arr[rrr] = frrr;
}

enum e_cmd	find_enum(char *cmd)
{
	enum e_cmd	result;
	char		*lst_cmd[12];

	lst_cmd[0] = "sa";
	lst_cmd[1] = "sb";
	lst_cmd[2] = "ss";
	lst_cmd[3] = "pa";
	lst_cmd[4] = "pb";
	lst_cmd[5] = "ra";
	lst_cmd[6] = "rb";
	lst_cmd[7] = "rr";
	lst_cmd[8] = "rra";
	lst_cmd[9] = "rrb";
	lst_cmd[10] = "rrr";
	lst_cmd[11] = NULL;
	result = 0;
	while (lst_cmd[result])
	{
		if (!ft_strncmp(cmd, lst_cmd[result], ft_strlen(lst_cmd[result]) + 1))
			return (result);
		result++;
	}
	return (-1);
}

void	exec_instruc(t_list *lst_cmd, int **stacks)
{
	void	(*arr[11])(int **stacks);
	char	*cmd;
	int		rang;

	init_tab_funct(arr);
	while (lst_cmd)
	{
		cmd = lst_cmd->content;
		write(STDOUT_FILENO, cmd, ft_strlen(cmd));
		write(STDOUT_FILENO, "\n", 1);
		rang = find_enum(cmd);
		if (rang > -1)
			(*arr[rang])(stacks);
		else
			clean_exit(stacks, &lst_cmd, 1);
		lst_cmd = lst_cmd->next;
	}
	(void)lst_cmd;
	(void)stacks;
}
