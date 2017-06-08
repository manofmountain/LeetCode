## A really fantastic thinking though it's inefficient
def findDiagonalOrder(self, matrix):
    entries = [(i+j, (j, i)[(i^j)&1], val)
               for i, row in enumerate(matrix)
               for j, val in enumerate(row)]
    return [e[2] for e in sorted(entries)]

	
def findDiagonalOrder(self, matrix):
    m, n = len(matrix), len(matrix and matrix[0])
    return [matrix[i][d-i]
            for d in range(m+n-1)
            for i in range(max(0, d-n+1), min(d+1, m))[::d%2*2-1]]