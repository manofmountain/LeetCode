//2.39%
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() && !version2.empty()){
			size_t pos1 = version1.find_first_of('.');
			string subStr1 = version1.substr(0, pos1);
			int ver1 = stoi(subStr1);
			size_t pos2 = version2.find_first_of('.');
			string subStr2 = version2.substr(0, pos2);
			int ver2 = stoi(subStr2);
			if(ver1 > ver2)
				return 1;
			else if(ver1 < ver2)
				return -1;
			if(pos1 == string::npos)
				version1 = "";
			else
				version1 = version1.substr(pos1 + 1, version1.size() - pos1 - 1);
			if(pos2 == string::npos)
				version2 = "";
			else
				version2 = version2.substr(pos2 + 1, version2.size() - pos2 - 1);
		}
		while(!version1.empty()){
			size_t pos1 = version1.find_first_of('.');
			string subStr1 = version1.substr(0, pos1);
			int ver1 = stoi(subStr1);
			if(ver1)
				return 1;
			if(pos1 == string::npos)
				version1 = "";
			else
				version1 = version1.substr(pos1 + 1, version1.size() - pos1 - 1);
		}
		while(!version2.empty()){
			size_t pos2 = version2.find_first_of('.');
			string subStr2 = version2.substr(0, pos2);
			int ver2 = stoi(subStr2);
			if(ver2)
				return -1;
			if(pos2 == string::npos)
				version2 = "";
			else
				version2 = version2.substr(pos2 + 1, version2.size() - pos2 - 1);
		}
		return 0;
    }
};

//Better than mine, need to be familar with string's function method like 'substr' and 'stoi'
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (; version1 != version2; version1 = nextSubstr(version1), version2 = nextSubstr(version2)) {
            int gap = stoi(version1) - stoi(version2);
            if (gap != 0) {
                return gap > 0 ? 1 : -1;
            }
        }
        return 0;
    }
    
    string nextSubstr(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str.at(i) == '.') {
                return str.substr(i + 1);
            }
        }
        return "0";
    }
};

//Need to have only one circulation
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}