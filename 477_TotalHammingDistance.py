def totalHammingDistance(self, nums):
    return sum(b.count('0') * b.count('1') for b in zip(*map('{:032b}'.format, nums)))
	

#Another solution	
bits = [ [0,0] for _ in xrange(32) ]
for x in A:
  for i in xrange(32):
    bits[i][x%2] += 1
    x /= 2
return sum( x*y for x,y in bits )