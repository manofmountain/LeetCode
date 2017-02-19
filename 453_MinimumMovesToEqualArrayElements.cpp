/*
It is a math question
let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;

After, say m moves, we get all the numbers as x , and we will get the following equation

 sum + m * (n - 1) = x * n
and actually,

  x = minNum + m
and finally, we will get

  sum - minNum * n = m
So, it is clear and easy now.
*/


//Timeout limit encountered
class Solution {
public:
    int minMoves(vector<int>& nums) {
		int res(0), size(nums.size());
		if(1 >= size)
			return 0;
		if(2 == size){
			if(nums[0] == nums[1])
				return 0;
			else{
				if(nums[1] > nums[0])
					return nums[1] - nums[0];
				return nums[0] - nums[1];
			}
		}
		
		//sort(nums.begin(), nums.end());
		int min(nums[0]), max(nums[0]);
		int minIndex(0), maxIndex(0);
		for(int i = 1; i < size; i++){
			if(nums[i] > max){
				max = nums[i];
				maxIndex = i;
			}
			if(nums[i] < min){
				min = nums[i];
				minIndex = i;
			}
		}
		swap(nums[0], nums[minIndex]);
		swap(nums[size - 1], nums[maxIndex]);
		int secondMax(nums[1]), secondMaxIndex(1);
		for(int i = 2; i < size; i++){
			if(nums[i] > secondMax && nums[i] < max){
				secondMax = nums[i];
				secondMaxIndex = i;
			}
		}
		swap(nums[size - 2], nums[secondMaxIndex]);
		
		while(nums[0] != nums[size - 1]){
			//Move
			nums[0]++;
			nums[size - 2]++;
			if(nums[size - 2] > nums[size - 1])
				swap(nums[size - 1], nums[size - 2]);
			res++;
		}
		return res;
    }
};

//Timeout limit encountered
class Solution {
public:
    int minMoves(vector<int>& nums) {
		int res(0), size(nums.size());
		if(1 >= size)
			return 0;
		if(2 == size){
			if(nums[0] == nums[1])
				return 0;
			else{
				if(nums[1] > nums[0])
					return nums[1] - nums[0];
				return nums[0] - nums[1];
			}
		}
		
		sort(nums.begin(), nums.end());
		while(nums[0] != nums[size - 1]){
			int diff(0);
			for(int j = size - 1; j > 0; j--){
				diff = nums[j] - nums[j - 1];
				if(diff)
					break;
			}
			for(int i = 0; i < size - 1; i++){
				nums[i] += diff;
			}
			res += diff;
			//Need to be put into a good place
			int index = binarySearchIndex(nums, 1, size - 2, nums[size - 1]);
			swap(nums[size - 1], nums[index]);			
		}
		return res;
    }
private:
	int binarySearchIndex(vector<int>& nums, int left, int right, int max){
		//int res(right);
		//int mid(right);
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] > max){
				if(nums[mid - 1] <= max)
					return mid;
				else
					right = mid - 1;
			}else{
				if(nums[mid + 1] > max)
					return mid + 1;
				else
					left = mid + 1;
			}
		}
		return right;
	}		
};