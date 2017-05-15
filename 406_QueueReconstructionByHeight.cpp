//24.34%
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if(people.empty())
			return {};
		
		unordered_map<int, vector<pair<int, int> > > peopleTable;
		vector<int> heights;
		vector<pair<int, int> > res;
		for(int i = 0; i < people.size(); ++i){
			if(peopleTable.find(people[i].first) == peopleTable.end()){
				peopleTable.insert(make_pair(people[i].first, vector<pair<int, int> >(1, make_pair(people[i].second, i))));
				heights.push_back(people[i].first);
			}else
				peopleTable[people[i].first].emplace_back(people[i].second, i);
		}
		
		sort(heights.begin(), heights.end(), greater<int>());
		for(auto height : heights){
			sort(peopleTable[height].begin(), peopleTable[height].end());
			for(auto& p : peopleTable[height]){
				res.insert(res.begin() + p.first, people[p.second]);
			}
		}
		return res;	
    }
};


vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people) 
        res.insert(res.begin() + p.second, p);
    return res;
}