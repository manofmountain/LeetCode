//32.79%
typedef struct {
    int size;
	int *sumRanges;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    if(!nums || 0 >= numsSize)
		return NULL;
	NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
	obj -> size = numsSize;
	obj -> sumRanges = (int *)malloc(sizeof(int) * numsSize);
	obj -> sumRanges[0] = nums[0];
	for(int i = 1; i < numsSize; i++){
		obj -> sumRanges[i] = obj -> sumRanges[i - 1] + nums[i];
	}
	return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    //return (!obj || i > j) ? -1 : obj -> sumRanges[i][j - i];
	if(!i)
		return obj -> sumRanges[j];
	else
		return obj -> sumRanges[j] - obj -> sumRanges[i - 1];
}

void numArrayFree(NumArray* obj) {
    if(!obj)
		return;
	free(obj -> sumRanges);
	free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */