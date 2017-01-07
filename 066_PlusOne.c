/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//7.33%
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(!digits || 0 >= digitsSize)
		return NULL;
	
	int addition = 1;
	for(int i = digitsSize - 1; i >= 0; i--){
		if(digits[i] + addition < 10){
			digits[i] += addition;
			*returnSize = digitsSize;
			return digits;
		}else{
			digits[i] = 0;
			//addition = 1;
		}
	}
	
	int *rst = (int *)malloc(sizeof(int) * (digitsSize + 1));
	for(int i = 1; i <= digitsSize; i++)
		rst[i] = 0;
	rst[0] = 1;
	*returnSize = digitsSize + 1;
	return rst;
}