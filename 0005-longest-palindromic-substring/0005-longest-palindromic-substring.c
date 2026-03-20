char* longestPalindrome(char* s) {
    int     left = 0, right = 0;
    int     start = 0, max = 1;
    char    *result;

    for (int i = 0; s[i] != '\0'; i++)
    {
        left = i;
        right = i;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right])
        {
            if (max < right - left + 1)
            {
                max = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
        printf("%d : %d\n", max, start);
        left = i;
        right = i + 1;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right])
        {
            if (max < right - left + 1)
            {
                max = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
        printf("%d : %d\n", max, start);
    }
    result = malloc(max + 1);
    strncpy(result, &s[start], max);
    result[max] = '\0';
    return (result);
}