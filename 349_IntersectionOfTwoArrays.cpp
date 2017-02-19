//53.67%
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
		
		unordered_map<int, int> unique;
		for(int num : nums1)
			unique[num] = 0;
		for(int num : nums2){
			if(unique.find(num) != unique.end()){
				if(unique[num] == 0){
					res.push_back(num);
					unique[num] = 1;
				}
			}
		}
		return res;
    }
};

//Seems more clean than mine
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};

//A solution which used more 'C++' thinking
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x))
            out.push_back(x);
    return out;
}