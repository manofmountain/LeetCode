//94.63%
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res(0);
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int i(0), size(s.size());
		for(auto greed : g){
			while(i < size){
				if(s[i++] >= greed){
					res++;
					break;
				}
			}
			if(i >= size)
				break;
		}
		return res;
    }
};