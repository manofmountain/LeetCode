//21%
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> numSet;
		for(vector<int>::const_iterator num = nums.begin(); num != nums.end(); num++){
			if(numSet.find(*num) != numSet.end())
				return true;
			numSet.insert(*num);
		}
		return false;
    }
};

#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};