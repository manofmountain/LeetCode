//88.33%
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty())
			return {};
		vector<int> pointers(nums1.size());
		vector<pair<int, int> > res;
		priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;
		for(int i = 0; i < nums1.size(); ++i){
			q.push(make_pair(nums1[i] + nums2[0], i));
		}
		while(res.size() < k && !q.empty()){
			int index(q.top().second);
			q.pop();
			res.push_back(make_pair(nums1[index], nums2[pointers[index]++]));
			if(pointers[index] < nums2.size())
				q.push(make_pair(nums1[index] + nums2[pointers[index]], index));
		}
		
		return res;
    }
};

//75.15%
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty())
			return {};
		vector<int> pointers(nums1.size());
		vector<pair<int, int> > res, ans;
		for(int i = 0; i < nums1.size(); ++i)
			res.emplace_back(nums1[i] + nums2[0], i);
		auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.first > p2.first; };
		make_heap(res.begin(), res.end(), cmp);
		//vector<pair<int, int> > ans;
		ans.reserve(k);
		for(int i = 0; i < k && !res.empty(); ++i){
			pop_heap(res.begin(), res.end(), cmp);
			int index(res.back().second);
			ans.emplace_back(nums1[index], nums2[pointers[index]++]);
			if(pointers[index] < nums2.size()){
				res.back().first = nums1[index] + nums2[pointers[index]];
				push_heap(res.begin(), res.end(), cmp);
			}else
				res.pop_back();
		}
		return ans;
    }
};

//Wonderful solution and have the same thinking way with mine
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};
