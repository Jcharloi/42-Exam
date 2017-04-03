#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	write (1, s, ft_strlen(s));
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			i++;
		}
		ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}