//71.43%
int missingNumber(int* nums, int numsSize) {
    //if(!nums || 0 >= numsSize)
	//	return -1;
	assert(nums && numsSize > 0);
	int sumNums = 0;
	for(int i = 0; i < numsSize; i++)
		sumNums += nums[i];
	int sum = (numsSize + 1) * numsSize;
	sum /= 2;
	return sum - sumNums;
}