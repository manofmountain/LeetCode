//28.48%
int singleNumber(int* nums, int numsSize) {
    //if(!nums || 0 >= numsSize)
	//	return 0;
	int res = nums[0];
	for(int i = 1; i < numsSize; i++)
		res ^= nums[i];
	return res;
}