
# A solution from LeetCode
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        oribin='{0:032b}'.format(n)
        reversebin=oribin[::-1]
        return int(reversebin,2)
		
def reverseBits(self, n):
    return int(bin(n)[2:].zfill(32)[::-1], 2)
		