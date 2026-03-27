int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while(left < right)
    {
        int cur;
        if (height[left] < height[right])
            cur = height[left] * (right - left);
        else 
            cur = height[right] * (right - left);
        if (max < cur)
            max = cur;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return (max);
}