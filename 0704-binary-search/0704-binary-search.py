class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        s =0
        e = len(nums)-1

        while s<= e:
            m = s + (e - s)//2

            if nums[m] > target:
                e = m - 1
            elif nums[m] < target:
                s = m + 1
            else:
                return m
        return -1