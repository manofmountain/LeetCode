//19.48%
class Solution {
public:
    string validIPAddress(string IP) {
        const string ipv4  = "IPv4";
		const string ipv6  = "IPv6";
		const string neither  = "Neither";
		int start(0), cnt(0), ipFlag(0);
		int i = start;
		for(; i < IP.size(); ++i){
			if(IP[i] == '.'){
				//If found ':' before
				if(ipFlag == 2)
					return neither;
				ipFlag = 1;
				//Check if satisfied 'ipv4' substring
				if(i - start > 3 || i - start > 1 && IP[start] == '0' || i == start)
					return neither;
				int sum(0);
				for(int k = start; k < i; ++k){
					if(IP[k] >= '0' && IP[k] <= '9')
						sum = 10 * sum + (IP[k] - '0');
					else
						return neither;
				}
				if(sum > 255)
					return neither;
				start = i + 1;
				++cnt;
			}else if(IP[i] == ':'){
				if(ipFlag == 1)
					return neither;
				ipFlag = 2;
				//Check if satisfied 'ipv6' substring
				if(i - start > 4 || i == start)
					return neither;					
				start = i + 1;
				++cnt;
			}else if(!(IP[i] >= '0' && IP[i] <= '9' || IP[i] >= 'A' && IP[i] <= 'F' || IP[i] >= 'a' && IP[i] <= 'f'))
				return neither;
		}
		
		if(ipFlag == 1){
			//Check if it's ipv4
			if(cnt != 3)
				return neither;
			if(i - start > 3 || i - start > 1 && IP[start] == '0' || i == start || stoi(IP.substr(start, i - start)) > 255)
				return neither;
			return ipv4;
		}else if(ipFlag == 2){
			//Check if it's ipv6
			if(cnt != 7)
				return neither;
			if(i - start > 4 || i == start)
				return neither;
			return ipv6;
		}else
			return neither;
    }
};


//Another solution from LeetCode
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    
    bool isValidIPv4Block(string& block) {
    	int num = 0;
    	if (block.size() > 0 && block.size() <= 3) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        // special case: if c is a leading zero and there are characters left
    	        if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1))
    		    return false;
    	        else {
    		    num *= 10;
    		    num += c - '0';
    	        }
    	    }
    	    return num <= 255;
    	}
    	return false;
    }
    
    bool isValidIPv6Block(string& block) {
    	if (block.size() > 0 && block.size() <= 4) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        if (validIPv6Chars.find(c) == string::npos)
    	    	    return false;
    	    }
    	    return true;
    	}
    	return false;
    }
    
    string validIPAddress(string IP) {
    	string ans[3] = {"IPv4", "IPv6", "Neither"};
    	stringstream ss(IP);
    	string block;
    	// ipv4 candidate
    	if (IP.substr(0, 4).find('.') != string::npos) {
    	    for (int i = 0; i < 4; i++) {
    		if (!getline(ss, block, '.') || !isValidIPv4Block(block))
    	   	    return ans[2];
    	    }
    	    return ss.eof() ? ans[0] : ans[2];
    	}
    	// ipv6 candidate
    	else if (IP.substr(0, 5).find(':') != string::npos) {
    	    for (int i = 0; i < 8; i++) {
    		if (!getline(ss, block, ':') || !isValidIPv6Block(block))
    		    return ans[2];
    	    }
    	    return ss.eof() ? ans[1] : ans[2];
    	}
    
    	return ans[2];
    }