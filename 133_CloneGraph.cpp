/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//69.86%
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
			return NULL;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> traced;
		return cloneGraphHelper(node, traced);
    }
private:
	UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& traced){
		if(!node)
			return NULL;
		if(traced.find(node) != traced.end())
			return traced[node];
		UndirectedGraphNode *res(new UndirectedGraphNode(node -> label));
		traced[node] = res;
		for(auto childNode : node -> neighbors)
			(res -> neighbors).push_back(cloneGraphHelper(childNode, traced));
		return res;
	}
};

//62.62%
//A good solution from LeetCode
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};

//BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> toVisit;
        toVisit.push(node);
        while (!toVisit.empty()) {
            UndirectedGraphNode* cur = toVisit.front();
            toVisit.pop();
            for (UndirectedGraphNode* neigh : cur -> neighbors) {
                if (mp.find(neigh) == mp.end()) {
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh -> label);
                    mp[neigh] = neigh_copy;
                    toVisit.push(neigh);
                }
                mp[cur] -> neighbors.push_back(mp[neigh]);
            }
        }
        return copy; 
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};