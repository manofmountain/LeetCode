#54.51%
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        sum = int(a, 2) + int(b, 2)
        digitList  = []
        if sum == 0:
            return a
        while sum > 0:
            digitList = [sum % 2] + digitList
            sum = sum / 2
        return ''.join([str(item) for item in digitList])
		

#add two binary from back to front, I think it is very self explained, when 1+1 we need a carry.
   class Solution:
        def addBinary(self, a, b):
            if len(a)==0: return b
            if len(b)==0: return a
            if a[-1] == '1' and b[-1] == '1':
                return self.addBinary(self.addBinary(a[0:-1],b[0:-1]),'1')+'0'
            if a[-1] == '0' and b[-1] == '0':
                return self.addBinary(a[0:-1],b[0:-1])+'0'
            else:
                return self.addBinary(a[0:-1],b[0:-1])+'1'

#Wonderful simple solution which is what i want at first
class Solution:
    def addBinary(self, a, b):
        return bin(eval('0b' + a) + eval('0b' + b))[2:]	

#This is an improvement on my own version
class Solution:
# @param a, a string
# @param b, a string
# @return a string
def addBinary(self, a, b):
    aa,bb=int(a,2),int(b,2)  # convert the binary string to int 
    c=aa+bb
    res=bin(c)[2:]     #convert int to binary string, Eg : bin(5)->'0b101'
    return res		