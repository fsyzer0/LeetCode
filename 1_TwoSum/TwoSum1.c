/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define METHOD_CHOOSE 3

#if METHOD_CHOOSE == 1
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, t;
    int *ret;

    *returnSize = 2;
    // I only need to return 2 numbers
    ret = (int*)calloc(2, sizeof(int));

    for (i=0; i<numsSize; i++){
        for (j=i+1; j<numsSize; j++){
            t=nums[i] + nums[j];
            if (t == target){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return ret;
}


#elif METHOD_CHOOSE == 2
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, r;
    int *ret;

    *returnSize = 2;
    // I only need to return 2 numbers
    ret = (int*)calloc(2, sizeof(int));

    // use i, j for double for loop
    for (i=0; i<numsSize; i++){
        r = target-nums[i];
        for (j=i+1; j<numsSize; j++){
            if (r==nums[j]){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return ret;
}
#elif METHOD_CHOOSE == 3
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, r;
    int *ret;

    *returnSize = 2;
    // I only need to return 2 numbers
    ret = (int*)malloc(2*sizeof(int));

    // use i, j for double for loop
    for (i=0; i<numsSize; i++){
        r = target-nums[i];
        for (j=i+1; j<numsSize; j++){
            if (r==nums[j]){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return ret;
}
#else


#endif