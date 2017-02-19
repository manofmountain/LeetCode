//5.75%
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        assert(num <= 10 && num >= 0);
		vector<string> res;
		int hourMaxNum = min(num, maxHourNum);
		int minuteMaxNum = min(num, maxMinuteNum);
		for(int i = 0; i <= hourMaxNum; i++){
			if((num - i) <= minuteMaxNum)
				appendPossibleTime(res, i, num - i);
		}
		return res;
    }
private:
	const int maxHourNum = 4;
	const int maxMinuteNum = 6;
	//int hourMaxNum(4);
	//int minuteMaxNum(6);
	
	void appendPossibleTime(vector<string> &timeSet, int hourNum, int minuteNum){
		vector<string> hourStrings, minuteStrings;
		getPossibleTimeStrings(hourStrings, hourNum, maxHourNum);
		getPossibleTimeStrings(minuteStrings, minuteNum, maxMinuteNum);
		for(auto hStr : hourStrings){
			for(auto mStr : minuteStrings){
				string s = hStr + ":";
				s += mStr;
				timeSet.push_back(s);
			}
		}
	}
	
	void getPossibleTimeStrings(vector<string> &timeStrings, int timeNum, int ledNum){
		vector<int> timeInts(getPossibletimeInts(timeNum, ledNum));
		for(auto i : timeInts){
			if(ledNum == maxHourNum && i > 11)
				continue;
			if(ledNum == maxMinuteNum && i > 59)
				continue;
			if(ledNum == maxMinuteNum && i < 10)
				timeStrings.push_back("0" + to_string(i));
			else
				timeStrings.push_back(to_string(i));
		}
	}
	
	vector<int> getPossibletimeInts(int timeNum, int ledNumLeft){
		vector<int> timeInts;
		if(timeNum == ledNumLeft){
			timeInts.push_back((1 << timeNum) - 1);
			return timeInts;
		}
		if(timeNum == 0){
			timeInts.push_back(0);
			return timeInts;
		}
		vector<int> timeIntsRemain = getPossibletimeInts(timeNum - 1, ledNumLeft - 1);
		for(auto num : timeIntsRemain){
			timeInts.push_back((num << 1) + 1);
		}
		vector<int> timeIntsRemain2 = getPossibletimeInts(timeNum, ledNumLeft - 1);
		for(auto num : timeIntsRemain2){
			timeInts.push_back(num << 1);
		}
		return timeInts;
	}
};


//Such a elegant solution from LeetCode
vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}