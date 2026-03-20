// int is_val3(char *s, char c, char b)
// {
//     int opened = 0, closed = 0;

//     for (int i = 0; str[i]; i++)
//     {
//         if (str[i] == c)
//             opened++;
//         else if (str[i] == b)
//         {
//             if (opened > 0)
//                 opened--;
//             else
//                 closed++;
//         }
//     }
//     return (opened + closed);
// }

int is_open(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return (1);
    return (0);
}

int check_pair(char open, char close)
{
    if (open == '(' && close == ')')
        return (1);
    if (open == '[' && close == ']')
        return (1);
    if (open == '{' && close == '}')
        return (1);
    return (0);
}

bool isValid(char* s) 
{
    int stack[strlen(s)];
    int n;

    n = -1;

    if (!is_open(s[0]))
        return (false);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (is_open(s[i]) == 1)
        {
            n++;
            stack[n] = s[i];
        }
        else if (n >= 0 && check_pair(stack[n], s[i]) == 1)
        {
            stack[n] = 0;
            n--;
        }
        else 
            return(false);
    }
    if (stack[0] != 0)
        return (false);
    return (true);
}