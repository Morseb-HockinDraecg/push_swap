#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

enum	e_stack
{
	A,
	B,
};

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

int		*cm_error_check(int argc, char **argv);
int		cm_strlen(char *s);
int		check_nbr(const char *nptr, int *nb);
void	ft_putnbr(int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

void	fsa(int **stacks);
void	fsb(int **stacks);
void	fss(int **stacks);
void	fpa(int **stacks);
void	fpb(int **stacks);
void	fra(int **stacks);
void	frb(int **stacks);
void	frr(int **stacks);
void	frra(int **stacks);
void	frrb(int **stacks);
void	frrr(int **stacks);

int		get_next_line(int fd, char **line);
int		glen(char *str, char c);
void	gnl_free(char **str);

void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstnew(const void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif