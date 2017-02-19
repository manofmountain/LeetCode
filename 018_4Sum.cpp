//73.07%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //assert(nums.size() >= 4);
		int size(nums.size());
		vector<vector<int>> res;
		if(size < 4)
			return res;
		
		sort(nums.begin(), nums.end());
		for(int i = 0; i <= size - 4;){
			vector<vector<int>> tuples = threeSum(nums, i + 1, size, target - nums[i]);
			for(auto tuple : tuples){
				tuple[0] = nums[i];
				res.push_back(tuple);
			}
			i++;
			while(i <= size - 4 && nums[i] == nums[i - 1]) i++;
		}
		return res;
    }
private:
	vector<vector<int>> threeSum(vector<int>& nums, int start, int size, int target){
		vector<vector<int>> tuples;
		while(start <= size - 3){
			int goal(target - nums[start]);
			int left(start + 1), right(size - 1);
			while(left < right){
				int temp(nums[left] + nums[right]);
				if(temp > goal){
					right--;
				}
				else if(temp < goal){
					left++;
				}
				else{
					vector<int> tuple(4);
					tuple[1] = nums[start];
					tuple[2] = nums[left];
					tuple[3] = nums[right];
					tuples.push_back(tuple);
					left++;
					right--;
					while(right > left && nums[right] == nums[right + 1]) right--;
					while(left < right && nums[left] == nums[left - 1]) left++;
				}
			}
			start++;
			while(start <= size - 3 && nums[start] == nums[start - 1]) start++;
		}
		return tuples;
	}
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};

//This one looks like mine and use iterative ways
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    
        vector<vector<int> > res;
    
        if (num.empty())
            return res;
    
        std::sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < num.size(); j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    
    }
};