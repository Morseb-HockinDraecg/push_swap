#include "checker.h"

static int	clean_exit(int **stacks, int ret)
{
	free(stacks[A]);
	free(stacks[B]);
	free(stacks);
	if (!ret)
		write(STDOUT_FILENO, "OK\n", cm_strlen("OK\n"));
	else
		write(STDOUT_FILENO, "KO\n", cm_strlen("KO\n"));
	return (ret);
}

static void	print_in(void)
{
	char	*err_fd;

	while (get_next_line(STDIN_FILENO, &err_fd) > 0)
	{
		printf("%s\n", err_fd);
		free(err_fd);
		err_fd = NULL;
	}
}

int	main(int argc, char **argv)
{
	int	**stacks;

	print_in();
	stacks = (int **)malloc(sizeof(int *) * 2);
	stacks[A] = cm_error_check(argc, argv);
	stacks[B] = (int *)malloc(sizeof(int) * argc);
	stacks[B][0] = 0;
	if (!stacks[A])
		return (clean_exit(stacks, 2));
	if (argc == 1)
		return (clean_exit(stacks, 0));
	return (clean_exit(stacks, 0));
}
