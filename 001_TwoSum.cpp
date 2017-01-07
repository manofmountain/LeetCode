# LeetCode 001
# Two Sum

// Beat 37.8% others
#include <map>
class Solution001 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		//Check boundary
		if(1 >= nums.size())
			return result;
		
		//Put all values into map(sorted dictionary)
		std::map<int, int> numsMap;
		int size = nums.size();
		for(int index = 0; index < size; index++)
			numsMap[nums[index]] = index;
		
		//Check to see if any index combinations existed
		for(int firstIndex = 0; firstIndex < size - 1; firstIndex++)
		{
			int valueSec = target - nums[firstIndex];
			std::map<int, int>::iterator posSec = numsMap.find(valueSec);
			if(posSec != numsMap.end() && posSec -> second != firstIndex)
			{
				result.push_back(firstIndex);
				result.push_back(posSec -> second);
				break;
			}	
		}
		return result;
    }
};

//Beat 67.1% after using 'unordered_map' rather than 'map'
class Solution002 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		//Check boundary
		int size = nums.size();
		if(1 >= size)
			return result;
		
		//Put all values into hash map(sorted dictionary)
		std::unordered_map<int, int> numsMap;
		
		for(int index = 0; index < size; index++)
			numsMap[nums[index]] = index;
		
		//Check to see if any index combinations existed
		for(int firstIndex = 0; firstIndex < size - 1; firstIndex++)
		{
			int valueSec = target - nums[firstIndex];
			std::unordered_map<int, int>::iterator posSec = numsMap.find(valueSec);
			if(posSec != numsMap.end() && posSec -> second != firstIndex)
			{
				result.push_back(firstIndex);
				result.push_back(posSec -> second);
				break;
			}	
		}
		return result;
    }
};

//Reference the answer provided by the website - LeetCode -- Beat 93.27% persons
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		//Check boundary
		int size = nums.size();
		if(1 >= size)
			return result;
		
		//Put all values into hash map(sorted dictionary)
		std::unordered_map<int, int> numsMap;
		for(int index = 0; index < size; index++)
		{
			int valueFst = nums[index];
			int valueSec = target - valueFst;
			std::unordered_map<int, int>::iterator posSec = numsMap.find(valueSec);
			if(posSec != numsMap.end())
			{
				result.push_back(posSec -> second);
				result.push_back(index);
				break;
			}
			numsMap[nums[index]] = index;		
		}
		return result;
    }
};
