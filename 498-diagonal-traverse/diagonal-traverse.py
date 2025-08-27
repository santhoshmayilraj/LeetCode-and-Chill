class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        prev = []
        if len(mat) == 0:
            return prev
        prev.append([0,0])
        ans = []
        ans.append(mat[0][0])
        mat[0][0] = -1e7

        flag = True

        while len(prev) != 0:
            temp = []
            prev = prev[::-1]
            if flag:
                for i in prev:
                    curr_x = i[0]
                    curr_y = i[1]
                    
                    if curr_y+1 < len(mat[0]) and mat[curr_x][curr_y+1] >= -1e5:
                        temp.append([curr_x,curr_y+1])
                        ans.append(mat[curr_x][curr_y+1])
                        mat[curr_x][curr_y+1] = -1e7
                    
                    if curr_x+1 < len(mat) and mat[curr_x+1][curr_y] >= -1e5:
                        temp.append([curr_x+1,curr_y])
                        ans.append(mat[curr_x+1][curr_y])
                        mat[curr_x+1][curr_y] = -1e7

                prev = temp
                flag = False
            else:
                for i in prev:
                    curr_x = i[0]
                    curr_y = i[1]

                    if curr_x+1 < len(mat) and mat[curr_x+1][curr_y] >= -1e5:
                        temp.append([curr_x+1,curr_y])
                        ans.append(mat[curr_x+1][curr_y])
                        mat[curr_x+1][curr_y] = -1e7
                    
                    if curr_y+1 < len(mat[0]) and mat[curr_x][curr_y+1] >= -1e5:
                        temp.append([curr_x,curr_y+1])
                        ans.append(mat[curr_x][curr_y+1])
                        mat[curr_x][curr_y+1] = -1e7

                prev = temp
                flag = True
                
        return ans

