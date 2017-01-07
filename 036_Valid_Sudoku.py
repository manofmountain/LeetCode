# A method from LeetCode
def isValidSudoku(self, board):
    return 1 == max(collections.Counter(
        x
        for i, row in enumerate(board)
        for j, c in enumerate(row)
        if c != '.'
        for x in ((c, i), (j, c), (i/3, j/3, c))
    ).values() + [1])

#Another method from LeetCode	
def isValidSudoku(self, board):
    seen = sum(([(c, i), (j, c), (i/3, j/3, c)]
                for i, row in enumerate(board)
                for j, c in enumerate(row)
                if c != '.'), [])
    return len(seen) == len(set(seen))

def isValidSudoku(self, board):
    seen = sum(([(c, i), (j, c), (i/3, j/3, c)]
                for i in range(9) for j in range(9)
                for c in [board[i][j]] if c != '.'), [])
    return len(seen) == len(set(seen))
	
def isValidSudoku(self, board):
    seen = set()
    return not any(x in seen or seen.add(x)
                   for i, row in enumerate(board)
                   for j, c in enumerate(row)
                   if c != '.'
                   for x in ((c, i), (j, c), (i/3, j/3, c)))
				   
#91.24%
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rowSize = 9
        colSize = 9
        squareSize = 9
        squareRowSize = 3
        squareColSize = 3
		#Can not use [[]] * 9 here
        flagRows = [[], [], [], [], [], [], [], [], []]
        flagCols = [[], [], [], [], [], [], [], [], []]
        flagSquares = [[], [], [], [], [], [], [], [], []]
        
        for i in range(rowSize):
            for j in range(colSize):
                val = board[i][j]
                if val != '.':
                    #val = board[i][j]
                    k = i / squareRowSize * squareColSize + j / squareColSize
                    if val in flagRows[i] or val in flagCols[j] or val in flagSquares[k]:
                        return False
                    else:
                        flagRows[i].append(val)
                        flagCols[j].append(val)
                        flagSquares[k].append(val)
        
        return True