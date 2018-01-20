/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
/*
Runtime: 4 ms
*/
int maxSubArray(int* nums, int numsSize) {
    int max_sum = INT_MIN;
    int cur_sum = 0;
    for(int i=0;i<numsSize;i++){
        if(cur_sum>0)
            cur_sum+=nums[i];
        else    
            cur_sum=nums[i];
        if(cur_sum>max_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}
