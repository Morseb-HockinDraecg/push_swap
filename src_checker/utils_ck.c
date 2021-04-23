#include "checker.h"

void	take_stdin(t_list **lst_cmd)
{
	char	*cmd;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &cmd);
		if (ret > 0)
			ft_lstadd_back(lst_cmd, ft_lstnew(cmd));
		else if (ret == -1)
		{
			ft_lstclear(lst_cmd, free);
			break ;
		}
	}
}

int	clean_exit(int **stacks, t_list **lst_cmd, int ret)
{
	free(stacks[A]);
	free(stacks[B]);
	free(stacks);
	ft_lstclear(lst_cmd, free);
	if (!ret)
		write(STDOUT_FILENO, "OK\n", cm_strlen("OK\n"));
	else if (ret == 1)
		write(STDOUT_FILENO, "KO\n", cm_strlen("KO\n"));
	exit (ret);
}
