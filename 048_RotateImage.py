class Solution:
    def rotate(self, A):
        A[:] = zip(*A[::-1])
		
class Solution:
    def rotate(self, A):
        A[:] = map(list, zip(*A[::-1]))
		
class Solution:
    def rotate(self, A):
        A[:] = [[row[i] for row in A[::-1]] for i in range(len(A))]