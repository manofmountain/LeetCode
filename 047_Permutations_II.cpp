//42.1%
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if(nums.empty()) return res;
		int size(nums.size());
		permuteUniqueHelper(nums, 0, size, res);
		return res;
    }
private:
	void permuteUniqueHelper(vector<int>& nums, int left, int right, vector<vector<int>>& res){
		if(left == right){
			res.push_back(nums);
			return;
		}
		unordered_set<int> table;
		for(int i = left; i < right; i++){
			if(table.find(nums[i]) != table.end())
				continue;
			table.insert(nums[i]);
			swap(nums[left], nums[i]);
			permuteUniqueHelper(nums, left + 1, right, res);
			swap(nums[left], nums[i]);
		}
	}
};

//Another way different with mine
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

//Another thinking way
class Solution {
public:
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int>> v;
    vector<int> r;
    map<int, int> map;
    for (int i : num)
    {
        if (map.find(i) == map.end()) map[i] = 0;
        map[i]++;
    }
    permuteUnique(v, r, map, num.size());
    return v;
}

void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
{
    if (n <= 0)
    {
        v.push_back(r);
        return;
    }
    for (auto &p : map)
    {
        if (p.second <= 0) continue;
        p.second--;
        r.push_back(p.first);
        permuteUnique(v, r, map, n - 1);
        r.pop_back();
        p.second++;
    }
}
};