class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        
        def backTrack(start, cur):
            if len(cur) > 1:
                ans.add(tuple(cur))
                
            last = cur[-1] if cur else -200
            
            for i in range(start, n):
                if nums[i] >= last:
                    cur.append(nums[i])
                    backTrack(i+1, cur)
                    cur.pop()
                    
        n = len(nums)
        backTrack(0, [])
        
        return ans
        