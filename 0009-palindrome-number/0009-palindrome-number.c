static int	count_digits(long n)
{
	int	len = 0;

	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int  my_pow(int base, int count)
{
    int result = 1;

    while (count > 0)
    {
        result *=  base;
        count--;
    }
    return (result);
}

bool isPalindrome(int x) {
    int len = count_digits(x);
    int left;
    int right = 1;

    if (x < 0)
        return (false);
    if (len == 1)
        return (true);
    left = my_pow(10, len - 1);
    while (left > right)
    {
        int l = (x / left) % 10;
        int r = (x / right) % 10;
        if (l != r)
            return (false);
        left /= 10;
        right *= 10;
    }
    return (true);
}