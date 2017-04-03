#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (ft_isalpha(argv[1][i]))
			{
				if (argv[1][i] == 'z' || argv[1][i] == 'Z')
					ft_putchar(argv[1][i] - 25);
				else
					ft_putchar(argv[1][i] + 1);
			}
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}