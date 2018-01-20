/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
/*
Runtime: 16 ms
*/
#define MAX(a,b)    a>b?a:b
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int max = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==1)
            count++;
        else{
            max = MAX(max, count);
            count = 0;
        }
    }
    max = MAX(max, count);
    return max;
}
