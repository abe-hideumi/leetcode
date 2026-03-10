#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int handole(char c) {
    if (c == 'I')
        return (I);
    if (c == 'V')
        return (V);
    if (c == 'X')
        return (X);
    if (c == 'L')
        return (L);
    if (c == 'C')
        return (C);
    if (c == 'D')
        return (D);
    if (c == 'M')
        return (M);
    return (0);
}

int option_I(char c) {
    if (c == 'V')
        return (V - I);
    if (c == 'X')
        return (X - I);
    return (I);
}

int option_X(char c) {
    if (c == 'L')
        return (L - X);
    if (c == 'C')
        return (C - X);
    return (X);
}

int option_C(char c) {
    if (c == 'D')
        return (D - C);
    if (c == 'M')
        return (M - C);
    return (C);
}

int romanToInt(char* s) {
    long long   result;
    int         tmp;

    result = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        tmp = handole(s[i]);
        if (tmp == I && s[i + 1] != '\0')
        {
            tmp = option_I(s[i + 1]);
            if (tmp != I)
                i++;
        }
        else if (tmp == X && s[i + 1] != '\0')
        {
            tmp = option_X(s[i + 1]);
            if (tmp != X)
                i++;
        }
        else if (tmp == C && s[i + 1] != '\0')
        {
            tmp = option_C(s[i + 1]);
            if (tmp != C)
                i++;
        }
        result = result + (long long)tmp;
    }
    return ((int)result);
}