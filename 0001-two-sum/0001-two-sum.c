/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// nums配列の中から,２要素足し算してtargetになるものの、index配列を返す
// resultも2要素と決まりがあるため,確保するメモリは sizeof(int) * 2
// 2要素と決まりがあるため returnSize = 2
// while (i < numSize -1)　最後の値は足すものがない
// while (j < numSize) j　は最後の要素まで確認 
// 　nums[i] + nums[j] == target　の時に 
// result[0] = i, result[1] = j　にindex格納
// 見つかった場合 即return
// while を抜ける = targetになるものがないので　return (NULL)
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