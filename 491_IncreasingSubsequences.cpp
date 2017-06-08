
//74.86%
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() < 2)
			return {};
		
		vector<vector<int>> res;
		for(int num : nums){
			int currSize(res.size());
			for(int i = 0; i < currSize; ++i){
				if(res[i].back() < num){
					vector<int> currVec(res[i]);
					currVec.push_back(num);
					res.push_back(currVec);
				}else if(res[i].back() == num){
					res[i].push_back(num);
				}
			}
			res.push_back({num});
		}
		
		res.erase(remove_if(res.begin(), res.end(),[](const vector<int>&vec){return vec.size() == 1;}), res.end());
		return res;
    }
};

//A java solution using HashSet
public class Solution {
     public List<List<Integer>> findSubsequences(int[] nums) {
         Set<List<Integer>> res= new HashSet<List<Integer>>();
         List<Integer> holder = new ArrayList<Integer>();
         findSequence(res, holder, 0, nums);
         List result = new ArrayList(res);
         return result;
     }

    public void findSequence(Set<List<Integer>> res, List<Integer> holder, int index, int[] nums) {
        if (holder.size() >= 2) {
            res.add(new ArrayList(holder));
        }
        for (int i = index; i < nums.length; i++) {
            if(holder.size() == 0 || holder.get(holder.size() - 1) <= nums[i]) {
                holder.add(nums[i]);
                findSequence(res, holder, i + 1, nums);
                holder.remove(holder.size() - 1);
            }
        }
    }
}

//This one looks like mine, classical back-tracing method
public List<List<Integer>> findSubsequences(int[] nums) {
	List<List<Integer>> res = new ArrayList<>();
	helper(res, new ArrayList<Integer>(), nums, 0);
	return res;
}
	
private void helper(List<List<Integer>> res, List<Integer> list, int[] nums, int id) {
	if (list.size() > 1) res.add(new ArrayList<Integer>(list));
	List<Integer> unique = new ArrayList<Integer>();
	for (int i = id; i < nums.length; i++) {
		if (id > 0 && nums[i] < nums[id-1]) continue; // skip non-increase
		if (unique.contains(nums[i])) continue; // skip duplicate
		unique.add(nums[i]);
		list.add(nums[i]);
		helper(res, list, nums, i+1);
		list.remove(list.size()-1);
	}
}

//C++ dfs
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, seq, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
        if(seq.size() > 1) res.push_back(seq);
        unordered_set<int> hash;
        for(int i = pos; i < nums.size(); ++i) {
            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                seq.push_back(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};