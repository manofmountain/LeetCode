
#This one is really hard to understand
def spiralOrder(self, matrix):
    return matrix and list(matrix.pop(0)) + self.spiralOrder(zip(*matrix)[::-1])
	

# This one has much more readibility	
def spiralOrder(self, matrix):
    ret = []
    while matrix:
        ret += matrix.pop(0)
        if matrix and matrix[0]:
            for row in matrix:
                ret.append(row.pop())
        if matrix:
            ret += matrix.pop()[::-1]
        if matrix and matrix[0]:
            for row in matrix[::-1]:
                ret.append(row.pop(0))
    return ret