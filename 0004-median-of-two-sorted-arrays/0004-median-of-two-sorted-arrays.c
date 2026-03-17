int *sort_nums(int *nums, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (nums[i] > nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (nums);
}

int *join_nums(int *nums1, int size_1, int *nums2, int size_2)
{
    int *join;
    int i;
    int j;

    join = malloc(sizeof(int) * (size_1 + size_2));
    if (join == NULL)
        return (NULL);
    i = 0;
    while (i < size_1)
    {
        join[i] = nums1[i];
        i++;
    }
    j = 0;
    while (j < size_2)
    {
        join[i] = nums2[j];
        i++;
        j++;
    }
    return (join);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int     *total_nums;
    int     t_size;
    double  result;

    total_nums = join_nums(nums1, nums1Size, nums2, nums2Size);
    if (total_nums == NULL)
        return (-1);
    t_size = nums1Size + nums2Size;
    total_nums = sort_nums(total_nums, t_size);
    result = 0; 
    if (t_size % 2 == 0)
    {
        result = (double)(total_nums[t_size / 2] + total_nums[(t_size / 2) - 1]) / 2;    
    }
    else
        result = total_nums[t_size / 2];
    return (result);   
}