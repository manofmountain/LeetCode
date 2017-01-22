//43.4%
void moveZeroes(int* nums, int numsSize) {
    int left = 0, right = 0;
	while(right < numsSize){
		if(!nums[right])
			right++;
		else{
			if(left != right){
				nums[left] = nums[right];
				nums[right] = 0;
			}
			left++;
			right++;
		}
	}	
}