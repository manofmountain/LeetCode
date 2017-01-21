//19.51%
void rotate(int* nums, int numsSize, int k) {
    if(!nums)
		return;
	if(k >= numsSize)
		k %= numsSize;
	if(!k)
		return;
	if(numsSize > k * 2){
		for(int i = 0; i < k; i++){
			int temp = nums[i];
			nums[i] = nums[numsSize - k + i];
			nums[numsSize - k + i] = temp;
		}
		rotate(nums + k, numsSize - k, k);
	}else{
		for(int i = 0; i < numsSize - k; i++){
			int temp = nums[i];
			nums[i] = nums[k + i];
			nums[k + i] = temp;
		}
		rotate(nums, k, 2 * k - numsSize);
	}
}