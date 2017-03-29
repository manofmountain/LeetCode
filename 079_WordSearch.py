#94.4%
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def correctPosition(pos, index):
            if index == size:
                return True
            
            #To left
            if pos[1] > 0 and 0 == traces[pos[0]][pos[1] - 1] and board[pos[0]][pos[1] - 1] == word[index]:
                traces[pos[0]][pos[1] - 1] = 1
                if correctPosition((pos[0], pos[1] - 1), index + 1):
                    return True
                traces[pos[0]][pos[1] - 1] = 0
            #To right
            if pos[1] < cols - 1 and 0 == traces[pos[0]][pos[1] + 1] and board[pos[0]][pos[1] + 1] == word[index]:
                traces[pos[0]][pos[1] + 1] = 1
                if correctPosition((pos[0], pos[1] + 1), index + 1):
                    return True
                traces[pos[0]][pos[1] + 1] = 0
            #To up
            if pos[0] > 0 and 0 == traces[pos[0] - 1][pos[1]] and board[pos[0] - 1][pos[1]] == word[index]:
                traces[pos[0] - 1][pos[1]] = 1
                if correctPosition((pos[0] - 1, pos[1]), index + 1):
                    return True
                traces[pos[0] - 1][pos[1]] = 0
            #To down
            if pos[0] < rows - 1 and 0 == traces[pos[0] + 1][pos[1]] and board[pos[0] + 1][pos[1]] == word[index]:
                traces[pos[0] + 1][pos[1]] = 1
                if correctPosition((pos[0] + 1, pos[1]), index + 1):
                    return True
                traces[pos[0] + 1][pos[1]] = 0
            return False
        size = len(word)
        if 0 == size:
            return False
        rows = len(board)
        if 0 == rows:
            return False
        cols = len(board[0])
        if 0 == cols:
            return False
        
        traces = [[0] * cols for _ in xrange(rows)]
        for i in xrange(rows):
            for j in xrange(cols):
                if board[i][j] == word[0]:
                    traces[i][j] = 1
                    if correctPosition((i, j), 1):
                        return True
                    traces[i][j] = 0
        return False