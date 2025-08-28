class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        for i in range(0,len(grid)):
            curr_x = i
            curr_y = 0
            arr = []
            while curr_x < len(grid) and curr_y < len(grid[0]):
                arr.append(grid[curr_x][curr_y])
                curr_x += 1
                curr_y += 1
            
            curr_x = i
            curr_y = 0
            arr.sort()
            arr = arr[::-1]
            temp = 0

            while curr_x < len(grid) and curr_y < len(grid[0]):
                grid[curr_x][curr_y] = arr[temp]
                temp += 1
                curr_x += 1
                curr_y += 1

        for i in range(1,len(grid[0])):
            curr_x = 0
            curr_y = i
            arr = []

            while curr_x < len(grid) and curr_y < len(grid[0]):
                arr.append(grid[curr_x][curr_y])
                curr_x += 1
                curr_y += 1
            
            curr_x = 0
            curr_y = i
            arr.sort()
            temp = 0

            while curr_x < len(grid) and curr_y < len(grid[0]):
                grid[curr_x][curr_y] = arr[temp]
                temp += 1
                curr_x += 1
                curr_y += 1


        return grid
            