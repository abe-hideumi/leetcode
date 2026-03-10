/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i;
    int j;
    int *result;

    result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    i = 0;
    while (i < numsSize - 1)
    {
        j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return (result);
            }
            j++;
        }
        i++;
    }
    return (NULL);
}