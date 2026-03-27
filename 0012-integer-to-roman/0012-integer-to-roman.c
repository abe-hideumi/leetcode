char* intToRoman(int num) {
    char    *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char    *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char    *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char    *thousands[] = {"", "M", "MM", "MMM"};
    char    *result = calloc(20, sizeof(char));

    if (result == NULL)
        return (NULL);
    strcat(result, thousands[num / 1000]);
    strcat(result, hundreds[num / 100 % 10]);
    strcat(result, tens[num / 10 % 10]);
    strcat(result, ones[num % 10]);
    return (result);
}