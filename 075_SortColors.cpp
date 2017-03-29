//20.21%
class Solution {
public:
    void sortColors(vector<int>& nums) {
		if(nums.empty()) return;
        int size(nums.size());
		int left(0), right(size - 1);
		
		//First round, puts all 0 to the left side
		while(left < right){
			if(nums[left] == 0) 
				left++;
			else if(nums[right] != 0) 
				right--;
			else{
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
		}
		
		if(nums[left] == 0)
			left++;
		right = size - 1;
		//Second round, puts all 1 to the left side
		while(left < right){
			if(nums[left] == 1)
				left++;
			else if(nums[right] == 2)
				right--;
			else{
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
		}
    }
};

//A more clever function than mine
class Solution {
    public:
        void sortColors(int A[], int n) {
            int second=n-1, zero=0;
            for (int i=0; i<=second; i++) {
                while (A[i]==2 && i<second) swap(A[i], A[second--]);
                while (A[i]==0 && i>zero) swap(A[i], A[zero++]);
            }
        }
    };
	
// one pass in place solution
void sortColors(int A[], int n) {
    int j = 0, k = n-1;
    for (int i=0; i <= k; i++) {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        else if (A[i] == 2)
            swap(A[i--], A[k--]);
    }
}

//A great way with different thinking
void sortColors(vector<int>& nums) {
    int r=0, w=0, b=0; // label the end of different colors;
    for(int num: nums){
        if(num==0) {nums[b++]=2; nums[w++]=1; nums[r++]=0; } 
        else if(num==1) {nums[b++]=2; nums[w++]=1;}
        else if(num==2) b++;
    }
}