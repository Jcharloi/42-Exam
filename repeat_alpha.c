#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_isalpha (int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	write (1, s, ft_strlen(s));
}

int main(int argc, char **argv)
{
	int i;
	int stock;

	i = 0;
	stock = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (ft_isalpha(argv[1][i]))
			{
				if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
					stock = argv[1][i] - 96;
				if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
					stock = argv[1][i] - 64;
				while (stock)
				{
					ft_putchar(argv[1][i]);
					stock--;
				}
			}
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return 0;
}
