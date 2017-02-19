//17.35%
int thirdMax(int* nums, int numsSize) {
    assert(nums && numsSize > 0);
	//Find first max
	int first = nums[0];
	for(int i = 1; i < numsSize; i++)
		if(nums[i] > first)
			first = nums[i];
	
	//Find second max
	int second;
	int i = 0;
	while(i < numsSize && nums[i] == first)
		i++;
	if(i == numsSize)
		return first;
	second = nums[i];
	while(i < numsSize){
		if(nums[i] > second && nums[i] < first)
			second = nums[i];
		i++;
	}
	
	//Find third max
	int third;
	i = 0;
	while(i < numsSize && nums[i] >= second)
		i++;
	if(i >= numsSize)
		return first;
	third = nums[i];
	while(i < numsSize){
		if(nums[i] > third && nums[i] < second)
			third = nums[i];
		i++;
	}
	return third;
}