//9.53%
/*
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
*/
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        if(equations.empty() || queries.empty())
			return {};
		
		unordered_map<string, vector<pair<string, double> > > equationsTable;
		for(int i = 0; i < equations.size(); ++i){
			if(equationsTable.find(equations[i].first) == equationsTable.end())
				equationsTable.insert(make_pair(equations[i].first, vector<pair<string, double> >()));
			equationsTable[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
			if(values[i] != 0)
				equationsTable[equations[i].second].push_back(make_pair(equations[i].first, 1.0 / values[i]));
		}
		
		vector<double> res;
		res.reserve(queries.size());
		for(auto& query : queries){
			unordered_set<string> traced;
			vector<double> path;
			if(reachable(query.first, query.second, path, traced, equationsTable)){
				double temp(1.0);
				for(double val : path)
					temp *= val;
				res.push_back(temp);
			}else
				res.push_back(-1.0);
		}
		return res;	
    }
private:
	bool reachable(const string& start, const string& end, vector<double>& path, unordered_set<string>& traced, unordered_map<string, vector<pair<string, double> > >& equationsTable){
		if(equationsTable.find(start) == equationsTable.end())
			return false;
		if(start == end)
			return true;
		traced.insert(start);
		for(auto & p : equationsTable[start]){
			if(traced.find(p.first) != traced.end())
				continue;
			path.push_back(p.second);
			if(p.first == end)
				return true;
			if(reachable(p.first, end, path, traced, equationsTable))
				return true;
			path.pop_back();
		}
		return false;
	}
};


//Other guy's solution which looks like mine
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
        vector<double>& values, vector<pair<string, string>> query) 
    {
        unordered_map<string,unordered_map<string, double>> m;
        vector<double> res;
        for (int i = 0; i < values.size(); ++i)
        {
            m[equations[i].first].insert(make_pair(equations[i].second,values[i]));
            if(values[i]!=0)
                m[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
        }

        for (auto i : query)
        {
            unordered_set<string> s;
            double tmp = check(i.first,i.second,m,s);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1);
        }
        return res;
    }

    double check(string up, string down, 
            unordered_map<string,unordered_map<string, double>> &m,
            unordered_set<string> &s)
    {
        if(m[up].find(down) != m[up].end()) return m[up][down];
        for (auto i : m[up])
        {
            if(s.find(i.first) == s.end())
            {
                s.insert(i.first);
                double tmp = check(i.first,down,m,s);
                if(tmp) return i.second*tmp;
            }
        }
        return 0;
    }
};