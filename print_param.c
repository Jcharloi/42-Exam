#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

void	ft_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (argc > 1)
	{
		ft_putstr(argv[i + 1]);
		ft_putchar('\n');
		i++;
		argc--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		f;
	char	*j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		f = 0;
		if (ft_strcmp(argv[i], argv[i + 1]) >= 0)
		{
			f = 1;
			j = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = j;
		}
		i++;
		if (f == 1)
			i = 1;
	}
	ft_argc(argc, argv);
	return (0);
}
