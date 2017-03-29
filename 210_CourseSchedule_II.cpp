//44.15%
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > dependencies(numCourses);
		vector<int> inDegrees(numCourses);
		for(auto& p : prerequisites){
			++inDegrees[p.first];
			dependencies[p.second].push_back(p.first);
		}
		queue<int> q;
		for(int i = 0; i < inDegrees.size(); ++i){
			if(inDegrees[i] == 0)
				q.push(i);
		}
		vector<int> res(numCourses);
		int cnt(0);
		while(!q.empty()){
			int node(q.front());
			q.pop();
			res[cnt++] = node;
			changeInDegrees(dependencies, inDegrees, q, node);
		}
		if(cnt != numCourses)
			return vector<int>();
		else
			return res;	
    }
private:
	inline void changeInDegrees(const vector<vector<int> >& dependencies, vector<int>& inDegrees, queue<int>& q, int node){
		for(int i = 0; i < dependencies[node].size(); ++i){
			if(--inDegrees[dependencies[node][i]] == 0)
				q.push(dependencies[node][i]);
		}
	}
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};