#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strrev(char *str)
// {
// 	char	*strrev;
// 	int i;
// 	int j;

// 	i = ft_strlen(str);
// 	j = 0;
// 	strrev = (char *)malloc(sizeof(char) * (i + 1));
// 	if (strrev == NULL)
// 		return (NULL);
// 	while (--i >= 0)
// 	{
// 		strrev[j] = str[i];
// 		//i--;
// 		j++;
// 	}
// 	strrev[j] = '\0';
// 	return (strrev);
// }

// int main(int argc, char **argv)
// {
// 	char *str;

// 	str = ft_strrev(argv[1]);
// 	ft_putstr(str);
// 	return (0);
// }


char *ft_strrev(char *str)
{
    char tmp;
    int i;
    int j;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
        i++;
    }
    return (str);
}

int main()
{
    char *str  = strdup("Quentin <3");
    printf("%s\n", ft_strrev(str));
    return (0);
}
