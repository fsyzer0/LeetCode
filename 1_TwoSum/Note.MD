Here're the simple codes for each method
### Method 1
Get the array number one by one, and calculate the value, if the value equal to target
Get the index and return them

**Result:**
101ms
Beats 53.02%

```
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
```

### Method 2
Direct use the target number to calculate the rest number r, and try find r index in the input array.

Result:
56ms
Beats 86.80%

```
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
```
