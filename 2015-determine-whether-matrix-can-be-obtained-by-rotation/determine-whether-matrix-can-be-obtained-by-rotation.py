class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        flg1,flg2,flg3,flg4 = True,True,True,True

        n,m = len(mat),len(mat[0])

        for i in range(n):
            for j in range(m):
                if flg1:
                    if mat[i][j] != target[i][j]:
                        flg1 = False
                if flg2:
                    if mat[n-1-j][i] != target[i][j]:
                        flg2 = False
                if flg3:
                    if mat[n-1-i][m-1-j] != target[i][j]:
                        flg3 = False
                if flg4:
                    if mat[j][m-1-i] != target[i][j]:
                        flg4 = False

        return flg1 or flg2 or flg3 or flg4