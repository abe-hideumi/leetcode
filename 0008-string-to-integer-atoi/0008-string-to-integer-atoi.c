#include <limits.h>

int myAtoi(char* s) {
    long long   result = 0;
    int         sign = 1;
    int         i = 0;

    while (s[i] != '\0' && s[i] == ' ')
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
    {
        result = (result * 10) + (s[i] - '0');
        if (sign == 1 && result > INT_MAX)
            return (INT_MAX);
        if (sign == -1 && -1 -result < INT_MIN)
            return (INT_MIN);
        i++;
    }
    return (sign * (int)result);
}