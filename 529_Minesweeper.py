def updateBoard(self, A, click):
    click = tuple(click)
    R, C = len(A), len(A[0])
    
    def neighbors(r, c):
        for dr in xrange(-1, 2):
            for dc in xrange(-1, 2):
                if (dr or dc) and 0 <= r + dr < R and 0 <= c + dc < C:
                    yield r + dr, c + dc
    
    stack = [click]
    seen = {click}
    while stack:
        r, c = stack.pop()
        if A[r][c] == 'M':
            A[r][c] = 'X'
        else:
            mines_adj = sum( A[nr][nc] in 'MX' for nr, nc in neighbors(r, c) )
            if mines_adj:
                A[r][c] = str(mines_adj)
            else:
                A[r][c] = 'B'
                for nei in neighbors(r, c):
                    if A[nei[0]][nei[1]] in 'ME' and nei not in seen:
                        stack.append(nei)
                        seen.add(nei)
    return A
	
def updateBoard(self, board, click):
    (row, col), directions = click, ((-1, 0), (1, 0), (0, 1), (0, -1), (-1, 1), (-1, -1), (1, 1), (1, -1))
    if 0 <= row < len(board) and 0 <= col < len(board[0]):
        if board[row][col] == 'M':
            board[row][col] = 'X'
        elif board[row][col] == 'E':
            n = sum([board[row + r][col + c] == 'M' for r, c in directions if 0 <= row + r < len(board) and 0 <= col + c < len(board[0])])
            board[row][col] = str(n or 'B')
			#not n and map(self.updateBoard, (board,) * 8, [(row + d[0], col + d[1]) for d in directions])
            for r, c in directions * (not n): self.updateBoard(board, [row + r, col + c])
    return board