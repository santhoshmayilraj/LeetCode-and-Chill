class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev = 0
        ans = 0
        for i in range(len(bank)):
            curr = 0
            for j in bank[i]:
                if j == '1':
                    curr += 1

            ans += curr*prev
            if curr != 0:
                prev = curr
            
        return ans