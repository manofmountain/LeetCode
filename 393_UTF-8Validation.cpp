//85.74%
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.empty())
			return true;
		int cnt(0);
		for(int val : data){
			if(!(val & 0x80)){ //val = 0xxx xxxx
				if(cnt)
					return false;
			}else if(!(val & 0x40)){ //val = 10xx xxxx
				if(!cnt)
					return false;
				--cnt;
			}else{ //val = 11xx xxxx
				if(cnt)
					return false;
				cnt = 1;
				unsigned flag = 0x20;
				while(val & flag){
					flag >>= 1;
					++cnt;
					if(cnt > 3)
						return false;
				}
			}
		}
		if(cnt)
			return false;
		return true;		
    }
};

//Same idea with mine which is more concise
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 7)) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};