//42.58%
class Solution {
public:
    string simplifyPath(string path) {
		string res("/");
        vector<string> dirSets;
		size_t start = path.find_first_not_of('/');
		if(start == string::npos)
			return res;
		string dir;
		while(start != path.size()){
			if(path[start] == '/'){
				if(dir == ".."){
					if(!dirSets.empty())
						dirSets.pop_back();
				}else if (dir != "." && !dir.empty()){
				dirSets.push_back(dir);
				}
				dir = "";
			}else if(path[start] == ' ')
				continue;
			else{
				dir += path[start];
			}
			start++;
		}
		if(!dir.empty()){
			if(dir == ".."){
				if(!dirSets.empty())
					dirSets.pop_back();
			}else if (dir != "."){
				dirSets.push_back(dir);
			}
		}

		for(auto dir : dirSets){
			res += dir;
			res += "/";
		}
		if(!dirSets.empty())
			res.pop_back();
		return res;
    }
};

//A really great method to remove characters in a string object
//str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());

//This solution from LeetCode teachs me a lot
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}