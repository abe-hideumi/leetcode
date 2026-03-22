#include <limits.h>

int reverse(int x){
    int sign = 1;
    long long result = 0;
    long long src = (long long)x;

    if (src < 0)
    {
        sign *= -1;
        src *= -1;
    }
    while (src > 0)
    {
        if (result * 10 >= INT_MAX)
            return (0);
        result = (result * 10) + (src % 10);
        src = src / 10;
    }
    return (sign * (int)result);
}