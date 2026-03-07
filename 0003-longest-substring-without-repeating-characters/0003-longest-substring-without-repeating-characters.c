// used配列に0をセット
// (unsigned char)にキャストしてusedにflagを立てる
// flagが立っていない場合はj++で進める
// flagが立っていた場合、whileをぬけresult < (j - i)の時のみresultを更新
// iは1文字ずつ追っていく
int lengthOfLongestSubstring(char* s) {
    int             used[256];
    int             i;
    int             j;
    int             result;
    unsigned char   c;

    i = 0;
    j = 0;
    result = 0;
    while (s[i] != '\0')
    {
        memset(used, 0, sizeof(used));
        j = i;
        while (s[j] != '\0')
        {
            c = (unsigned char)s[j];
            if (used[c] == 1)
                break ;
            used[c] = 1;
            j++;
        }
        if (result < (j - i))
            result = j - i;
        i++;
    }
    return (result);
}