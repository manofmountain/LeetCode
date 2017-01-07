//30.7%
int removeElement(int* nums, int numsSize, int val) {
    //Check boundary
	if(!nums || 0 >= numsSize)
		return numsSize;
	
	int i = 0, j = numsSize - 1;
	for(; i <= j; i++)
		if(nums[i] == val){
			while(j > i && nums[j] == val)
				j--;
			if(j > i){
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				j--;
			}
			else
				return i;
		}
	
	return i;	
}