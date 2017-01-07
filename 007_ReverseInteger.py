
#0.53%
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        #Check boundary conditions
        intMax = 0x7fffffff
        intMin = 0x80000000
        if -10 < x and x < 10:
            return x
        if x == intMin:
            return 0
            
        #Main routine
        flag = True
        if x < 0:
            flag = False
            x = -x
        rstVal = 0
        while x != 0:
            unitVal = x % 10
            rstVal = rstVal * 10 + unitVal
            x = x / 10
        
        #Check Integer overflow
        if rstVal > intMax:
            return 0
        if not flag:
            rstVal = -rstVal
            
        return rstVal
            