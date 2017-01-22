//11.30%
class Solution {
public:
    bool isHappy(int n) {
        while(n != 1){
			if(table.find(n) == table.end()){
				table[n] = 1;
				int m = 0;
				while(n){
					int temp = n % 10;
					m += (temp * temp);
					n /= 10;
				}
				n = m;
			}else
				return false;
		}
		return true;			
    }
private:
	map<int, int> table; //or unordered_map
};

//11.30%
class Solution {
public:
    bool isHappy(int n) {
        while(n != 1){
			if(table.find(n) == table.end()){
				table.insert(1);
				int m = 0;
				while(n){
					int temp = n % 10;
					m += (temp * temp);
					n /= 10;
				}
				n = m;
			}else
				return false;
		}
		return true;			
    }
private:
	set<int> table; //unordered_set
};