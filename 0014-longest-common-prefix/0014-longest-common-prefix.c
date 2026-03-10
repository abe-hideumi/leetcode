char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	copy_len;

	if (s == NULL)
		return (NULL);
	s_len = strlen(s);
	if (s_len <= start)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	copy_len = strlen(s + start);
	if (copy_len > len)
		copy_len = len;
	sub = malloc(copy_len + 1);
	if (sub == NULL)
		return (NULL);
	strlcpy(sub, s + start, copy_len + 1);
	return (sub);
}

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char    *result;
    int     j;
    int     i;

    if (strsSize == 0)
        return (NULL);
    i = 0;
    result = substr(strs[i], 0, strlen(strs[i]));
    if (strsSize == 1)
        return (result);
    for (int i = 1; i < strsSize; i++)
    {
        j = 0;
        while (result[j] != '\0' && strs[i][j] != '\0')
        {
            if (result[j] != strs[i][j])
                break ;
            j++;
        }
        result = substr(result, 0, j);
    }
    return (result);
}