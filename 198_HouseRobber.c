int rob(int* nums, int numsSize) {
    if(!nums || 0 >= numsSize)
		return 0;
	int s1 = nums[0] + rob(nums + 2, numsSize - 2);
	int s2 = rob(nums + 1, numsSize - 1);
	return s1 > s2 ? s1 : s2;
}

//2.75%
int rob(int* nums, int numsSize) {
    if(!nums || 0 >= numsSize)
		return 0;
	int s0 = nums[0];
	if(1 >= numsSize)
		return s0;
	int s1 = nums[1] > nums[0] ? nums[1] : nums[0];
	for(int i = 2; i < numsSize; i++){
		int temp = nums[i] + s0 > s1 ? nums[i] + s0 : s1;
		s0 = s1;
		s1 = temp;
	}
	return s1;
}