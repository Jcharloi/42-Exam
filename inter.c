#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *str, char c, int i)
{
	int	j;

	j = 0;
	while(j < i)
	{
		if (str[j] == c)
			return (0);
		++j;
	}
	return (1);
}

void	ft_iter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (ft_check(s1, s1[i], i) == 1)
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s1[i], 1);
					break;
				}
				++j;
			}
		}
		++i;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_iter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

// "1231"
// //tab[10] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
// char tab[256];
// while (i < 256)
// 	tab[i] = 0;

// c = argv[1][i];
// if (tab[c] == 0)
// {
// 	ft_putchar(c);
// 	tab[c] = 1;
// }

return ((octet >> 4) + (octet << 4));