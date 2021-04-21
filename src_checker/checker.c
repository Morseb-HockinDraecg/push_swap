#include "checker.h"

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = cm_error_check(argc, argv);
	if (!stack_a)
		return (1);
	printf("Checker here \n");
	return (0);
}
