class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        k = self.Kadane(nums)
        
        CS = 0
        for i in range(len(nums)):
            CS += nums[i]
            nums[i] = -nums[i]
        CS = CS+ self.Kadane(nums)
        
        if CS > k and CS != 0:
            return CS
        else:
            return k
        
    def Kadane(self, A):
        cursum, maxsum = A[0], A[0]
        for n in A[1:]:
            cursum = max(n, cursum + n)
            maxsum = max(cursum, maxsum)
        return maxsum
        