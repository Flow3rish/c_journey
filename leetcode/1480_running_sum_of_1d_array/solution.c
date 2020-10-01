#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * returnSize: an out parameter with the size of the returned array
 */
int *runningSum(int *nums, int numsSize, int *returnSize)
{
    int *running_sum_arr = (int *)malloc(sizeof(int) * numsSize);
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        running_sum_arr[i] = nums[i] + sum;
        sum += nums[i];
    }
    /* output */
    *returnSize = numsSize;
    return running_sum_arr;
}

void printIntArray(int *arr, int arrSize)
{
    printf("[ ");
    for (int i = 0; i < arrSize; i++)
    {
        if (i == arrSize - 1)
        {
            printf("%d ]", arr[i]);
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int numsSize = argc - 1;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }
    int returnSize;
    int *result = runningSum(nums, numsSize, &returnSize);
    printIntArray(result, numsSize);
    free(nums);
    free(result);

    return 0;
}
