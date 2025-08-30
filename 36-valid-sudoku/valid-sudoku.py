from collections import defaultdict
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for box_x in (0, 3, 6):
            for box_y in (0, 3, 6):
                hash_box = defaultdict(int)
                for i in range(3):
                    for j in range(3):
                        val = board[box_x + i][box_y + j]
                        if val != '.':
                            if hash_box[val]:
                                return False
                            hash_box[val] = 1

        for i in range(9):
            hash_row = defaultdict(int)
            hash_col = defaultdict(int)
            for j in range(9):
                # Row
                if board[i][j] != '.':
                    if hash_row[board[i][j]]:
                        return False
                    hash_row[board[i][j]] = 1
                # Column
                if board[j][i] != '.':
                    if hash_col[board[j][i]]:
                        return False
                    hash_col[board[j][i]] = 1

        return True
