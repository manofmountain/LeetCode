#29.19%
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digitLen = len(digits)
        i = digitLen - 1
        
        while i >= 0:
            if digits[i] + 1 < 10:
                digits[i] = digits[i] + 1
                return digits
            else:
                digits[i] = 0
				i = i - 1
        
        digits = [1] + digits
        
        return digits
            
 
#Another solution from LeetCode
def plusOne(digits):
    num = 0
    for i in range(len(digits)):
    	num += digits[i] * pow(10, (len(digits)-1-i))
    return [int(i) for i in str(num+1)]

#Fabulous solution from LeetCode
def plusOne(self, digits): return [int(x) for x in str(int(''.join([str(x) for x in digits])) + 1)]	