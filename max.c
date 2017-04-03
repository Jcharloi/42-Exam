

int		max(int *tab, unsigned int len)
{
	int i;
	int	stock;

	i = 0;
	stock = 0;
	if (!(tab))
		return(0);
	while (len)
	{
		if (tab[i] > stock)
			stock = tab[i];
		i++;
		len--;
	}
	return(stock);
}

int main(void)
{
	int	tab[] = {42, 0, 5, 64, 2, 68, 1};

	printf("max : %d", max(tab, 7));
	return (0);
}