//39.7%
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size(nums.size());
		vector<string> res;
		vector<int> numsClone(nums);	
		
		//for(int i = 0; i < size; i++)
		//	numsWithIndex.push_back(pair<int, int>(nums[i], i));
		sort(numsClone.begin(), numsClone.end(), comparePair);
		unordered_map<int, int> rankTable;
		//vector<int> rankTable(size);
		for(int i = 0; i < size; i++){
			rankTable[numsClone[i]] = i;
		}
		string medals[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
		for(int i = 0; i < size; i++){
			if(rankTable[nums[i]] < 3)
				res.push_back(medals[rankTable[nums[i]]]);
			else
				res.push_back(to_string(rankTable[nums[i]] + 1));
		}
		return res;
    }
private:
	static bool comparePair(int p1, int p2){
		return p1 > p2;
	}
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        for(int i=0; i<nums.size(); ++i) rank.push_back(i);
        
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
        vector<string> ranks(nums.size());
        
        for(int i=3; i<nums.size(); ++i){
            ranks[rank[i]] = std::to_string(i+1);
        }
        
        if(nums.size() > 0) ranks[rank[0]] = "Gold Medal";
        if(nums.size() > 1) ranks[rank[1]] = "Silver Medal";
        if(nums.size() > 2) ranks[rank[2]] = "Bronze Medal";
        
        return ranks;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> res(nums.size(),"");
        int count = 1;
        for(int i=0; i<nums.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;}
            else {res[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return res;
    }
};