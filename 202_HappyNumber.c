//My old solution before

#define MAX_SIZE 1000
bool isContained(int *array, int leftPos, int rightPos, int val)
{
	int mid;
	int left = leftPos;
	int right = rightPos;
	
	if(left > right)
	{
		array[left] = val;
		return false;
	}
	while(left <= right)
	{
		mid = (left + right) >> 1;
		if(array[mid] == val)
			return true;
		else if(array[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	int i = rightPos;
	while(i >= left)
	{
		array[i + 1] = array[i];
		i--;
	}
	array[i + 1] = val;
	
	return false;
	
}


bool isHappy(int n) 
{
	if(0 >= n)
		return false;
	if(1 == n)
		return true;
	
	int temp = n;
	int tempRem = 0;
	int tempNew = 0;
	int *tempArray = (int *)malloc(sizeof(int) * MAX_SIZE);
	int len = 0;
	int tempLen = 0;
	while(temp != 1)
	{
		if(isContained(tempArray, 0, len - 1, temp))
			return false;
		len++;

		while(temp > 0)
		{
			tempRem = temp % 10;
			tempNew += (tempRem * tempRem);
			temp /= 10;		
		}
		
		temp = tempNew;
		tempNew = 0;
	}
	free(tempArray);
	if(1 == temp)
		return true;
}

//A better solution than mine ( whose idea came from to judge if a linked list exist circulation )
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

//A solution from LeetCode : Using fact all numbers in [2, 6] are not happy (and all not happy numbers end on a cycle that hits this interval):
bool isHappy(int n) {
    while(n>6){
        int next = 0;
        while(n){next+=(n%10)*(n%10); n/=10;}
        n = next;
    }
    return n==1;
}