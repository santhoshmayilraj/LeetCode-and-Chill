from collections import defaultdict

class Solution(object):
    def repeatedNTimes(self, nums):
        temp = defaultdict(int)
        for i in nums:
            if temp[i] != 0:
                return i
            temp[i] = 1
