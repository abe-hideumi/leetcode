bool is_open(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return (true);
    return (false);
}

bool check_pair(char open, char close)
{
    if (open == '(' && close == ')')
        return (true);
    if (open == '[' && close == ']')
        return (true);
    if (open == '{' && close == '}')
        return (true);
    return (false);
}

bool isValid(char* s) 
{
    int stack[strlen(s)];
    int n;

    n = -1;

    if (is_open(s[0]) == false)
        return (false);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (is_open(s[i]) == true)
        {
            n++;
            stack[n] = s[i];
        }
        else if (n >= 0 && check_pair(stack[n], s[i]) == true)
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