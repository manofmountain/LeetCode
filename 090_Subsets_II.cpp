//33.20%
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        vector<int> sub;
		vector<vector<int>> res;
		int size(nums.size());
		subsetsWithDupHelper(res, sub, 0, size, nums);
		return res;
    }
private:
	void subsetsWithDupHelper(vector<vector<int>>& res, vector<int>& sub, int start, int size, vector<int>& nums){
		res.push_back(sub);
		for(int i = start; i < size; i++){
			sub.push_back(nums[i]);
			subsetsWithDupHelper(res, sub, i + 1, size, nums);
			sub.pop_back();
			while(i < size - 1 && nums[i + 1] == nums[i]) i++;
		}
	}
};


//A really good iterative solution and I put its explanation below too
/*  
To solve this problem, it is helpful to first think how many subsets are there. If there is no duplicate element, the answer is simply 2^n, where n is the number of elements. This is because you have two choices for each element, either putting it into the subset or not. So all subsets for this no-duplicate set can be easily constructed:
num of subset

(1 to 2^0) empty set is the first subset
(2^0+1 to 2^1) add the first element into subset from (1)
(2^1+1 to 2^2) add the second element into subset (1 to 2^1)
(2^2+1 to 2^3) add the third element into subset (1 to 2^2)
....
(2^(n-1)+1 to 2^n) add the nth element into subset(1 to 2^(n-1))
Then how many subsets are there if there are duplicate elements? We can treat duplicate element as a spacial element. For example, if we have duplicate elements (5, 5), instead of treating them as two elements that are duplicate, we can treat it as one special element 5, but this element has more than two choices: you can either NOT put it into the subset, or put ONE 5 into the subset, or put TWO 5s into the subset. Therefore, we are given an array (a1, a2, a3, ..., an) with each of them appearing (k1, k2, k3, ..., kn) times, the number of subset is (k1+1)(k2+1)...(kn+1). We can easily see how to write down all the subsets similar to the approach above.
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};

//This is a good one and help me finish my below one
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> ret = {{}};
    int size = 0, startIndex = 0;
    for (int i = 0; i < S.size(); i++) {
        startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
        size = ret.size();
        for (int j = startIndex; j < size; j++) {
            vector<int> temp = ret[j];
            temp.push_back(S[i]);
            ret.push_back(temp);
        }
    }
    return ret;
}
//Can not make it work anyway
//8.39%
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res(1, vector<int>());
		int start(0);
		for(int i = 0; i < nums.size(); i++){
			int size(res.size());
			for(int j = start; j < size; j++){
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
			start = i < nums.size() - 1 && nums[i + 1] == nums[i] ? size : 0;
		}
		return res;
    }
};