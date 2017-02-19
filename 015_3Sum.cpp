//0.81%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
		int size(nums.size());
		sort(nums.begin(), nums.end());
		unordered_map<int, unordered_set<int>>	table(size);
		for(int i = 0; i < size; i++)
			table[nums[i]].insert(i);
		for(int i = 0; i < size - 2;){
			for(int j = i + 1; j < size - 1; ){
				int target = 0 - nums[i] - nums[j];
				unordered_map<int, unordered_set<int>>::iterator ite = table.find(target);
				if(ite != table.end()){
					for(auto item : ite -> second){
						if(item > j){
							vector<int> temp;
							temp.push_back(nums[i]);
							temp.push_back(nums[j]);
							temp.push_back(nums[item]);
							res.push_back(temp);
							break;
						}
					}
				}
				int preJ(nums[j]);
				while(j < size - 1 && nums[++j] == preJ);
			}
			int preI(nums[i]);
			while(i < size - 2 && nums[++i] == preI);
		}
		return res;
    }
};

//A better solution from LeetCode
vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }   
    return res;
}