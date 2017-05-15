##64.76%
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if not board or not board[0]:
            return 0
        
        cnt = 0
        for row in xrange(len(board)):
            for col in xrange(len(board[0])):
                if board[row][col] == 'X':
                    if (row == 0 or board[row - 1][col] == '.') and (col == 0 or board[row][col - 1] == '.'):
                        cnt += 1
        return cnt