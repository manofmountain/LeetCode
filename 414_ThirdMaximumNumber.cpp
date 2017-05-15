class Solution {
public:
    int thirdMax(vector<int>& nums) {
		if(nums.empty())
			return 0;
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return max(nums[0], nums[1]);
		auto cmp = [](int num1, int num2){ return num1 >= num2; };
        nth_element(nums.begin(), nums.begin() + 2, nums.end(), cmp);
		return nums[2];
    }
};

int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums) {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums)
        if (top3.insert(num).second && top3.size() > 3)
            top3.erase(top3.begin());
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}