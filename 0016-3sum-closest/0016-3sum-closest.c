void sort_nums(int *nums, int numsSize)
{
    int tmp;

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] >= nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int result;

    sort_nums(nums, numsSize);
    result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++)
    {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(target - result) > abs(target - sum))
                result = sum;
            if (target < sum)
                k--;
            else if (target > sum)
                j++;     
            else 
                return (nums[i] + nums[j] + nums[k]);
        }
    }
    return (result);
}