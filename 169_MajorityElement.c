//41.25%
int majorityElement(int* nums, int numsSize) {
    if(numsSize == 1)
		return nums[0];
	int left = majorityElement(nums, numsSize / 2);
	int right = majorityElement(nums + numsSize / 2, numsSize - numsSize / 2);
	if(left == right)
		return left;
	int leftNum = 0, rightNum = 0;
	for(int i = 0; i < numsSize; i++)
		if(nums[i] == right)
			rightNum++;
		else if(nums[i] == left)
			leftNum++;
	
	if(leftNum > rightNum)
		return left;
	return right;
}