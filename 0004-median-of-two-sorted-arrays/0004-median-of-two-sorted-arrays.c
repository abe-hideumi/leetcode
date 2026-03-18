double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int n1 = 0, n2 = 0, val = 0;
    int result1 = 0, result2 = 0;
    for (int i = 0; i <= mid2; i++)
    {
        if (n1 < nums1Size && (n2 >= nums2Size || nums1[n1] < nums2[n2]))
        {
            val = nums1[n1];
            n1++;
        }
        else if (n2 < nums2Size)
        {
            val = nums2[n2];
            n2++;
        }
        if (i == mid1)
            result1 = val;
        if (i == mid2)
            result2 = val;
    }
    printf("%d\n", result1);
    printf("%d\n", result1);
    return ((double)(result1 + result2) / 2);
}