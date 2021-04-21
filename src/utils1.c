#include "utils.h"

int	cm_strlen(char *s)
{
	int	k;

	k = 0;
	if (!s)
		return (k);
	while (s[k])
		k++;
	return (k);
}

int	check_nbr(const char *nptr, int *nb)
{
	long long int	val;
	int				signe;

	if (!nptr)
		return (1);
	signe = 1;
	val = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -signe;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
		val = 10 * val + (*nptr++ - '0');
	if (*nptr != 0 || val > INT_MAX || val < INT_MIN)
		return (1);
	*nb = signe * val;
	return (0);
}

void	ft_putnbr(int nb)
{
	int	w;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			w = '-';
			write(1, &w, 1);
			nb = -nb;
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		w = (nb % 10) + '0';
		write(1, &w, 1);
	}
}
