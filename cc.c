#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	print(long *tab, int len)
{
	int i = 0;

	while (i < len)
	{
		printf("tab[i] : %ld\n", tab[i]);
		i++;
	}
	printf("\n");
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_operateur(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
	{
		if (ft_isdigit(str[i + 1]) == 0)
			return (1);
	}
	return (0);
}

long		*rpn(char *str)
{
	long	*tab;
	int	i;
	int j;

	j = 0;
	i = 0;
	if (!(tab = (long*)malloc(sizeof(long) * ft_strlen(str))))
		return (NULL);
	while (str[i] != '\0')
	{
		while (is_operateur(str + i) == 0)
		{
			tab[j] = atoi(str + i);
			j++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
			if (str[i] == '\0')
			{
				printf("Error\n");
				return (NULL);
			}
			while (str[i] == ' ')
				i++;
		}
		if (j < 2)
		{
			printf("Error\n");
			return (NULL);
		}
		if (str[i] == '+')
		{
			tab[j - 2] = tab[j - 2] + tab[j - 1];
		}
		else if (str[i] == '-')
		{
			tab[j - 2] = tab[j - 2] - tab[j - 1];
		}
		else if (str[i] == '*')
		{
			tab[j - 2] = tab[j - 2] * tab[j - 1];
		}
		else if (str[i] == '/')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error\n");
				return (NULL);
			}
			tab[j - 2] = tab[j - 2] / tab[j - 1];
		}
		else if (str[i] == '%')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error\n");
				return (NULL);
			}
			tab[j - 2] = tab[j - 2] % tab[j - 1];
		}
		j--;
		i++;
		while (str[i] == ' ')
			i++;
	}
	if (j > 1)
	{
		printf("Error\n");
		return (NULL);
	}
	return (tab);
}

int main(int argc, char **argv)
{
	long		*tab;

	if (argc == 2 && argv[1][0] != '\0')
	{
		tab = rpn(argv[1]);
		if (tab != NULL)
			printf("%ld\n", tab[0]);
		return (0);
	}
	printf("Error\n");
	return (0);
}