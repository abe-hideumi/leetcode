static int	count_digits(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*my_itoa(int n)
{
	char	*result;
	long	nbr;
	int		len;

	nbr = (long)n;
	len = count_digits(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		result[0] = '0';
	while (nbr > 0)
	{
		result[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (result);
}

bool isPalindrome(int x) {
    char    *src = my_itoa(x);
    int     len = strlen(src) - 1;

    for (int i = 0; i <= len; i++)
    {
        if (src[i] != src[len])
            return (false);
        len--;
    }
    return (true);
}