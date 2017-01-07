
//15.41%
//O(n)
int removeDuplicates(int* nums, int numsSize) {
    if(!nums || 1 >= numsSize)
		return numsSize;
	
	int size = 1;
	int val = nums[0];
	for(int i = 1; i < numsSize; i++)
		if(nums[i] == val){
			continue;
		else{
			nums[size++] = nums[i];
			val = nums[i];
		}
	}
	return size;
}

