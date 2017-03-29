//17.2%
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		restoreIpAddressHelper(res, s, "", 0, 0, s.size());
		return res;
    }
private:
	void restoreIpAddressHelper(vector<string>& res, const string& s, string target, int start, int index, int size){
		if(index == 3){
			if(size <= start || start + 3 < size || start + 3 == size && s.substr(start) > "255")
				return;
			if(start < size - 1 && s[start] == '0')
				return;
			res.push_back(target + s.substr(start));
			return;
		}
		//Has 1/ 2/ 3 digits separately on 'index' position
		if(start <= size - 2)
			restoreIpAddressHelper(res, s, target + s.substr(start, 1) + '.', start + 1, index + 1, size);
		if(start <= size - 3 && s[start] != '0')
			restoreIpAddressHelper(res, s, target + s.substr(start, 2) + '.', start + 2, index + 1, size);
		if(start <= size - 4 && s[start] != '0' && s.substr(start, 3) <= "255")
			restoreIpAddressHelper(res, s, target + s.substr(start, 3) + '.', start + 3, index + 1, size);
	}
};


//In a very different thinking way
    // c++  code
	//17.2%
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
	
//An iterative Java solution	
public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>();
        int len = s.length();
        for(int i = 1; i<4 && i<len-2; i++){
            for(int j = i+1; j<i+4 && j<len-1; j++){
                for(int k = j+1; k<j+4 && k<len; k++){
                    String s1 = s.substring(0,i), s2 = s.substring(i,j), s3 = s.substring(j,k), s4 = s.substring(k,len);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
                        res.add(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        return res;
    }
    public boolean isValid(String s){
        if(s.length()>3 || s.length()==0 || (s.charAt(0)=='0' && s.length()>1) || Integer.parseInt(s)>255)
            return false;
        return true;
    }
}

//Another Java solution which uses DFS
public List<String> restoreIpAddresses(String s) {
    List<String> solutions = new ArrayList<String>();
    restoreIp(s, solutions, 0, "", 0);
    return solutions;
}

private void restoreIp(String ip, List<String> solutions, int idx, String restored, int count) {
    if (count > 4) return;
    if (count == 4 && idx == ip.length()) solutions.add(restored);
    
    for (int i=1; i<4; i++) {
        if (idx+i > ip.length()) break;
        String s = ip.substring(idx,idx+i);
        if ((s.startsWith("0") && s.length()>1) || (i==3 && Integer.parseInt(s) >= 256)) continue;
        restoreIp(ip, solutions, idx+i, restored+s+(count==3?"" : "."), count+1);
    }
}