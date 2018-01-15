#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		compare(char *s1, char *s2)
{
	int		j = 0;
	int		len = 0;

	while (s2[j] != '\0')
	{
		if (s2[j] == s1[j])
			len++;
		j++;
	}
	if (len == ft_strlen(s2))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	int		i;

	i = 0;
	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		while (str1[i] != '\0')
		{
			if (str1[i] == str2[0])
			{
				if (compare(str1 + i, str2) == 1)
				{
					ft_putstr(str1 + i);
					ft_putchar('\n');
				}
				return (0);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
