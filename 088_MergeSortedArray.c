//27.55%
void merge(int* nums1, int m, int* nums2, int n) {
    if(!nums1 || !nums2 || 0 >= n)
		return;
	if( 0 >= m){
		for(int i = 0; i < n; i++)
			nums1[i] = nums2[i];
	}
	
	int *nums = (int *)malloc(sizeof(int) *(m + n));
	int i = 0, i1 = 0, i2 = 0;
	while(i1 < m && i2 < n){
		if(nums1[i1] < nums2[i2]){
			nums[i++] = nums1[i1++];
		}else{
			nums[i++] = nums2[i2++];
		}
	}
	while(i1 < m)
		nums[i++] = nums1[i1++];
	while(i2 < n)
		nums[i++] = nums2[i2++];
	
	for(i = 0; i < m + n; i++)
		nums1[i] = nums[i];
	free(nums);
}