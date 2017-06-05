#include <unistd.h>

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

int main(int ac, char **av)
{
    char *av1;
    char *av2;
    int i;
    int j;
    int stock;

    i = 0;
    j = 0;
    stock = 0;
    av1 = av[1];
    av2 = av[2];
    if (ac == 3)
    {
        while (av1[i] != '\0')
        {
            while (av2[j] != '\0')
            {
                if (av1[i] == av2[j])
                {
                    stock++;
                    j++;
                    break ;
                }
                j++;
            }
            i++;
        }
    if (stock == ft_strlen(av1))
        ft_putstr(av1);
    }
    ft_putstr("\n");
    return (0);
}
